class Solution {
public:
    int smallestNumber(int n, int t) {
        int product=1;
        int a = n;
        while(a!=0){
            product*=a%10;
            a/=10;
        }
        if(product%t==0){
            return n;
        }
        return smallestNumber(n+1,t);
    }
};