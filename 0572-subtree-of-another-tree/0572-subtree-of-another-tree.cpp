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
bool same(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;

    if(p->val != q->val) return false;

    return same(p->left, q->left) &&
           same(p->right, q->right);
}
bool dfs(TreeNode* p, TreeNode* q) {
    // if(p == NULL && q == NULL) return true;
    // if(p != NULL && q != NULL) {
    //     if(p->val == q->val) {
    //         if(dfs(p->left , q->left) == false) return false;
    //         if(dfs(p->right , q->right) == false) return false;
    //     }
    //     else{
    //         if(dfs(p->left , q) == false) return false;
    //     }
    // }
    // else return false;
    // return true;


    if(p == NULL) return false;

    if(same(p, q)) return true;

    return dfs(p->left, q) || dfs(p->right, q);
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root , subRoot);    
    }
};