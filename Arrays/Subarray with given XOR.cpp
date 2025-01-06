//Subarray with given XOR

class Solution {
public:
    int subarrayXOR(vector<int>& A, int B) {
        unordered_map<int, int> freq; // To store frequencies of prefixXOR
        int prefixXOR = 0;           // To maintain the XOR of elements up to the current index
        int count = 0;               // Count of subarrays with XOR equal to B
        
        for (int num : A) {
            prefixXOR ^= num; // Update prefixXOR
            
            // Check if prefixXOR is already equal to B
            if (prefixXOR == B) {
                count++;
            }
            
            // Check if there exists a prefixXOR[start - 1] such that
            // prefixXOR[start - 1] = prefixXOR ^ B
            int requiredXOR = prefixXOR ^ B;
            if (freq.find(requiredXOR) != freq.end()) {
                count += freq[requiredXOR];
            }
            
            // Update the frequency of the current prefixXOR
            freq[prefixXOR]++;
        }
        
        return count;
    }
};
