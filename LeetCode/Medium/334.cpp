class Solution {
public:
    bool increasingTriplet(vector<int>& num) {
        vector<int> dp(3, 1<<30);
        int n = num.size();
        for(int i = 0; i < n; ++i) {
            assert(num[i] != (1<<30));
            if(dp[1] != (1<<30) && dp[1] < num[i]) dp[2] = num[i];
            if(dp[0] != (1<<30) && dp[0] < num[i]) dp[1] = min(dp[1], num[i]);
            dp[0] = min(dp[0], num[i]);
            if(dp[2] != (1<<30)) return true;
        }
        return false;
    }
};
