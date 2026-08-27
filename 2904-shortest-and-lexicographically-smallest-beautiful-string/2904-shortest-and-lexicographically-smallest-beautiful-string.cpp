class Solution {
public:
    
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> store;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1') store.push_back(i);
        }
        if(store.size()<k) return "";
        string ans = "";
        for(int i=0;i+k-1<store.size();i++){
            int st = store[i];
            int  end = store[i+k-1];
            string curr = s.substr(st,end-st+1);
            if(ans=="" || curr.size()<ans.size() || ((curr.size()==ans.size()) && ans>curr)){
                ans = curr;
            }
        }
        return ans;
    }
};