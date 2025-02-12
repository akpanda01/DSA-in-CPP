//Subsets

class Solution {
public:
    void generateSubsets(vector<int>& arr, vector<int>& ans, int i, vector<vector<int>>& result) {
        if (i == arr.size()) {
            result.push_back(ans);  // Store the subset
            return;
        }

        // Exclude the current element
        generateSubsets(arr, ans, i + 1, result);

        // Include the current element
        ans.push_back(arr[i]);
        generateSubsets(arr, ans, i + 1, result);
        ans.pop_back();  // Backtrack
    }

    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> result;
        vector<int> ans;
        generateSubsets(arr, ans, 0, result);
        return result;
    }
};
