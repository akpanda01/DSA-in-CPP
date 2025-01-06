//Print Anagrams Together


class Solution {
public:
    vector<vector<string>> anagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        
        // Group words by their sorted version
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            map[key].push_back(s);
        }

        // Collect grouped anagrams into a result vector
        vector<vector<string>> result;
        for (auto& entry : map) {
            result.push_back(entry.second);
        }

        return result;
    }
};
