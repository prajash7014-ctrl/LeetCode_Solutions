class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        if(n%2==0){
            n=(n/2)-1;
        }
        else n = n/2;

        int val = nums[n];
        int sum  = 0;
        for(int i=0;i<nums.size();i++){
            sum+=abs(nums[i]-val);
        }
        return sum;
    }
};