#include <iostream>
#include <vector>

using namespace std;

int AllWork(vector<pair<int, int> > &v, int n, int d)
{
    int r = 0;
    int l = 0;
    int sum = 0;
    int mx = 0;
    while (r < n)
    {
        if(r > l && v[r].first - v[l].first >= d)
        {
            sum -= v[l].second;
            l++;
        }
        sum += v[r].second;
        mx = max(mx, sum);
        r++;
    }
    return mx;
}
int main()
{
    int n;
    int d;
    int i = 0;
    cin >> n >> d;
    vector<pair<int, int> >v(n);
    while (i < n)
    {
        cin >> v[i].first >> v[i].second;
        i++;
    }
    sort(v.begin(), v.end());
    cout << AllWork(v, n, d);
}