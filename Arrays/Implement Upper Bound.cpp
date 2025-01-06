//Implement Upper Bound

//Brute Approach - T.C = O(n log n) & S.C = O(1)
//Ceil The Floor
class Solution {
public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // Sort the array
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int st = 0, end = n - 1;
        int floorIdx = -1, ceilIdx = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] == x) {
                // If x is found, both floor and ceil are the same
                return {arr[mid], arr[mid]};
            } else if (arr[mid] < x) {
                // Update floor and move right
                floorIdx = mid;
                st = mid + 1;
            } else {
                // Update ceil and move left
                ceilIdx = mid;
                end = mid - 1;
            }
        }

        // Get the floor and ceil values, considering -1 if no valid index
        int floorValue = (floorIdx != -1) ? arr[floorIdx] : -1;
        int ceilValue = (ceilIdx != -1) ? arr[ceilIdx] : -1;

        return {floorValue, ceilValue};
    }
};


//Optimal Approach - T.C = O(n) & S.C = O(1)
class Solution {
public:
    vector<int> findFloorAndCeil(vector<int> &arr, int x) {
        int floor = -1, ceil = -1;

        // Single traversal
        for (int num : arr) {
            if (num <= x) {
                floor = max(floor, num);
            }
            if (num >= x) {
                ceil = (ceil == -1) ? num : min(ceil, num);
            }
        }

        return {floor, ceil};
    }
};
