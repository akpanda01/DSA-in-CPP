//Sub-Array with Sum K

//Brute Force - O(n^2)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        int count=0;

        for(int i =0;i<n;i++){
            int sum =0;
            for(int j = i;j<n;j++){
                sum+=nums[j];
                if(sum == k){
                    count++;
                }
            }
        }
        return count;
    }
};


//Optimal Approach - Prefix Sum and Hashmap - T.C = O(n) & S.C = O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumFreq;
        prefixSumFreq[0] = 1; // To handle cases where prefix sum equals k

        int count = 0;
        int sum = 0;

        for (int num : nums) {
            sum += num;

            // Check if (sum - k) exists in the map
            if (prefixSumFreq.find(sum - k) != prefixSumFreq.end()) {
                count += prefixSumFreq[sum - k];
            }

            // Update the frequency of the current prefix sum
            prefixSumFreq[sum]++;
        }

        return count;
    }
};


