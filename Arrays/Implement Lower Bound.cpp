//Implement Lower Bound

class Solution {
  public:

    int findFloor(vector<int>& arr, int k) {

        int st = 0, end = arr.size() - 1;
        int floorIndex = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] <= k) {
                // Update the potential floor and search right
                floorIndex = mid;
                st = mid + 1;
            } else {
                // Search left
                end = mid - 1;
            }
        }

        return floorIndex;
    }
};
