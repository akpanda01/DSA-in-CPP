//Combination Sum

class Solution {
public:
    void combSum(vector<int>& candidates, int idx, int target, vector<int>& combination, vector<vector<int>>& answer) {
        if (target == 0) { // Base case: found a valid combination
            answer.push_back(combination);
            return;
        }
        if (idx == candidates.size() || target < 0) { // Base case: out of bounds or negative target
            return;
        }

        // Include current candidate
        combination.push_back(candidates[idx]);
        combSum(candidates, idx, target - candidates[idx], combination, answer); // Allow reusing the same index
        combination.pop_back(); // Backtrack

        // Exclude current candidate
        combSum(candidates, idx + 1, target, combination, answer);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> combination;
        combSum(candidates, 0, target, combination, answer);
        return answer;
    }
};
