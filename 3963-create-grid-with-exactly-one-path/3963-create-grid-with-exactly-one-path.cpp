class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        for(int i=0;i<m;i++){
            string st = "";
            for(int j=0;j<n;j++){
                if(j==0 || i==m-1){
                    st+='.';
                }
                else{
                    st+='#';
                }
            }
            ans.push_back(st);
        }
        return ans;
    }
};