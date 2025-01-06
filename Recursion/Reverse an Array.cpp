//Reverse an Array


class Solution {
public:
    void revHelp(vector<int>& nums, int left, int right) {
        if (left >= right) return; // Base case: when pointers cross, stop recursion

        swap(nums[left], nums[right]); // Swap elements at the two ends
        revHelp(nums, left + 1, right - 1); // Recursive call for the next pair
    }

    vector<int> reverseArray(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        revHelp(nums, left, right); // Helper function to reverse the array
        return nums; // Return the reversed array
    }
};
