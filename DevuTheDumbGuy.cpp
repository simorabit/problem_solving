#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long learningHours;
    long long numOfSubjects;
    cin >> numOfSubjects >> learningHours;
    vector<long long> chapters(numOfSubjects);
    long long i = 0;
    long long sum = 0;
    while (i < numOfSubjects)
    {
        cin >> chapters[i];
        i++;
    }
    sort(chapters.begin(), chapters.end());
    i = 0;
    while (i < numOfSubjects)
    {
        sum += chapters[i] * learningHours;
        if(learningHours != 1)
            learningHours--;
        i++;
    }
    cout << sum << endl;
}
