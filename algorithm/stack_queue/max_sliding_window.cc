#include <vector>
#include <deque>
using namespace std;

class MonotonousQueue {
public:
    void push(int n) {
        while (!data.empty() && data.back() < n) data.pop_back();
        data.push_back(n);
    }
    
    void pop(int n) {
        if (!data.empty() && data.front() == n) {
            data.pop_front();
        }
    }

    int max() {
        return data.front();
    }
private:
    std::deque<int> data;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MonotonousQueue window;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k - 1) {
                window.push(nums[i]);
            } else {
                window.push(nums[i]);
                res.push_back(window.max());
                window.pop(nums[i-k+1]);
            }
        }
        return res;
    }
};