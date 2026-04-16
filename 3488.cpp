class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]].push_back(i);
        }

        int n = nums.size();
        for (auto& [_, p] : indices) {
            // 前后各加一个哨兵
            int i0 = p[0];
            p.insert(p.begin(), p.back() - n);
            p.push_back(i0 + n);
        }

        for (int& i : queries) { // 注意这里是引用
            auto& p = indices[nums[i]];
            if (p.size() == 3) {
                i = -1;
            } else {
                int j = ranges::lower_bound(p, i) - p.begin();
                i = min(i - p[j - 1], p[j + 1] - i);
            }
        }
        return queries;
    }
};
