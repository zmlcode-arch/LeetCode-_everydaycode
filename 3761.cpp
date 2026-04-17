class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> last_index;
        int n = nums.size(), ans = n;
        
        for (int j = 0; j < n; j++) {
            int x = nums[j];
            auto it = last_index.find(x);
            if (it != last_index.end()) {
                ans = min(ans, j - it->second);
            }

            int rev = 0;
            for (; x > 0; x /= 10) {
                rev = rev * 10 + x % 10;
            }
            last_index[rev] = j;
        }

        return ans < n ? ans : -1;
    }
};
