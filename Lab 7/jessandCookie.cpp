#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <queue>

using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n, k, operations = 0;
    ;
    cin >> n;
    cin >> k;

    priority_queue<int> p;

    for (int a = 0; a < n; a++)
    {
        int cookie;
        cin >> cookie;
        p.push(cookie * -1);
    }

    while (p.top() > k * -1 && p.size() > 1)
    {
        int cookie1, cookie2, newCookie;

        cookie1 = p.top();
        p.pop();

        cookie2 = p.top();
        p.pop();

        newCookie = cookie1 + 2 * cookie2;
        p.push(newCookie);

        operations++;
    }

    if (p.top() > k * -1)
        cout << "-1";
    else
        cout << operations;

    return 0;
}
