class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int size=intervals.size();
        if(size==1) return 1;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){ return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });
        for(int i=0;i<size-1;i++){
            if(intervals[i][0]<=intervals[i+1][0] && intervals[i][1]>=intervals[i+1][1]){
                intervals.erase(intervals.begin() + i+1);
                size--;
                i--;
            }
        }
        return intervals.size();
    }
};