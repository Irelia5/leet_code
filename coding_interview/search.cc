#include <vector>
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search_right(nums, target) - search_right(nums, target-1);
    }

    int search_right(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) right = mid - 1;
            else if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] == target) left = mid + 1;
        }
        return left;
    }
};