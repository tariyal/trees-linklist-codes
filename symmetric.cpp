class Solution {
public:
    bool check(TreeNode* a, TreeNode* b)
    {
        if(a==NULL && b==NULL)
            return 1;
        else if(a!=NULL && b!=NULL)
             return (a->val==b->val && check(a->left,b->right) && check(a->right,b->left));
        return false;
        
    }
    bool isSymmetric(TreeNode *root) {
     if(root==NULL)
        return true;
     return check(root->left,root->right);
    }
};
