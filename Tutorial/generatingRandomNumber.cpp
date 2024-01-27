#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    long elapsTime = time(nullptr); // jan 1 1970
    srand(elapsTime);
    int number = rand() % 10;

    cout << number << endl;
    cout << elapsTime << endl;

    return 0;
}
