#include<iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        // Two-pointer approach
        int left = 0, right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            // Calculate the current area
            int width = right - left;
            int current_area = std::min(height[left], height[right]) * width;

            // Update the max area
            max_area = std::max(max_area, current_area);

            // Move the pointer pointing to the shorter line inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec = {1,1};
    int res = sol.maxArea(vec);
    std::cout << res << std::endl;
}