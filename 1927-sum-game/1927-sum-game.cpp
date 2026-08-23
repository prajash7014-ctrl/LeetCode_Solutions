class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int L = 0, R = 0;
        int qL = 0, qR = 0;

        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                qL++;
            else
                L += num[i] - '0';
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                qR++;
            else
                R += num[i] - '0';
        }

        if ((qL + qR) % 2) return true;

        return (L - R) != ((qR - qL) / 2) * 9;
    }
};