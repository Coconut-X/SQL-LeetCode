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

    bool isSameTree(TreeNode*p, TreeNode*q)
    {
        if((p and !q) or (!p and q))
            return false;

        if(!q and !p)
            return true; //if both reach end at same time

        if(p->val!=q->val)
            return false;


        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right);
    }

    bool traverseRoot(TreeNode*root, TreeNode*subRoot)
    {   
        if(!root)
            return false;

        if(root->val==subRoot->val and isSameTree(root,subRoot))
            return true;

        return traverseRoot(root->left, subRoot) || traverseRoot(root->right, subRoot);

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        return traverseRoot(root, subRoot);
        
    }
};