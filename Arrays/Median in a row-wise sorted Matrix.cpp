//Median in a row-wise sorted Matrix


class Solution {
public:
    int median(vector<vector<int>> &mat) {
        vector<int> elements;

        // Flatten the matrix into a single array
        for (const auto &row : mat) {
            for (int val : row) {
                elements.push_back(val);
            }
        }

        // Sort the array
        sort(elements.begin(), elements.end());

        // Return the middle element
        int size = elements.size();
        return elements[size / 2];
    }
};
