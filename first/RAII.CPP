#include <iostream>
#include <cstdio>
#include <memory>

class FileHandle{
private:
        FILE* file;
public:
        FileHandle(const char* filename,const char* file_model = "r"){
               file = fopen(filename,file_model);
               if(!file){
                throw std::runtime_error("Failed to open file");
               } 
                std::cout << "File opened: " << filename << std::endl;               
        }

        ~FileHandle(){
             fclose(file);
             std::cout<<"File closed."<<std::endl;
        }
        FileHandle(const FileHandle&) = delete;
        FileHandle& operator=(const FileHandle&) = delete;

        // 移动构造
        FileHandle(FileHandle&& other) noexcept : file(other.file) {
            other.file = nullptr;
        }

        // 移动赋值
        FileHandle& operator=(FileHandle&& other) noexcept {
            if (this != &other) {
                if (file) fclose(file);
                file = other.file;
                other.file = nullptr;
            }
            return *this;
        }

    };

class SmartFileHandle{
    private:
        std::unique_ptr<FILE,decltype(&fclose)>file;
    public :
        SmartFileHandle(const char* filename, const char* file_model)  
        : file(fopen(filename,file_model),fclose){
            if(!file){
                throw std::runtime_error("failed to open file");
            }
            std::cout<<"file opened:"<<filename<<std::endl;
        }
    };


int main() {
    try {
        FileHandle fh("test.txt", "w");
        // FileHandle fh2 = fh;  // 编译错误：拷贝构造已删除
        FileHandle fh3 = std::move(fh);  // 移动构造

        // fh3 在作用域结束时自动关闭文件
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // 测试智能指针版本
    try {
        SmartFileHandle sfh("test.txt", "w");
        // 自动移动，无需手动实现
    } catch (...) {}
    return 0;
}

