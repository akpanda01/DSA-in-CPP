//Count occurrences of a number in a sorted array with duplicates

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        int first = -1, last = -1;

        // Find the first occurrence of the target
        int st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (arr[mid] == target) {
                first = mid;    // Record potential first occurrence
                end = mid - 1;  // Narrow search to the left
            } else if (arr[mid] < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // If the target is not found, return 0
        if (first == -1) return 0;

        // Find the last occurrence of the target
        st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (arr[mid] == target) {
                last = mid;    // Record potential last occurrence
                st = mid + 1; // Narrow search to the right
            } else if (arr[mid] < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // Count the occurrences
        return last - first + 1;
    }
};

