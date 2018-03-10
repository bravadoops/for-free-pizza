class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if ((n+m) % 2 == 0) {
            // even 
            return (getMedian(nums1, m, nums2, n, (m+n)/2) + getMedian(nums1, m, nums2, n, (m+n)/2+1)) / 2.0;
        }
        else {
            // odd
            return getMedian(nums1, m, nums2, n, (m+n)/2+1);
        }
    }
    int getMedian(vector<int> a, int m, vector<int> b, int n, int k) {
        // a is empty
        if (m == 0) return b[k-1];
        if (n == 0) return a[k-1];
        // k == 1
        if (k <= 1) return min(a[0], b[0]);
        if (n/2 + m/2 + 1 >= k) {
            if (b[n/2] >= a[m/2]) {
                // drop b|n/2 -> n|  part
                return getMedian(a, m, b, n/2, k);
            } else {
                // drop a|n/2 -> n|  part
                return getMedian(a, m/2, b, n, k);

            }
        } else {
            if (b[n/2] >= a[m/2]) {
                // drop a|0 -> m/2 | part, k should minus m/2+1
                vector<int> right_a (a.begin()+m/2+1, a.end());
                return getMedian(right_a, m - m/2 - 1, b, n, k - m/2 -1); 
            } else {
                // drop b|0 -> n/2| part
                vector<int> right_b (b.begin()+n/2+1, b.end());
                return getMedian(a, m, right_b, n - n/2 -1, k - n/2 -1);
            }
        }
    }
};