class Solution {
public:
    int rob(vector<int>& num) {
        int n = num.size();
        if(!n) return 0;
        if(n == 1) return num[0];
        vector<int> dp(n, 0);
        for(int i = 0; i < n; ++i) {
            if(i == 0) dp[i] = 0;
            else if(i == 1) dp[i] = num[i];
            else dp[i] = max(dp[i-1], dp[i-2] + num[i]);
        }
        vector<int> dp2(n, 0);
        for(int i = 0; i < n; ++i) {
            if(i == n-1) {
                return max(dp2[i-1], dp[i]);
            }
            if(i == 0) dp2[i] = num[i];
            else if(i == 1) dp2[i] = (num[i], dp2[i-1]);
            else dp2[i] = max(dp2[i-1], dp2[i-2] + num[i]);
        }
    }
};
