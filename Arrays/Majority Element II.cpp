//Majority Element II

//Brute Force - T.C = O(n) & S.C = O(n) 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        vector<int> result;
        int n = nums.size();
        
        // Count the frequency of each element
        for (int num : nums) {
            freq[num]++;
        }
        
        // Find elements appearing more than n/3 times
        for (auto& [key, count] : freq) {
            if (count > n / 3) {
                result.push_back(key);
            }
        }
        
        return result;
    }
};



//Optimal Approach - T.C = O(n) & S.C = O(1) 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c1 = -1, c2 = -1, cnt1 = 0, cnt2 = 0;

        // First pass: Find potential candidates
        for (int num : nums) {
            if (num == c1) {
                cnt1++;
            } else if (num == c2) {
                cnt2++;
            } else if (cnt1 == 0) {
                c1 = num;
                cnt1 = 1;
            } else if (cnt2 == 0) {
                c2 = num;
                cnt2 = 1;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        // Second pass: Validate the candidates
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == c1) cnt1++;
            else if (num == c2) cnt2++;
        }

        vector<int> result;
        if (cnt1 > n / 3) result.push_back(c1);
        if (cnt2 > n / 3) result.push_back(c2);

        return result;
    }
};


