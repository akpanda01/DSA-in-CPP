//Find Kth Rotation

class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] > arr[right]) {
                left = mid + 1; // The minimum must be in the right part
            } else {
                right = mid; // The minimum is in the left part
            }
        }
        
        return left; // The position of the smallest element
    }
};
