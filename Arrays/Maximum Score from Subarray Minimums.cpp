//Maximum Score from Subarray Minimums

class Solution {
public:

    int pairWithMaxSum(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return 0; // If the array has fewer than 2 elements, no valid pair exists.

        int maxSum = INT_MIN;

        // Iterate through adjacent pairs and compute their sums
        for (int i = 0; i < n - 1; i++) {
            int sum = arr[i] + arr[i + 1];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};
