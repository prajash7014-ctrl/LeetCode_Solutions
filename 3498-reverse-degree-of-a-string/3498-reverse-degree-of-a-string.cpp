class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i=0;i<s.size();i++){
            int a = s[i]-'a'+1;
            a = 27-a;
            sum += (a)*(i+1);
        }
        return sum;
    }
};