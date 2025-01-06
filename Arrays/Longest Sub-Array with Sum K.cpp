//Longest Sub-Array with Sum K

//Brute force - Nested Loops - O(n^2)
class Solution {
public:
    int lenOfLongSubarr(vector<int>& arr, int k) {
        int n = arr.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum == k) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};

//optimal approach - prefix sum and hashmap - T.C = O(n) & S.C = O(n)

class Solution {
public:
    int lenOfLongSubarr(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumMap;
        int maxLen = 0;
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            // If the prefix sum equals k
            if (sum == k) {
                maxLen = i + 1;
            }

            // If sum - k exists in the map
            if (prefixSumMap.find(sum - k) != prefixSumMap.end()) {
                maxLen = max(maxLen, i - prefixSumMap[sum - k]);
            }

            // Store the prefix sum if not already in the map
            if (prefixSumMap.find(sum) == prefixSumMap.end()) {
                prefixSumMap[sum] = i;
            }
        }

        return maxLen;
    }
};
