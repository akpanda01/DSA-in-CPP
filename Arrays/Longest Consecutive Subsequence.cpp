//Longest Consecutive Subsequence

//Brute Froce - Nested Loops - T.C = O(n^2) & S.C = O(1)
class Solution {
public:
    int findLongestConseqSubseq(vector<int>& arr) {
        int n = arr.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int currNum = arr[i];
            int currLen = 1;

            // Check for consecutive elements
            for (int j = 0; j < n; j++) {
                if (arr[j] == currNum + 1) {
                    currNum++;
                    currLen++;
                    j = -1; // Reset the inner loop to continue searching
                }
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};


//Better Approach - Sorting of Array - T.C = O(n log n) & S.C = O(1)
class Solution {
public:
    int findLongestConseqSubseq(vector<int>& arr) {
        if (arr.empty()) return 0;

        sort(arr.begin(), arr.end());
        int maxLen = 1, currLen = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1] + 1) {
                currLen++;
            } else if (arr[i] != arr[i - 1]) {
                currLen = 1;
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};


//Optimal Approach - Hash Set - T.C = O(n) & S.C = O(n)






