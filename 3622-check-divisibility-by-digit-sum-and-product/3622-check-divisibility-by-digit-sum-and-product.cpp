class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int x = n;
        int product = 1;
        while(n!=0){
            int a = n%10;
            n=n/10;
            sum+=a;
            product*=a;
        }
        sum+=product;
        if(x%sum==0) return true;
        return false;
    }
};