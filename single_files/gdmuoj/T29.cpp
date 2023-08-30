#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double delta = b * b - 4 * a * c;
    if (delta > 0)
    {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        printf("x1=%.3f x2=%.3f", max(x1, x2), min(x1, x2));
    }
    else if (delta == 0)
    {
        double x = -b / (2 * a);
        printf("x1=x2=%.3f", x);
    }
    else
    {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-delta) / (2 * a);
        printf("x1=%.3f+%.3fi x2=%.3f-%.3fi", realPart, imaginaryPart, realPart, imaginaryPart);
    }
    return 0;
}