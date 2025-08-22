#include <iostream>
void implace_swap(int* x,int* y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int arr[],int length)
{
    int first;
    int last;
    for (first = 0,last = length-1;first <= last ;first++,last--)
    {
        implace_swap(&arr[first], &arr[last]);
    }
}

/*
还有一个非常经典的题目，有一个数组，其中有奇数个元素，除了其中一个元素，其他的元素都出现了两次，请你找出找出这个元素
*/

/*
解决方法也是使用位运算，就是把0依次与数组中的元素来进行一次异或运算，最后得到的结果就是只出现一次的那个数
*/


int main()
{
    std::cout << (4<<2) << std::endl;
    std::cout << (4>>2) << std::endl;

    int x = 0xf0000001;
    std::cout << std::hex << (x << 2);
}

