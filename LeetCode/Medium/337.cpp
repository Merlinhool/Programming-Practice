/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
        public:
                int rob(TreeNode* root) {
                        return dfs(root).second;
                }
                pair<int,int> dfs(TreeNode*r) {
                        if(r == NULL) return make_pair(0,0);
                        pair<int,int> ls = dfs(r->left);
                        pair<int,int> rs = dfs(r->right);

                        pair<int,int> res = make_pair(0,0);
                        res.first = max(res.first, ls.second + rs.second);
                        res.second = max(res.second, r->val + ls.first + rs.first);
                        res.second = max(res.first, res.second);
                        return res;
                }
};

