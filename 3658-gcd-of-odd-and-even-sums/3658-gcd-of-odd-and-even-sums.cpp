class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumo=0, sume=0;
        for(int i=1;i<2*n;i++){
            sumo+=i;
            i++;
        }
        for(int i=0;i<=2*n;i++){
            sume+=i;
            i++;
        }
        return gcd(sumo,sume);
    }
};