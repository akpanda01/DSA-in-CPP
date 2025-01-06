//Single Element in a Sorted Array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            // Check pair alignment
            if (nums[mid] == nums[mid ^ 1]) {
                st = mid + 1; // Move right
            } else {
                end = mid; // Move left
            }
        }
        return nums[st];
    }
};
