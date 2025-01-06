//Find First and Last Position of Element in Sorted Array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> answer(2, -1); // Initialize with [-1, -1]
        
        // Find the first occurrence
        int st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                answer[0] = mid; // Update the first occurrence
                end = mid - 1;   // Continue searching in the left half
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        // Find the last occurrence
        st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                answer[1] = mid; // Update the last occurrence
                st = mid + 1;    // Continue searching in the right half
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        
        return answer;
    }
};
