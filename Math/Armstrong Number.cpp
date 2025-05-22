class Solution {
public:
    bool isArmstrong(int n) {
        int count = 0;
        int sum = 0;
        int org = n;
        int temp =n;
        while(temp!=0){
            int digit = temp%10;
            count++;
            temp=temp/10;
        }
        temp=n;
        while(temp!=0){
            int digit = temp%10;
            sum += pow(digit,count);
            temp=temp/10;
        }
        return sum==org;    


    }
};
