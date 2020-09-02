#include <vector>
class Solution {
public:
    int pivotIndex(std::vector<int>& nums);
};

int Solution::pivotIndex(std::vector<int>& nums)
{
    int sum = 0;
    int left_sum = 0;
    int right_sum = 0;
    for (int i : nums) {
        sum += i;
    } 
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] + 2 * left_sum == sum)
            return i;
        left_sum += nums[i];
    }   
    return -1;
}