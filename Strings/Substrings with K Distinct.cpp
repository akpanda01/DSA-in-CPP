//Substrings with K Distinct


class Solution {
public:
    int countSubstr(string s, int k) {
        int diff = atMost(s, k) - atMost(s, k - 1);
        return diff;
    }
    
    int atMost(string s, int k) {
        int left = 0;
        int cnt = 0;
        unordered_map<char, int> hm;
        
        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];
            hm[ch]++;
            
            while (hm.size() > k) {
                char left_ch = s[left];
                hm[left_ch]--;
                if (hm[left_ch] == 0) {
                    hm.erase(left_ch);
                }
                left++;
            }
            cnt += right - left + 1;
        }
        return cnt;
    }
};
