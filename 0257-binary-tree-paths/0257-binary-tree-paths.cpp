/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void dfs(TreeNode* root , vector<string>& ans , string str) {
    if(root == NULL) return;
    str += to_string(root->val);

    if(root->left == NULL && root->right == NULL) {
        ans.push_back(str);
        return;
    }
    str += "->";

    dfs(root->left , ans , str);
    dfs(root->right , ans , str);
}
    vector<string> binaryTreePaths(TreeNode* root) {
        TreeNode* temp = root;
        vector<string> ans;
        string str = "";
        dfs(temp , ans , str);
        return ans;  
    }
};