class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        // Store reserved seats for each affected row
        unordered_map<int, set<int>> mp;

        for (auto &v : reservedSeats) {
            mp[v[0]].insert(v[1]);
        }

        // Every completely empty row can fit 2 groups
        long long ans = 2LL * n;

        for (auto &[row, seats] : mp) {

            bool left = true;    // seats 2-5
            bool right = true;   // seats 6-9
            bool middle = true;  // seats 4-7

            for (int s = 2; s <= 5; s++) {
                if (seats.count(s)) {
                    left = false;
                    break;
                }
            }

            for (int s = 6; s <= 9; s++) {
                if (seats.count(s)) {
                    right = false;
                    break;
                }
            }

            for (int s = 4; s <= 7; s++) {
                if (seats.count(s)) {
                    middle = false;
                    break;
                }
            }

            if (left && right) {
                // Already counted 2 groups
            }
            else if (left || right || middle) {
                // This row can accommodate only 1 group
                ans--;
            }
            else {
                // This row can accommodate 0 groups
                ans -= 2;
            }
        }

        return (int)ans;
    }
};