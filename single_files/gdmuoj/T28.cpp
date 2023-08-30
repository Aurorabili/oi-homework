#include <iostream>
#include <algorithm>

using namespace std;

// gcd
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

// lcm
int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << lcm(a, b) << endl;
    return 0;
}