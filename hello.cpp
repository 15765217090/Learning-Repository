#include <iostream>
#include <string>
#include <cstdint>
using namespace std;

struct ProblematicBitField {
    bool flag1 : 1;    
    bool flag2 : 1;
};

struct GoodBitField {
    unsigned int f1 : 2;  // 明确使用无符号类型
    unsigned int f2 : 2;
    unsigned int f3 : 1;
    unsigned int fs : 1;  // 多个标志位组合
}c;



int main() {

    // c.f1 = 2;
    // uint8_t a=1u;
    // int b=1;
    // // printf("%d\n",a);
    // std::cout << "a:% "<<a<< std::endl;  // 通常是 1
    // std::cout << "Size of a: " << sizeof(a) << std::endl;  // 通常是 3
    // std::cout << "Size of ProblematicBitField: " << sizeof(ProblematicBitField) << std::endl;  // 通常是 3
    // std::cout << "Size of GoodBitField: " << sizeof(GoodBitField) <<std::endl;    // 可能是 12
    // std::cout << "Size of a: " << sizeof(c) <<std::endl;    // 可能是 12
    // std::cout << "c的值为: " << c.f1 <<std::endl;   
    char a[20];
    int *ptr = (int*)a;
    ptr++;
    std::cout <<"ptr的地址:"<<ptr<<std::endl;
    cout<<sizeof(a)<<endl;
    int i=0;
    return 0;
}