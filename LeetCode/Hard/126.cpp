class Solution {
public:
    static const int Max_N = 11111;
    string idx[Max_N];
    map<string, int> has;
    vector<int> pre[Max_N], Edge[Max_N];
    int dis[Max_N];
    queue<int> Q;
    vector<vector<string> > ans;
    vector<string> temp;
    void dfs(int x) {
        temp.push_back(idx[x]);
        if(dis[x] == 0) {
            ans.push_back(temp);
            temp.erase(temp.end()-1);
            return;
        }
        for(int i = 0; i < (int)pre[x].size(); ++i) {
            dfs(pre[x][i]);
        }
        temp.erase(temp.end()-1);
    }
    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        int n = wordList.size(), tmp = 0;
        assert(n < Max_N);
        
        has.clear();
        while(!Q.empty()) Q.pop();
        for(int i = 0; i < n; ++i) pre[i].clear(), Edge[i].clear();
        for(int i = 0; i < n; ++i) dis[i] = n + 10;
        
        for(unordered_set<string>::iterator it = wordList.begin(); it != wordList.end(); ++it, ++tmp) {
            idx[tmp] = *it;
            has[*it] = tmp;
        }
        for(unordered_set<string>::iterator it = wordList.begin(); it != wordList.end(); ++it) {
            string s = *it;
            int idx_it = has[*it];
            for(int i = 0; i < s.length(); ++i) {
                char ct = s[i];
                for(char j = 'a'; j <= 'z'; ++j) {
                    if(ct == j) continue;
                    s[i] = j;
                    if(has.find(s) != has.end()) {
                        Edge[idx_it].push_back(has[s]);
                    }
                }
                s[i] = ct;
            }
        }
        int start = has[beginWord], end = has[endWord];
        
        Q.push(start);
        dis[start] = 0;
        while(!Q.empty()) {
            int top = Q.front(); Q.pop();
            if(top == end) break;
            for(vector<int>::iterator it = Edge[top].begin(); it != Edge[top].end(); ++it) {
                if(dis[*it] > dis[top] + 1) {
                    pre[*it].push_back(top);
                    dis[*it] = dis[top] + 1;
                    Q.push(*it);
                } else if(dis[*it] == dis[top] + 1) {
                    pre[*it].push_back(top);
                }
            }
        }
        
        ans.clear();
        temp.clear();
        dfs(end);
        for(int i = 0; i < (int)ans.size(); ++i) reverse(ans[i].begin(), ans[i].end());
        return ans;
    }
};
