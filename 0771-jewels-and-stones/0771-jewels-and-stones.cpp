class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int n = jewels.size();
        int c = 0;
        for(int i=0;i<jewels.size();i++){
            int a = count(stones.begin(),stones.end(),jewels[i]);
            c+=a;
        }
        return c;
    }
};