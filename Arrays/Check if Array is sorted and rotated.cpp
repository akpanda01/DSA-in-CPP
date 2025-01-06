//Check if Array is sorted and rotated

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0; // Count of rotational breaks
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Compare current element with the next, wrapping around using modulo
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            // If there are more than one rotational breaks, it's invalid
            if (count > 1) {
                return false;
            }
        }
        return true; // Array is sorted and rotated
    }
};
