#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<int> heapify(vector<int> a, int i)
{
    size_t l = 2 * i;
    size_t r = 2 * i + 1;
    int smallest;
    if (l <= a.size() - 1 && a[l] <= a[i])
    {
        smallest = l;
    }
    else
    {
        smallest = i;
    }

    if (r <= a.size() - 1 && a[r] < a[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        int temp_i = a[i];
        a[i] = a[smallest];
        a[smallest] = temp_i;

        a = heapify(a, smallest);
    }
    return a;
}

int main()
{
    vector<int> a;
    string Q;
    getline(cin, Q);

    for (int i = 0; i < stoi(Q); i++)
    {
        string n_temp;
        getline(cin, n_temp);
        vector<string> arr_temp = split(rtrim(n_temp));

        if (arr_temp[0] == "1")
        {
            a.insert(a.begin(), stoi(arr_temp[1]));
            a = heapify(a, 0);
        }
        else if (arr_temp[0] == "2")
        {
            for (size_t i = 0; i < a.size(); i++)
            {
                if (a[i] == stoi(arr_temp[1]))
                {
                    // cout << i << endl;
                    a.erase(a.begin() + i);

                    break;
                }
            }
            // if (a.size() > 0)
            // {
            //     a = heapify(a, 0);
            // }
        }
        else if (arr_temp[0] == "3")
        {
            a = heapify(a, 0);
            cout << a[0] << endl;
        }
    }

    // for (int item : a)
    // {
    //     cout << item << endl;
    // }

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
