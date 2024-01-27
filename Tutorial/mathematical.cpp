#include <iostream>

using namespace std;

int main()
{
    int x = 10;
    int y = 3;
    // we can do the increment in post fix or pre fix --x or x==
    y = x++; // this will first assign the x value to y and incremnt x by one: y = 10 , x = 11
    y = ++x; // this will incremnt x first and the add to y

    x--; // decrement
    int z = x + y;

    x++; // increment

    double w = x / y;

    cout << z << endl;
    cout << w;
    return 0;
}
