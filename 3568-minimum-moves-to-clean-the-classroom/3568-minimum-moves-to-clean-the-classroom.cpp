class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        vector<pair<int, int>> litter;

        // Find S and L cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();
        int targetMask = (1 << k) - 1;

        if (k == 0) return 0;

        // Every L gets a bit number
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < k; i++) {
            id[litter[i].first][litter[i].second] = i;
        }

        // best[r][c][mask] = maximum energy reached
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << k, -1)
            )
        );

        // {row, col, mask, remaining energy}
        queue<tuple<int, int, int, int>> q;

        q.push({sr, sc, 0, energy});
        best[sr][sc][0] = energy;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        int moves = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, currEnergy] = q.front();
                q.pop();

                // All litter collected
                if (mask == targetMask) {
                    return moves;
                }

                // Cannot move without energy
                if (currEnergy == 0) continue;

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Boundary
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if (classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy = currEnergy - 1;
                    int newMask = mask;

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        newMask |= (1 << id[nr][nc]);
                    }

                    // Reset energy
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // Dominated state
                    if (best[nr][nc][newMask] >= newEnergy) {
                        continue;
                    }

                    best[nr][nc][newMask] = newEnergy;
                    q.push({nr, nc, newMask, newEnergy});
                }
            }

            moves++;
        }

        return -1;
    }
};