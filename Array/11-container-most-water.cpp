// O(n)
// O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int i = 0, j = size - 1;
        // no need to calculate now
        int h, l;
        int most_water = 0;
        while (i < j) {
            // h, l, most_water
            h = min(height[i],height[j]);
            l = j - i;
            most_water = max(most_water, h*l);
            // jump over lower boundary
            while (height[i] <= h && i < j) i++;
            while (height[j] <= h && i < j) j--;

        }
        return most_water;
    }
};