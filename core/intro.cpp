#include <iostream>
#include <ostream>
#include <string>
int main()
{
    // const char* arr = "qweas";
    // std::cout << arr[1];

    // auto e = char('A'+ 2);
    // std::cout << e ;
    

    int *ptr = new int(2);
    char *ptr1 = new char('s');
    std::cout << sizeof(ptr) <<"-" << sizeof(int) << "-" << sizeof(ptr1) << std::endl;
    delete ptr;
    delete ptr1;
}