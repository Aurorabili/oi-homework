#include <iostream>
#include <vector>
#include <algorithm>

// 写一函数，使输入的一个字符串（包含数字，字母，空格，特殊符号）按反序存放，在主函数中输入输出反序后的字符串
void reverse(char *str)
{
    char *end = str;
    char tmp;
    if (str)
    {
        while (*end)
        {
            ++end;
        }
        --end;
        while (str < end)
        {
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
}

int main()
{
    using namespace std;
    char str[100];
    cin.getline(str, 100);
    reverse(str);
    cout << str << endl;
    return 0;
}
