/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
     RandomListNode * createnode(int data)
      {
	    RandomListNode* temp = (RandomListNode* )malloc(sizeof(RandomListNode));
	    temp->label = data;
	    temp->next = NULL;
	    return temp;
    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL)
            return NULL;
        RandomListNode *var = head,*temp;        
        while(head!=NULL)
        {
            temp= head->next;
            head->next=createnode(head->label);
            head->next->next=temp;
            head = temp;
        }
        head = var;
        while(head!=NULL)
        {
            if(head->random!=NULL)
                head->next->random = head->random->next;
            else
                head->next->random = NULL;
            head = head->next->next;
        }
        head = var;
        temp = head->next;
        var = temp;
        while(head!=NULL)
        {
            head->next = head->next->next;
            if(temp->next!=NULL)
            {
                temp->next = temp->next->next;
                temp = temp->next;
            }
            head = head->next;
                
        }
        return var;
        
    }
}; 
