class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int minOdd = INT_MAX, minEven = INT_MAX;
        long long oddCount = 0, evenCount = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 0) {
                evenCount++;
                minEven = min(minEven, nums1[i]);
            } else {
                oddCount++;
                minOdd = min(minOdd, nums1[i]);
            }
        }
        
        
        bool p0 = (oddCount == 0);
        
        
        bool p1 = (evenCount == 0) || (oddCount > 0 && minOdd < minEven);
        
        return p0 || p1;
    }
};