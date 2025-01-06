//Check if the array is sorted


class Solution {
public:
    bool checkSorted(vector<int>& nums, int index) {
        // Base case: if we reach the last element, the array is sorted
        if (index == nums.size() - 1) {
            return true;
        }
        // Check if the current element is greater than the next
        if (nums[index] > nums[index + 1]) {
            return false; // Array is not sorted
        }
        // Recursive call for the next element
        return checkSorted(nums, index + 1);
    }

    bool isSorted(vector<int>& nums) {
        // Call the recursive helper function starting from index 0
        if (nums.empty()) return true; // An empty array is considered sorted
        return checkSorted(nums, 0);
    }
};
