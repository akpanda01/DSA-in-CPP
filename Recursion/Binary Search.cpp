//Binary Search

class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        if (left > right) {
            return -1; // Target not found
        }

        int mid = left + (right - left) / 2; // Avoids overflow

        if (nums[mid] == target) {
            return mid; // Target found
        } 
        else if (nums[mid] > target) {
            return binarySearch(nums, left, mid - 1, target); // Search left half
        } 
        else {
            return binarySearch(nums, mid + 1, right, target); // Search right half
        }
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};
