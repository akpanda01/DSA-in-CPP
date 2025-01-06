//Peak Element


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st = 0, end = nums.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] > nums[mid + 1]) {
                // Peak is in the left half or is the current element
                end = mid;
            } else {
                // Peak is in the right half
                st = mid + 1;
            }
        }
        return st; // st == end
    }
};
