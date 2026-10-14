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
void dfs(TreeNode* node , int depth , int& maxDepth) {
    if(node == NULL) return;
    maxDepth = max(maxDepth , depth);
    dfs(node->left , depth + 1 , maxDepth);
    dfs(node->right , depth + 1 , maxDepth);
}
    int maxDepth(TreeNode* root) {
        int depth = 1 , maxDepth = 0;
        dfs(root , depth , maxDepth);
        return maxDepth;


        //Breadth First Search
        // if(root == NULL) return 0;
        // queue<TreeNode*> q;
        // q.push(root);
        // int depth = 0;
        
        // while(!q.empty()) {
        //     int size = q.size();
        //     depth++;
        //     for(int i=0; i<size; i++) {
        //         TreeNode* node = q.front();
        //         q.pop();
        //         if(node->left != NULL ) q.push(node->left);
        //         if(node->right != NULL) q.push(node->right);
        //     }
        // }
        // return depth;    
    }
};