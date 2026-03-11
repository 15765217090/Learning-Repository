#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
using namespace std;

struct ProblematicBitField {
    bool flag1 : 1;    
    bool flag2 : 1;
};
class MyException : public std::exception {
private:
    string message;
public:
    MyException(const string& msg) : message(msg){}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

void riskyFunction(int value){
    if(value < 0){
        throw MyException("负数错误:不能为负数");  
    }
    cout<<"输入的值是："<< value <<endl;
}
void safeFunction() noexcept {

    cout << "This function is marked as noexcept." <<endl;
}

void mayThrow() {
    throw std::runtime_error("error");
}
union ca{
    int a;
    char b[4];
    float c;
}num;
struct GoodBitField {
    unsigned int f1 : 2;  // 明确使用无符号类型
    unsigned int f2 : 2;
    unsigned int f3 : 1;
    unsigned int fs : 1;  // 多个标志位组合
}c;

 typedef struct 
{   
    union 
    {
        struct 
        {
            uint16_t data1;
            uint16_t data2;
            uint16_t data3;
            uint16_t data4;
        }data;
        uint64_t buf_u64;
    }msg;
}st;


int main() {

    c.f1 = 2;
    // uint8_t a=1u;
    // int b=1;
    vector<int> vec = {1, 2, 3};
    safeFunction();
    std::vector<int> v;
    v.push_back(1);

    void fun() noexcept;
    try {
        riskyFunction(-1);
    } catch (const MyException& e){
        cout << "Caught MyException:" << e.what() <<endl;
    } catch (const std::exception& e){
        cout <<"捕获到标准异常:" << e.what() <<endl;
    }

    st amount;
    amount.msg.buf_u64 = 0x1122334455667788;
    num.b[0] = 'A';
    cout<<"num.b:"<<num.b[0]<<endl;
    num.a = 5;
    cout<<"num.a:"<<num.a<<endl;
    num.c =3.14f;
    cout<<"num.c:"<<num.c<<endl;
    cout<<"data1:"<<hex<<amount.msg.data.data1<<endl;
    return 0;
}