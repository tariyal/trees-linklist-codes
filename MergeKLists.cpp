class Solution {
public:
    struct ComparisonClass {
    bool operator() (ListNode* a, ListNode* b) {
        return a->val > b->val ;
        //comparison code here
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*,vector<ListNode*> ,ComparisonClass> q; 
        if(lists.size()==0)
            return NULL;
        ListNode *head,*var,*k;
        head = (ListNode*)malloc(sizeof(ListNode));
        head->next=NULL;
        var = head;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL)
                q.push(lists[i]);
        }    
        while(!q.empty())
        {
            k = q.top();
            q.pop();
            head->next=k;
            head = head->next;
            if(k->next != NULL)
                q.push(k->next);
        }
        head->next=NULL;
        return var->next;
    }
};
