class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
                // FIXED: Agar array khali hai toh empty string return karo
                        if (strs.empty()) return "";

                                // FIXED: Pehle string ko base maan kar baaki sabse compare karenge
                                        string prefix = strs[0];

                                                for (int i = 1; i < strs.size(); i++) {
                                                            // FIXED: Jab tak current string prefix se start nahi hoti, prefix ko chota karte jao
                                                                        while (strs[i].find(prefix) != 0) {
                                                                                        prefix = prefix.substr(0, prefix.length() - 1);
                                                                                                        // FIXED: Agar prefix chote hote hote khali ho jaye, toh koi common prefix nahi hai
                                                                                                                        if (prefix.empty()) return "";
                                                                                                                                    }
                                                                                                                                            }

                                                                                                                                                    return prefix;
                                                                                                                                                        }
                                                                                                                                                        };
