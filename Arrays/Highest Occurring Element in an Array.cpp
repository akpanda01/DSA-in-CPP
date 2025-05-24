//BRUTE FORCE

class Solution {
public:
    int mostFrequentElement(vector<int>& nums) {
        int maxFreq = 0;
        int result = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }

            if (count > maxFreq || (count == maxFreq && nums[i] < result)) {
                maxFreq = count;
                result = nums[i];
            }
        }
        return result;
    }
};

//USING HASHING

class Solution {
public:
    int mostFrequentElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int num : nums){
            freq[num]++;
        }
        int maxFreq = 0, result = INT_MAX;
        for(auto& [num,count]:freq){
            if(count>maxFreq || (count == maxFreq && num < result)){
                maxFreq = count;
                result = num;
            }
        }
        return result;
    }
};
