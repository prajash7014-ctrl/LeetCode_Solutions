class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int miss;
        vector<int> arr;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        vector<int> res;

        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1]){
                res.push_back(arr[i]);
            }
        }
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        
        if (arr[0] != 1) {
            res.push_back(1);
            return res;
        }

        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i + 1] != arr[i] + 1) {
                res.push_back(arr[i] + 1);
                return res;
            }
        }


        if (arr.back() != n * n) {
            res.push_back(n * n);
        }
        return res;
    }
};