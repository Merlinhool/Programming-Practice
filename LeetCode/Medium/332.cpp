class Solution {
public:
    vector<vector<string> > GG;
    vector<vector<int> > G;
    vector<vector<bool> > flag;
    map<string, int> has;
    vector<string> ans;
    vector<int> in, out;
    string idx[20000];
    vector<string> findItinerary(vector<pair<string, string>> tic) {
        int n = 0;
        has.clear();
        for(int i = 0; i < (int)tic.size(); ++i) {
            if(has.find(tic[i].first) == has.end()) has[tic[i].first] = n++;
            if(has.find(tic[i].second) == has.end()) has[tic[i].second] = n++;
        }
        for(map<string,int>::iterator it = has.begin(); it != has.end(); ++it) {
            idx[it->second] = it->first;
        }
        
        GG.resize(n);
        G.resize(n);
        flag.resize(n);
        in.resize(n, 0);
        out.resize(n, 0);
        for(int i = 0; i < (int)tic.size(); ++i) {
            GG[has[tic[i].first]].push_back(tic[i].second);
        }
        for(int i = 0; i < n; ++i) {
            sort(GG[i].begin(), GG[i].end());
            
            out[i] = GG[i].size();
            flag[i].resize((int)GG[i].size());
            for(int j = 0; j < (int)GG[i].size(); ++j) {
                G[i].push_back(has[GG[i][j]]);
                ++in[has[GG[i][j]]];
                flag[i][j] = 0;
            }
        }
        
        ans.clear();
        dfs(has["JFK"]);
        ans.push_back("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
    void dfs(int x){
        for(int i = 0; i < (int)G[x].size(); ++i) if(!flag[x][i]){
            
            if(in[x] > 1 && in[G[x][i]] != out[G[x][i]] && in[G[x][i]] != (out[G[x][i]] + 1)) continue;
            
            flag[x][i] = true;
            --out[x]; --in[G[x][i]];
            dfs(G[x][i]);
            ans.push_back(idx[G[x][i]]);
        }
    }
};
