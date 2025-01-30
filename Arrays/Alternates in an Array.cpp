//Alternates in an Array

class Solution {
  public:
    vector<int> getAlternates(vector<int> &arr) {
        vector<int> result; // Stores alternate elements
        for (int i = 0; i < arr.size(); i += 2) { // Step by 2 for alternate elements
            result.push_back(arr[i]);
        }
        return result;
    }
};
