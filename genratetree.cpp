class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return gentree(1,n);
    }
    vector<TreeNode*> gentree(int start,int end)
    {
        vector<TreeNode*> ans;
        if(start>end)
        {
            ans.push_back(NULL);
            return ans;
        }
        int mid=start;
        vector<TreeNode*> lefttree;
        vector<TreeNode*> righttree;
        while(mid<=end)
        {
            lefttree = gentree(start,mid-1);
            righttree = gentree(mid+1,end);
            for(int i=0;i<lefttree.size();i++)
            {
                for(int j=0;j<righttree.size();j++)
                {
                    TreeNode* root=(TreeNode *)(malloc(sizeof(TreeNode*)));
                    root->val = mid;
                    root->left = lefttree[i];
                    root->right = righttree[j];
                    ans.push_back(root);
                }
            }
            mid++;
        }
        return ans;
    }
    
};
