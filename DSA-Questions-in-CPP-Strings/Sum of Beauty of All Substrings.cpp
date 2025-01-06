//Sum of Beauty of All Substrings

class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int beautySum = 0;
        
        // Iterate over each starting point of the substring
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0); // frequency array for 26 lowercase letters
            
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++; // increment frequency of current character
                
                int maxFreq = 0, minFreq = INT_MAX; // track max and min frequencies
                
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]); // update max frequency
                        minFreq = min(minFreq, freq[k]); // update min frequency
                    }
                }
                
                beautySum += maxFreq - minFreq; // add the beauty of current substring
            }
        }
        
        return beautySum;
    }
};
