class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        
        for(int i=0;i<n-1;i++){
            if(nums[i+1]==nums[i]+1){
                sum+=nums[i+1];
            }
            else {
                break;
            }
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==sum){
                sum++;
            }
            else if(sum>nums[i] || sum<nums[i]){
                continue;
            }
        }
        
        return sum;
    }
};