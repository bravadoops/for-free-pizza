// O(n^2)
// O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0 || matrix[0].size() == 0) {
            return;
        }
        int temp;
        for (int i = 0; i < n/2; i++) {
            for (int index = i; index < n-1-i; index++) {
                // save top-left
                temp = matrix[i][index];
                // move a->b || b = a 
                // eg. top-left = left-bottom
                matrix[i][index] = matrix[n-1-index][i];
                matrix[n-1-index][i] = matrix [n-1-i][n-1-index];
                matrix [n-1-i][n-1-index] = matrix[index][n-1-i];
                matrix[index][n-1-i] = temp;
            }
        }
        return;
    }
};