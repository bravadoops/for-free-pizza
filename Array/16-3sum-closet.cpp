// Time O(n^2)
// Space O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        // smallest_gap
        // use smallest_gap to decide when to update itself
        // && when to update sum(result)
        int sum = 0;
        int smallest_gap = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            int a = i+1, b = nums.size()-1;
            while (a < b) {
                if (abs(nums[a] + nums[b] - t) < smallest_gap) {
                    sum = nums[i] + nums[a] + nums[b];
                    smallest_gap = abs(nums[a] + nums[b] - t);
                }
                if (nums[a] + nums[b] > t) {
                    b--;
                } else if (nums[a] + nums[b] < t) {
                    a++;
                } else {
                    return nums[i] + nums[a] + nums[b];
                }
            }
        }
        return sum;
    }
};