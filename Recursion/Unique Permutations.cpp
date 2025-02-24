//Unique Permutations

class Solution {
  public:
// backtrack() helps to generate permutations
    void backtrack(vector<int>& arr, int start, set<vector<int>>& uniquePermutations) {
        if (start == arr.size()) { //the recursion would stop when the start reaches the length of the string or array
            uniquePermutations.insert(arr); // the current permutation of arr will be inserted in the vector
            return;
        }
        for (int i = start; i < arr.size(); i++) {
            swap(arr[start], arr[i]);//Swap the numbers or characters to explore different position
            backtrack(arr, start + 1, uniquePermutations);// moves to the next index to generate further permutations
            swap(arr[start], arr[i]); // Backtracks - it restores the original order of the string so it would not affect the future recursive calls
        }
    }

//uniquePerms() helps to return the final result that is the unique permutations
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        sort(arr.begin(), arr.end()); // Sort to get lexicographical order
        set<vector<int>> uniquePermutations;
        backtrack(arr, 0, uniquePermutations); // starts the recursive permutation generation
        return vector<vector<int>>(uniquePermutations.begin(), uniquePermutations.end()); //set to vector conversion
    }
};


