//Container With Most Water 

class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        
        int left = 0;
        int right = arr.size()-1;
        int maxArea = 0;
        
        while(left<right){
            int h = min(arr[left],arr[right]);
            int w =right -left;
            maxArea = max(maxArea , h*w);
            
            if(arr[left] < arr[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};
