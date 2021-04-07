#include <vector>
using std::vector;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] & 1) {
                left++;
                continue;
            }
            if ((nums[right] & 1) == 0) {
                right--;
                continue;
            }
            std::swap(nums[left], nums[right]);
        }
        return nums;
    }
};

vector<int> exchange(vector<int>& nums) {
    int slow = 0;
    int fast = 0;
    while (fast < nums.size()) {
        if (nums[fast] & 1) {
            std::swap(nums[fast], nums[slow]);
            slow++;
        }
        fast++;
    }
    return nums;
}