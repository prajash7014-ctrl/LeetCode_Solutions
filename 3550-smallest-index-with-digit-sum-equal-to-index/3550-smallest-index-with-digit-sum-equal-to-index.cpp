class Solution {
public:
    int sumofdig(int x){
        int sum = 0;
        while(x!=0){
            sum+=x%10;
            x/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        for(int i=0;i<n;i++){
            if(i==sumofdig(nums[i])){
                arr.push_back(i);
            }
        }
        if(arr.empty()) return -1;
        else return *min_element(arr.begin(),arr.end());
    }
};