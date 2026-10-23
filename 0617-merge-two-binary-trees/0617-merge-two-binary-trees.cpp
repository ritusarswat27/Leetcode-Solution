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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return NULL;
        else if(root1 == NULL) return root2;
        else if(root2 == NULL) return root1;

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.push(root1);
        q2.push(root2);


        while(!q1.empty() && !q2.empty()) {
            TreeNode* node1 = q1.front();
            q1.pop();

            TreeNode* node2 = q2.front();
            q2.pop();

            node1->val = node1->val + node2->val;

            // if(node->left != NULL) q.push(node->left);
            // if(node->right != NULL) q.push(node->right);


            if (node1->left == NULL) node1->left = node2->left;
            else if (node2->left != NULL) {
                q1.push(node1->left);
                q2.push(node2->left);
            }

            // Merge right children
            if (node1->right == NULL) node1->right = node2->right;
            else if (node2->right != NULL) {
                q1.push(node1->right);
                q2.push(node2->right);
            }
        }
        return root1;    
    }
};