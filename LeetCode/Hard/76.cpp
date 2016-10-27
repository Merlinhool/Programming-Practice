class Solution {
        public:
                int index(char c) {
                        if(c >= 'a' && c <= 'z') return c - 'a';
                        return c - 'A' + 26;
                }
                string minWindow(string s, string t) {
                        int n = s.length(), char_size = 52;
                        vector<int> count(char_size, 0), pos(n, 0), last(char_size, n), ans(n, n);
                        for(int i = 0; i < (int)t.length(); ++i) {
                                ++count[index(t[i])];
                        }
                        for(int i = n-1; i >= 0; --i) {
                                pos[i] = last[index(s[i])];
                                last[index(s[i])] = i;
                        }
                        for(int i = 0; i < char_size; ++i) if(count[i]){
                                int pre = -1, first = -1;
                                for(int j = 0; j < n; ++j) {
                                        if(index(s[j]) == i) {
                                                if(first == -1) first = j;
                                                if(count[i] > 1) --count[i];
                                                else if(count[i] == 1) {
                                                        pre = first;
                                                        count[i] = 0;
                                                } else {
                                                        pre = pos[pre];
                                                }
                                        }
                                        ans[j] = min(pre, ans[j]);
                                }
                        }

                        int idx = -1, len = n + 1;
                        for(int i = 0; i < n; ++i) if(ans[i] >= 0 && i-ans[i]+1 < len){
                                len = i - ans[i] + 1;
                                idx = ans[i];
                        }
                        if(idx == -1) return "";
                        return s.substr(idx, len);
                }
};
