//Next Permutation

//Brute Force - T.C = O(n!* n) & S.C = O(n!)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<vector<int>> permutations;

        // Step 1: Generate all permutations
        generatePermutations(nums, 0, permutations);

        // Step 2: Sort and remove duplicates
        sort(permutations.begin(), permutations.end());
        permutations.erase(unique(permutations.begin(), permutations.end()), permutations.end());

        // Step 3: Find the current array and return the next permutation
        for (int i = 0; i < permutations.size(); i++) {
            if (permutations[i] == nums) {
                if (i == permutations.size() - 1) {
                    nums = permutations[0]; // Wrap around if it's the last permutation
                } else {
                    nums = permutations[i + 1];
                }
                return;
            }
        }
    }

private:
    void generatePermutations(vector<int>& nums, int index, vector<vector<int>>& permutations) {
        if (index == nums.size()) {
            permutations.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            generatePermutations(nums, index + 1, permutations);
            swap(nums[i], nums[index]); // backtrack
        }
    }
};


//Better Approach - T.C = O(n log n) & S.C = O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (!next_permutation(nums.begin(), nums.end())) {
            // If no next permutation exists, sort to the smallest order
            sort(nums.begin(), nums.end());
        }
    }
};


//Optimal Approach - T.C = O(n) & S.C = O(1)


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        // Step 1: Find the first decreasing element from the end
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }

        // Step 2: If no such element exists, reverse the entire array
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find the smallest element larger than nums[idx] to the right
        for (int i = n - 1; i > idx; i--) {
            if (nums[i] > nums[idx]) {
                swap(nums[i], nums[idx]);
                break;
            }
        }

        // Step 4: Reverse the subarray to the right of idx
        reverse(nums.begin() + idx + 1, nums.end());
    }
};

