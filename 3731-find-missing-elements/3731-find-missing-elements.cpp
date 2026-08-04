class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> res;
        int a  = nums[0];
        int b = nums[n-1];
        int j=0;
        for(int i=a;i<b;i++){
           if(nums[j]==i){
            j++;
           }
           else{
            res.push_back(i);
           }
        }
        return res;
    }
};