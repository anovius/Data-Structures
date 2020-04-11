#include <iostream>
#include "polynomial.h"
using namespace std;
int main()
{
    polynomial a,b;
    cin >> a;
    cin >> b;
    cout << a;
    cout << b;
    polynomial c;
    c = a + b;
    cout << c;
    c = a * b;
    cout << c;
    cout << a.evaluate(5) << endl;
    system("pause");
    return 0;
}
