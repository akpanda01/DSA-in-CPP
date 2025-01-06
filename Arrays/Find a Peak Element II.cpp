//Find a Peak Element II


class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();    // Number of rows
        int n = mat[0].size(); // Number of columns

        int left = 0, right = n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Find the global maximum in the middle column
            int maxRow = 0;
            for (int i = 1; i < m; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            // Check neighbors in the left and right columns
            int leftValue = (mid > 0) ? mat[maxRow][mid - 1] : -1;
            int rightValue = (mid < n - 1) ? mat[maxRow][mid + 1] : -1;

            if (mat[maxRow][mid] > leftValue && mat[maxRow][mid] > rightValue) {
                // Found a peak
                return {maxRow, mid};
            } else if (leftValue > mat[maxRow][mid]) {
                // Move to the left half
                right = mid - 1;
            } else {
                // Move to the right half
                left = mid + 1;
            }
        }

        // Should never reach here
        return {-1, -1};
    }
};
