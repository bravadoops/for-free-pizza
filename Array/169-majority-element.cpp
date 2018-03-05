// Time O(n)
// Space O(1)
// different if-else will influence running time

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //O(1)
        int cand, sum = 0;
        //O(n)
        for (int n : nums) {
            if (n == cand) {
                sum += 1;
            } else {
                if (sum == 0) {
                    //change candidate
                    cand = n;
                    sum = 1;
                } else {
                    sum -= 1;
                }
            }
        }
        return cand;
    }
};