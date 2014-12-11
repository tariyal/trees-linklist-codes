class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int a=0;
        return build(preorder,inorder,0,preorder.size()-1,a);
    }
    TreeNode* build(vector<int> &pre,vector <int> &in, int start,int end,int &a)
    {
        if(end<start)
            return NULL;
        TreeNode* root = new TreeNode(pre[a]);
         a++;
        if(start==end)
            return root;
        int i;
        for(i=start;i<=end;i++)
        {
            if(in[i]==root->val)
                break;
        }
       
        root->left =  build(pre,in,start,i-1,a);
        root->right = build(pre,in,i+1,end,a);
        return root;
    }
    
};
