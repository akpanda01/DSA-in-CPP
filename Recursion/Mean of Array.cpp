//Mean of Array

class Solution {
  public:
    int findMeanHelper(vector<int>& arr, int n) {
        // Base case: If only one element, return that element
        if (n == 1) {
            return arr[0];
        }
        
        // Recursive case: Sum of first (n-1) elements + nth element
        return arr[n - 1] + findMeanHelper(arr, n - 1);
    }

    int findMean(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0; // Edge case: empty array

        int sum = findMeanHelper(arr, n);
        return sum / n;
    }
};
