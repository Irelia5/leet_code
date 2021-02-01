#include <vector>
#include <set>
using std::vector;
using std::set;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i) {
                if (nums[i] == nums[nums[i]]) {
                    return nums[i];
                }
                std::swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};
