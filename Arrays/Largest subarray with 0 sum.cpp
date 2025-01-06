//Largest subarray with 0 sum

class Solution {
public:
    int maxLen(vector<int>& arr) {
        unordered_map<int, int> prefixMap; // To store prefix sum and its first occurrence
        int maxLength = 0, prefixSum = 0;
        
        for (int i = 0; i < arr.size(); ++i) {
            prefixSum += arr[i];
            
            // If prefix sum is 0, subarray from start to current index has sum 0
            if (prefixSum == 0) {
                maxLength = i + 1;
            }
            
            // If prefix sum is seen before, calculate the subarray length
            if (prefixMap.find(prefixSum) != prefixMap.end()) {
                maxLength = max(maxLength, i - prefixMap[prefixSum]);
            } else {
                // Store the first occurrence of the prefix sum
                prefixMap[prefixSum] = i;
            }
        }
        
        return maxLength;
    }
};

//T.C = O(n)
//S.C = O(n)
