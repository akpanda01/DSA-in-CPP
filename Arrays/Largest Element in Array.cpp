//Largest Element in Array

class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int maximum = INT_MIN;
        
        for(int i =0;i<arr.size();i++){
            if(arr[i]>maximum){
                maximum = arr[i];
            }
        }
        return maximum;
    }
};
