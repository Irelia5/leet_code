#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> res;
        std::unordered_map<int, int> target_pair;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = target_pair.find(nums[i]);
            if (iter != target_pair.end()) {
                res.push_back(iter->second);
                res.push_back(i);
                break;
            }
            target_pair[target-nums[i]] = i;
        }
        return res;
    }
};