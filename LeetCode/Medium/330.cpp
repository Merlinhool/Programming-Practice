class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        vector<long long> num;
        for(int i = 0; i < (int)nums.size(); ++i) num.push_back(nums[i]);
        num.push_back(n + 1L);
        long long ans = 0;
        long long sum = 0;
        for(int i = 0; i < (int)num.size() && sum <= n; ++i) {
            if(num[i] > sum + 1) {
                for(long long j = sum+1; j < num[i] && sum <= n; j = sum+1) {
                    //cout << j << " " << sum << endl;
                    ++ans; sum += j;
                }
            }
            sum += num[i];
        }
        return (int)ans;
    }
};
