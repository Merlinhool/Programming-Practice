class Solution {
        public:
                string::iterator it;
                string s;
                bool isValidSerialization(string preorder) {
                        s = preorder;
                        s.push_back(',');
                        it = s.begin();
                        return dfs() && (increase(), it == s.end());
                }
                bool dfs(){
                        if(it == s.end()) return false;
                        if(*it == '#') return true;

                        increase();
                        dfs();
                        if(it == s.end()) return false;
                        increase();
                        return dfs();
                }
                void increase(){
                        while(*it != ',') ++it;
                        ++it;
                }
};
