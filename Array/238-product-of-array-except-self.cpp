// O(n)
// O(1)
// eg    1     2   3   4
// res   1    |1  |1*2|1*2*3
// right 2*3*4|3*4|4  |1

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        // start = 1
        res[0] = 1;
        // 1 -> n-1
        for (int i = 1; i < n; i++) {
            res[i] = res[i-1] * nums[i-1];
        }
        // end
        int right = 1;
        // end-1 -> 0
        for (int i = n-2; i >= 0; i--) {
            right *= nums[i+1];
            res[i] *= right;
        }
        return res;
    }
};