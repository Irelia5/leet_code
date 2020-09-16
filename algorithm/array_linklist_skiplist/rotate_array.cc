#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums, 0, nums.size());
        reverse(nums, 0, k);
        reverse(nums, k, nums.size());
    }
    //end is the next of end element 
    void reverse(vector<int>& nums, int start, int end)
    {
        for (int i = start; i < (start + end) / 2; ++i) {
            std::swap(nums[i], nums[end-1-i+start]);
        }
    }
};