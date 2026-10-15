class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
         vector<int> even;
       vector<int> odd;
       vector<int> result;
       int n = nums.size();
       if(n==1 || n==0) return nums;
       for(int i=0;i<n;i++){
        if(nums[i]%2==0){
            even.push_back(nums[i]);
        }
        else{
            odd.push_back(nums[i]);
        }
       } 
    for(int i=0;i<(n/2);i++){
        result.push_back(even[i]);
        result.push_back(odd[i]);
    }
    return result;
    }
};