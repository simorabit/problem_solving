#include<vector>
#include<iostream>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int right = nums.size() - 1;
        int left = 0;
        int mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] >= nums[left])//{4,5,6,7,0,1,2}
            {
                if(nums[left] <= target && nums[mid] >= target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if(nums[right] >= target && nums[mid] <= target)
                    left = mid + 1;
                else
                    left = mid - 1;
            }
        }
        return -1; 
    }
};


