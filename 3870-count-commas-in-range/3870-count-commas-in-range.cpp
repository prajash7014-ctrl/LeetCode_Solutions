class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        if(n>=1 && n<1000){
            ans = 0;
        }
    else{
        for(int i=1000;i<=n;i++){
            ans++;
        }
    }
        return ans;
    }
};