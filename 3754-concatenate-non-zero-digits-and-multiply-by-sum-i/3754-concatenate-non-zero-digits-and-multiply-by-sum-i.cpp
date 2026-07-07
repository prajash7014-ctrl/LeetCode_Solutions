class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        long long i=0;
        long long sum = 0;
        while(n!=0){
            if(n%10!=0){
            int y = n%10;
            sum += y;
            x = y*pow(10,i) + x;
            i++;
            n = n/10;
            }
            else{
                n=n/10;
            }
        }
        x = x*sum;
        return x;
    }
};