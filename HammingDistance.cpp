#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    string a;
    string b;

    getline(cin, a);
    getline(cin, b);

    int i = 0;
    int k = 0;
    while (i < b.length())
    {
        i = k;
        int j = 0;
        while (j < a.length())
        {
            if (a[j] != b[i])
                sum++;
            i++;
            j++;
        }
        k++;
    }
    std::cout << sum << endl;
}