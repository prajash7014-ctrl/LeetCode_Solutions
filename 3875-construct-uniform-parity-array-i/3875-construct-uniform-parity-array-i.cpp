class Solution {
public:
    bool even(vector<int> nums){
        bool ans = true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                ans = false;
                break;
            }
        }
        return ans;
    }
    bool odd(vector<int> nums){
        bool ans = true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                ans = false;
                break;
            }
        }
        return ans;
    }
    bool make_odd(vector<int> nums1){
        bool ans = true;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            if(nums1[i]%2!=0){
               continue;
            }
            else{
                for(int j=0;j<n;j++){
                    if(i==j) continue;
                    if(j==n-1 && (nums1[i]-nums1[j])%2==0){
                        ans = false;
                        break;
                    }
                    if((nums1[i]-nums1[j])%2!=0){
                        break;
                    }
                }
            }
        }
    return ans;
    }
     bool make_even(vector<int> nums1){
        bool ans = true;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
               continue;
            }
            else{
                for(int j=0;j<n;j++){
                    if(i==j) continue;
                    if(j==n-1 && (nums1[i]-nums1[j])%2!=0){
                        ans = false;
                        break;
                    }
                    if((nums1[i]-nums1[j])%2==0){
                        break;
                    }
                }
            }
        }
    return ans;
    }
    bool uniformArray(vector<int>& nums1) {
        if(even(nums1)) return true;
        if(odd(nums1)) return true;
        vector<int> nums2;
        if(make_odd(nums1) || make_even(nums1)) return true;
        else return false;
    }
};