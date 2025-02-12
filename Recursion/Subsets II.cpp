//Subsets II

class Solution {
public:
    void generateSubsets(vector<int>& nums, vector<int>& subset, int index, vector<vector<int>>& result) {
        result.push_back(subset);  // Store current subset

        for (int i = index; i < nums.size(); i++) {
            // Skip duplicate elements to avoid duplicate subsets
            if (i > index && nums[i] == nums[i - 1]) continue;

            subset.push_back(nums[i]);  // Include element
            generateSubsets(nums, subset, i + 1, result);
            subset.pop_back();  // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;

        sort(nums.begin(), nums.end());  // Sort to handle duplicates easily
        generateSubsets(nums, subset, 0, result);

        return result;
    }
};
