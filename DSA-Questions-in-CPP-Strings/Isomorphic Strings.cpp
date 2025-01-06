//Isomorphic Strings


class Solution {
public:
    bool isomorphicString(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> mapST, mapTS;

        for (int i = 0; i < s.size(); ++i) {
            char chS = s[i], chT = t[i];

            // Check if mapping exists and is consistent
            if (mapST.count(chS) && mapST[chS] != chT) return false;
            if (mapTS.count(chT) && mapTS[chT] != chS) return false;

            // Create mappings
            mapST[chS] = chT;
            mapTS[chT] = chS;
        }

        return true;
    }
};
