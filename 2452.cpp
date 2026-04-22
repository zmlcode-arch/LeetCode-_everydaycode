class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (auto& q : queries) {
            for (auto& s : dictionary) {
                int cnt = 0;
                for (int i = 0; i < s.size() && cnt <= 2; i++) {
                    if (q[i] != s[i]) {
                        cnt++;
                    }
                }
                if (cnt <= 2) {
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};
