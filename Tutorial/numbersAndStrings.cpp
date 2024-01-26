#include <iostream>

using namespace std;

int main()
{
    string grade = "Nidula Gunawardana";
    cout << grade << endl; // normal variable printing
    cout<< grade.length()<<endl; // normal length of a string
    cout<<grade[0]<<endl; // individual character accessing.
    grade[1] = 'a';
    cout<<grade;

    return 0;
}