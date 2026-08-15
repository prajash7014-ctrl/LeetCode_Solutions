class Solution {
    public:
    int maximumLengthSubstring(string s) {
    int n = s.length();
    int max_len = 0;
    int left = 0;
    unordered_map<char, int> count;
    for (int right = 0;
    right < n;
    right++) {
    count[s[right]]++;
    while (count[s[right]] > 2) {
    count[s[left]]--;
    left++;
    }
    max_len = max(max_len, right - left + 1);
    }
    return max_len;
    }
    }
    ;

