#include <iostream>
#include <map>

int main()
{
    int n;
    int i = 0;
    std::cin >> n;
    int sum = 0;
    int x, y;
    std::map<int, int> diff;
    
    std::map<int, int> summ;
    i = 0;
    while (i < n)
    {
        std::cin >> x >> y;
        int dif = x - y;
        int msum = x + y;
        sum += diff[dif];
        sum += summ[msum];
        diff[dif]++;
        summ[msum]++;
        i++;
    }

    std::cout << sum;
}