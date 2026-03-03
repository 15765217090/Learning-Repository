#include <iostream>
#include <string>
#include <cstring>

using namespace std;

namespace PrintUtil{
    void print(int value){
        std::cout<<"[PrintUtil::print(int)}"<<endl;
    }
    void print(double value){
        std::cout<<"[PrintUtil::print(double)}"<<endl;        
    }
    void print(const char* str){
        std::cout<<"[PrintUtil::print(string)}"<<endl;        
    }
}

namespace Mystr{
class Refactor_Str{
    private:
        char* data;
        size_t length;
    public:
        Refactor_Str(){                             //默认构造函数
            data = new char[1];
            data[0] = '\0';
            length = 0;
            cout<<"The default constructor is called"<<endl;
        }
        Refactor_Str(const char* str){              //带参构造函数
            if(str == nullptr){
                data = new char[1];
                data[0] = '\0';
                length = 0;
            }
            else{
                length = strlen(str);
                data = new char[length + 1];
                strcpy(data, str);
            }
        } 
        Refactor_Str(const Refactor_Str& other){        //深拷贝
            length = other.length;
            data = new char[length +1];
            strcpy(data, other.data);
        }  
        Refactor_Str& operator = (const Refactor_Str& other){
            if(this == &other){
                return *this;
            }
            delete[] data;
            data = new char[other.length + 1];
            strcpy(data, other.data);
            length = other.length;
            return *this;
        }
        ~Refactor_Str(){                            //析构函数
            delete[] data;
        }  
        
        void print() const{
            cout<<"[Mystr::Refactor_Str] "<<data<<endl;
        }
};
}

int main(){

    Mystr::Refactor_Str str1("hello");
    Mystr::Refactor_Str str2 = str1;  //调用拷贝构造函数
    Mystr::Refactor_Str str3;         //调用默认构造函数
    str3 = str1;                      //调用赋值运算符重载
    str1.print();
    str2.print();
    str3.print();
}
