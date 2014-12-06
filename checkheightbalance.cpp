/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    bool Balance(TreeNode *root,int* height) {
        if(root==NULL)
        {
            *height=0;
            return 1;
        }
        int l,r,lh,rh;
        l = Balance(root->left,&lh);
        r = Balance(root->right,&rh);
        *height = (lh>rh?lh:rh)+1;
        if(abs(lh-rh)>1)
            return 0;
        else
            return l&&r;
    }
    bool isBalanced(TreeNode *root)
    {
        int h=0;
        return Balance(root,&h);
    }
};
