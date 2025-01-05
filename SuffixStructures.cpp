#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort
#include <utility>    // For std::pair
#include <math.h>

using namespace std;
bool automaton(string a, string b)
{
    int n = 0;
    for (int i = 0; i < a.length() and n < b.length(); i++) 
        n += a[i] == b[n];
    return n == b.length();
}

int main()
{
    string s1;
    string s2;

    bool isexit = false;

    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0; i < s2.length(); i++)
    {
        for (int j = 0; j < s1.length(); j++)
        {
            if(s2[i] == s1[j])
                isexit = true;
        }
        if(!isexit)
        {
            cout << "need tree" << endl;
            return 0;
        }
    }
    if (s1 != s2 && s1.length() == s2.length())
        cout << "array" << endl;
    else if (automaton(s1, s2)) cout << "automaton" << endl;
    else
        cout << "both" << endl;
    return 0;
}