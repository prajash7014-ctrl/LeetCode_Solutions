class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
      int x = k;
        for(int i=1;i<=n+1;i++){
            k = x;
            bool ans = false;
            k = k*i;
            for(int j=0;j<n;j++){
                if(nums[j]==k) ans = true;
            }
            if(ans!=true) break;
        }
        return k;
    }
};