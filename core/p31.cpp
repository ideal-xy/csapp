#include <cinttypes>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstddef>
#include <iomanip>
#include <bitset>
#include <xlocale/_stdio.h>

/*
解释一下这段代码：
    1.第一行相当于创建了一个指针，后续读取数据的时候，每次只读取一个字节的
    2.因为任何指针变量存储的都是其指向的存储快的第一个字节的虚拟地址，而我们知道，int类型是四个字节大小
    3.这段代码在工作的时候，首先找到变量i的首个字节的内存地址，然后一次读取一个字节，就可以分四次打印，打印存储在那个字节上的值
    4.假设一个int变量位于0x100处，它的16进制值为0x0123456，那么0x100，这里存储的就是0x67，二进制就是一个八位数，然后以此类推
    5.这里展示的小端法，有的机器存储方式是大端法，会把0x67存储在地址0x103处
    6.直接打印start[i]很可能出现乱码是因为:我们打印的是unsigned char（0-255），cout默认将其视为 ​ASCII字符​，而不是数值，而可打印的字符只有可打印字符：32-126（空格到~）
    7.我们还注意到：虽然浮点型和整形数据都是对12345编码，但是他们有截然不同的字节模式
    8.展示指针那一部分，我们写了俩函数，一个是把 x转化为unsigned char*,还有一个是把&x转化为unsigned char*,这是不一样的
    9.地址本身就是一种抽象，任意一个指针在64位的计算机上都是8个字节的大小，比如对于一个指向int型变量的指针，变量本身只有四个字节，但是指向他的指针却又八个字节
           这两个数据其实没有啥关系，因为地址和虚拟内存就没有啥关系，地址只是为我们防卫虚拟内存上的变量提供了标签.
    10.所以说，在第八条中，两种方式打印结果是不一样的，但是！！使用x这种方式是危险的，因为会额外访问四个自己的内存
*/

using byte_pointer = unsigned char*;
 
void show_bytes(byte_pointer start,size_t len)
{
    std::cout << "16 进制存储为" << std::endl;
    for (size_t i = 0; i < len; ++i)
    {
        std::cout << std::hex << std::setw(2) << std::setfill('0') 
                  << static_cast<int>(start[i]) << " ";
    }
    std::cout << "\n";
    std::cout << "2 进制存储为" << std::endl;
    for (size_t i = 0; i < len; ++i)
    {
        std::cout << std::setw(8) << std::setfill('0') 
                  << std::bitset<8>(start[i]) << " ";
    }
    std::cout << "\n";
}

void show_int(int x)
{
    std::cout << "***int"<< "在计算机中的存储："  << std::endl;
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_str(const char* str)
{
    std::cout << "***字符串" << "在计算机中的存储为" << std::endl;
    show_bytes((byte_pointer) str, std::strlen(str));
}

void show_float(float x)
{
    std::cout << "***float" << "在计算机中的存储" << std::endl;
    show_bytes((byte_pointer) &x, sizeof(float));
}

void var_show_pointer(void *x)
{
    std::cout << "***指针" << x << "在计算机中的存储："  << std::endl;
    show_bytes((byte_pointer) x,sizeof(void*));
}

void show_pointer(void *x)
{
    std::cout << "***指针" << x << "在计算机中的存储："  << std::endl;
    show_bytes((byte_pointer) x,sizeof(void*));
}

int main()
{
    int i = 12345;
    float x = 12345.0;
    int* ptr = &i;
    const char* str = "12345";

    show_int(i);
    show_float(x);
    show_pointer(ptr);
    show_str(str);

   
}

