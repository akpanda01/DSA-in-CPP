//Binary Search to find X in sorted array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0;
        int end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] == target) {
                return mid; // Target found
            }
            else if (nums[mid] > target) {
                end = mid - 1; // Search in the left half
            }
            else {
                st = mid + 1; // Search in the right half
            }
        }
        return -1; // Target not found
    }
};
