//Sort characters by frequency


class Solution {
public:
    vector<char> frequencySort(string& s) {
        unordered_map<char, int> freqMap;
        int maxFreq = 0;

        // Count frequencies and find the maximum frequency
        for (char c : s) {
            maxFreq = max(maxFreq, ++freqMap[c]);
        }

        // Bucket to group characters by frequency
        vector<vector<char>> buckets(maxFreq + 1);
        for (auto& [c, freq] : freqMap) {
            buckets[freq].push_back(c);
        }

        // Process buckets in reverse order of frequency
        vector<char> result;
        for (int i = maxFreq; i > 0; --i) {
            if (!buckets[i].empty()) {
                // Sort characters with the same frequency alphabetically
                sort(buckets[i].begin(), buckets[i].end());
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }

        return result;
    }
};
