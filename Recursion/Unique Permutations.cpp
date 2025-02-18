//Unique Permutations

class Solution {
  public:
    void backtrack(vector<int>& arr, int start, set<vector<int>>& uniquePermutations) {
        if (start == arr.size()) {
            uniquePermutations.insert(arr);
            return;
        }
        for (int i = start; i < arr.size(); i++) {
            swap(arr[start], arr[i]);
            backtrack(arr, start + 1, uniquePermutations);
            swap(arr[start], arr[i]); // Backtrack
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        sort(arr.begin(), arr.end()); // Sort to get lexicographical order
        set<vector<int>> uniquePermutations;
        backtrack(arr, 0, uniquePermutations);
        return vector<vector<int>>(uniquePermutations.begin(), uniquePermutations.end());
    }
};
