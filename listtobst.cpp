/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* middle(ListNode* head)
    {
        if(head==NULL)
            return NULL;
        ListNode* slow = head;
        while(head!=NULL)
        {
            if(head->next!=NULL)
                head = head->next->next;
            else 
                break;
             slow = slow->next;
        }
        return slow;
    }
    
    TreeNode *sortedListToBST(ListNode *k) 
    {
        ListNode* head= k;
        ListNode* temp =   middle(head);
        if(head ==NULL || temp ==NULL )
            return NULL;
        TreeNode* node  = (TreeNode*)malloc(sizeof(TreeNode));
        node->val = temp->val;
        if(head==temp)
        {
            node->left = NULL;
        }
        else
        {
            while(head->next!=temp)
                head = head->next;
            head->next = NULL;
            node->left = sortedListToBST(k);
        }
        node->right = sortedListToBST(temp->next);
        return node;
    }
};
