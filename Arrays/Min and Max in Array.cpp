//Min and Max in Array

class Solution {
  public:
    pair<long long, long long> getMinMax(vector<long long int> arr) {
        // code here
        int smallest = INT_MAX;
        int largest = INT_MIN;
        int n = arr.size();
        
        for(int i = 0;i<n;i++){
            if(arr[i] > largest){
                largest = arr[i];
            }
            if(arr[i]<smallest){
                smallest = arr[i];
            }
        }
        return {smallest,largest};
    }
};
