#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int currSum = nums[i] + nums[right] + nums[left];
                if(currSum == target)
                    return target;
                if(abs(currSum - target) < abs(closest - target))
                    closest = currSum;
                if(currSum < target)
                    left++;
                else
                    right--;
            }
            
        }
        return closest;
    }
};
int main()
{
    Solution ss;
    vector<int> vec = {5,7,7,8,9,10};
    ss.threeSumClosest(vec, 8);
}