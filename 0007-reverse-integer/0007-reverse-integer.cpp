class Solution {
public:
    int reverse(int x) {
        long y=0;
        while(x!=0){
            y = y*10 + x%10;
            x = x/10;
        }
        if(y>= pow(-2,31) && y<=pow(2,31)-1){
            return y;
        }
        else{
            return 0;
        }
    }
};
