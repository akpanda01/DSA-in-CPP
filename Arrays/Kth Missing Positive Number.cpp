//Kth Missing Positive Number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;

        // Binary search to find the position
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int missing = arr[mid] - (mid + 1); // Missing numbers before arr[mid]

            if (missing < k) {
                left = mid + 1; // Search to the right
            } else {
                right = mid - 1; // Search to the left
            }
        }

        // Missing count before index `left` is less than k
        return left + k;
    }
};
