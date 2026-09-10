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
int findAverage(TreeNode* root) {
    int sum = 0 , cnt = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cnt++;
        sum += node->val;
        if(node->left != NULL) q.push(node->left);
        if(node->right != NULL) q.push(node->right);    
    }
    return sum / cnt;
}

pair<int , int> dfs(TreeNode* root , int& ans) {
    if(root == NULL) return {0 , 0};

    auto left = dfs(root->left , ans);
    auto right = dfs(root->right , ans);

    int sum = left.first + right.first + root->val;
    int cnt = left.second + right.second + 1;

    if(sum / cnt == root->val) ans++;
    return {sum , cnt};
}

    int averageOfSubtree(TreeNode* root) {
        // int cnt = 0;
        // queue<TreeNode*> q;
        // q.push(root);
        // while(!q.empty()) {
        //     TreeNode* node = q.front();
        //     q.pop();
        //     if(node->left != NULL) q.push(node->left);
        //     if(node->right != NULL) q.push(node->right); 
        //     int ans = findAverage(node);
        //     if(ans == node->val) cnt++;
        // }

        // return cnt;  


        int ans = 0;
        dfs(root , ans);
        return ans;
    }
};