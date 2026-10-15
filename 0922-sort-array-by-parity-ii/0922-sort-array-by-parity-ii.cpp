class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i%2==0 && nums[i]%2==0) continue;
            if(i%2==0 && nums[i]%2!=0){
                for(int j=i+1;j<n;j++){
                    if(nums[j]%2==0){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
            if(i%2!=0 && nums[i]%2==0){
               for(int j=i+1;j<n;j++){
                    if(nums[j]%2!=0){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
            else continue;
        }
        return nums;
    }
};