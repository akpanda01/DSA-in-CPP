//Rearrange Array Elements by Sign

//Brute Force
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positives, negatives, result;
        
        for (int num : nums) {
            if (num > 0) positives.push_back(num);
            else negatives.push_back(num);
        }
        
        int n = positives.size();
        for (int i = 0; i < n; i++) {
            result.push_back(positives[i]);
            result.push_back(negatives[i]);
        }
        
        return result;
    }
};


//Optimal Approach

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int posIndex = 0, negIndex = 1;
        
        for (int num : nums) {
            if (num > 0) {
                result[posIndex] = num;
                posIndex += 2;
            } else {
                result[negIndex] = num;
                negIndex += 2;
            }
        }
        
        return result;
    }
};

