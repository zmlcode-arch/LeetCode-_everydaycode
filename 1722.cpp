class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<vector<int>> g(n);
        for (auto& e : allowedSwaps) {
            int i = e[0], j = e[1];
            g[i].push_back(j); // 建图
            g[j].push_back(i);
        }

        vector<int8_t> vis(n);
        unordered_map<int, int> diff;

        auto dfs = [&](this auto&& dfs, int x) -> void {
            vis[x] = true; // 避免重复访问
            // 抵消相同的元素，最终剩下 source 和 target 各自多出来的元素（对称差）
            diff[source[x]]++;
            diff[target[x]]--;
            for (int y : g[x]) {
                if (!vis[y]) {
                    dfs(y);
                }
            }
        };

        int ans = 0;
        for (int x = 0; x < n; x++) {
            if (!vis[x]) {
                diff.clear();
                dfs(x);
                for (auto& [_, c] : diff) {
                    ans += abs(c);
                }
            }
        }
        return ans / 2; // 有 ans / 2 对多出来的元素
    }
};
