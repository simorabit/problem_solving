#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
#include <map>

class Solution
{
private:
    std::map<int, std::string> romans = {
        {1, "I"},
        {5, "V"},
        {10, "X"},
        {50, "L"},
        {100, "C"},
        {500, "D"},
        {1000, "M"},
    };
    std::string result = "";
    int getDivisor(int num)
    {
        int magnitude = std::to_string(num).size();
        int divisor = std::pow(10, magnitude - 1);
        return divisor;
    }
    vector<int> getNums(int num)
    {
        std::vector<int> components;
        int divisor = getDivisor(num);
        int i = 0;
        while (divisor > 0)
        {
            int digitValue = (num / divisor) * divisor; // Extract the component
            if(digitValue != 0)
                components.push_back(digitValue);
            num %= divisor; // Remove the extracted part
            divisor /= 10;  // Move to the next place value
        }
        return components;
    }
    int getFirstNum(int const &num)
    {
        std::string res = std::to_string(num);
        return (res[0] - '0');
    }
    void getRomans(int num)
    {
        while (true)
        {
            int fnum = getFirstNum(num);
            if(fnum == 5 || fnum == 1)
            {
                auto it = romans.find(num); // 50
                result += it->second;
                break;
            }
            if(fnum < 5)
                fnum = 1;
            else if(fnum > 5)
                fnum = 5;
            int n = num - (getDivisor(num) * fnum);
            auto it = romans.find((getDivisor(num) * fnum)); // 50
            result += it->second;
            if(getFirstNum(n) == 5 || getFirstNum(n) == 1)
            {
                auto it = romans.find(n); // 50
                result += it->second;
                break;
            }
            else
                num = n;
        }
    }

public:
    string intToRoman(int num)
    {
        vector<int> data = getNums(num);
        for (int n : data)
        {
            int fNum = getFirstNum(n);
            if (fNum == 4 || fNum == 9)
            {
                auto it = romans.find(getDivisor(n));
                auto it2 = romans.find(it->first + n);
                result += (it->second + it2->second);
            }
            else
                 getRomans(n);
        }
        return result;
    }
};

int main()
{
    Solution sol;

    std::cout << sol.intToRoman(10) << std::endl;
}