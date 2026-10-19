class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> result;
        sort(nums.begin(),nums.end());
        int a = -1;
        for(int i=0;i<nums.size();i++){
            if(target==nums[i]){
                a = i;
                break;
            }
        }
        while(a<nums.size()){
            if(nums[a]==target){
                result.push_back(a);
                a++;
            }
            else break;
        }
        return result;
    }
};