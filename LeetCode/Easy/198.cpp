class Solution {
public:
    int rob(vector<int>& num) {
        int n = num.size();
        if(!n) return 0;
        vector<int> dp(n, 0);
        for(int i = 0; i < n; ++i) {
            if(i == 0) dp[i] = num[i];
            else if(i == 1) dp[i] = max(num[i], dp[i-1]);
            else dp[i] = max(dp[i-2] + num[i], dp[i-1]);
        }
        return dp[n-1];
    }
};
