#include <unordered_map>
#include <vector>
#include <algorithm> // for min
using namespace std;

class Solution {
public:
    int secondMostFrequentElement(vector<int> &nums) {
        int n = nums.size();
        int maxFreq = 0, secMaxFreq = 0; 
        int maxEle = -1, secEle = -1;
        
        unordered_map<int, int> freqMap;
        
        // Count frequencies
        for (int i = 0; i < n; i++) {
            freqMap[nums[i]]++;
        }
            
        // Find max and second max frequency elements
        for (auto it : freqMap) {
            int ele = it.first;
            int freq = it.second;

            if (freq > maxFreq) {
                // Current max becomes second max
                secMaxFreq = maxFreq;
                secEle = maxEle;

                maxFreq = freq;
                maxEle = ele;
            }
            else if (freq == maxFreq) {
                // Tie for max frequency, choose smaller element
                maxEle = min(maxEle, ele);
            }
            else if (freq > secMaxFreq) {
                // New second max frequency
                secMaxFreq = freq;
                secEle = ele;
            }
            else if (freq == secMaxFreq) {
                // Tie for second max frequency, choose smaller element
                secEle = min(secEle, ele);
            }
        }
        
        // If no second most frequent element exists, secEle will remain -1
        return secEle;
    }
};
