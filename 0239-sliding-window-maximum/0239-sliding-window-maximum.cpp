class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        int  n= nums.size();
        if(n==1) return nums;
        for(int i=0;i<n;i++){
            while(q.size()>0 && nums[i]>nums[q.back()]) q.pop_back();
            q.push_back(i);
            int j = i-k+1;
            while(q.front()<j) q.pop_front();
            if(i>=k-1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};