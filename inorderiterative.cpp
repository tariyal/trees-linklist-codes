vector<int> inorderTraversal(TreeNode *head) {
    stack<TreeNode*> q;
    vector<int> ans ;
    TreeNode* temp;
    int done=1;
    while(done)
    {
        if(head!=NULL)
        {
            q.push(head);
            head=head->left;
        }
        else
        {
            if(q.size()>0)
            {
                temp =q.top(); 
                q.pop();
                ans.push_back(temp->val);
                head = temp->right;
            }
            else
                done=0;
        }
    }
    return ans;
        
    }
