//Sort an array of 0's 1's and 2's - Dutch National Flag Algorithm - O(n)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n  =nums.size();
        int low = 0 , mid = 0;
        int high = n-1;
        
        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                mid++;
                low++;
                
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
