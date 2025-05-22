class Solution {
public:
    int largestDigit(int n) {
        int largest =0;
        while(n!=0){
            int digit = n% 10;
            if(digit>largest){
                largest = digit;
            }
            n = n/10;
        }
        return largest;

    }
};
