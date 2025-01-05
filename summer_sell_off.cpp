#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort
#include <utility>    // For std::pair

using namespace std;

// Custom comparator for sorting by the second element of the pair
bool compareBySecond(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
    return a.second > b.second;  // Change to a.second < b.second if you want ascending order
}

int main() {
    long long n, f;
    cin >> n >> f;
    long long  i = 0;
    vector<pair<pair<long long , long long >, long long > > array(n);  // Use vector instead of raw array
    long long  sum = 0;

    for (i = 0; i < n; ++i) {
        long long  a, b, c, d, k;
        cin >> a >> b;

        if (a > b) {
            c = b;
            sum += b;
        } else {
            c = a;
            sum += a;
        }
        array[i].first.first = a;
        array[i].first.second = b;
        d = (a * 2);
        if (d > b) {
            k = b;
        } else {
            k = d;
        }
        array[i].second = k - c;
    }
    sort(array.begin(), array.end(), compareBySecond);
    i = 0;
    while (i < f)
    {
        sum += array[i].second;
        i++;
    }
    cout << sum;
    return 0;
}
