#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort
#include <utility>    // For std::pair
#include <math.h>

using namespace std;

int main()
{
    int a, x, y;

    cin >> a >> x >> y;

    if(y == 0 || abs(x) >= a || (y % a) == 0)
        cout << -1 << endl;
    int levels = (y / a) + 1;
    int ans;
    int oddLevel, evenLevel;

    if (levels == 1)
    {
        if(abs(x) >= ((a + 1) / 2))
            ans = -1;
        else
            ans = 1;
    }
    else if (levels % 2 != 0) // 4 1 16  level = 5
    {
        oddLevel = levels / 2;
        ans = oddLevel * 2 + (oddLevel - 1) + 2;
        if(x < 0)
            ans--;
        if(x == 0)
            ans = -1;
    }
    else // 4
    {
        oddLevel = (levels - 1) / 2;
        ans = oddLevel * 2 + (oddLevel) + 2;
        if(abs(x) >= (a + 1) / 2)
            ans = -1;
    }
    cout << ans << endl;
}