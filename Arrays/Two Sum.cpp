//Two Sum

//Brute Force - Using Nested for loops - T.C = O(n^2) & S.C = O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(nums[i]+nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};

//Better Approach - Using Sorting and Two-Pointer Technique - T.C = O(n log n) & S.C = O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> indexedNums;
        
        // Store the elements along with their indices
        for (int i = 0; i < n; i++) {
            indexedNums.push_back({nums[i], i});
        }
        
        // Sort the array based on values
        sort(indexedNums.begin(), indexedNums.end());
        
        int left = 0, right = n - 1;
        
        while (left < right) {
            int sum = indexedNums[left].first + indexedNums[right].first;
            if (sum == target) {
                return {indexedNums[left].second, indexedNums[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};


//Optimal Approach - Using Hashmap - T.C = O(n) & S.C = O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i =0;i<n;i++){
            int complement = target - nums[i];

            if(mp.find(complement) != mp.end()){
                return {mp[complement],i};
            }

            mp[nums[i]] = i;
        }
        return {};
    }
};
