//Permutations

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, int start) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);  // Swap to generate a new permutation
            backtrack(nums, result, start + 1);  // Recur for the next index
            swap(nums[start], nums[i]);  // Backtrack to restore original order
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, result, 0);
        return result;
    }
};
