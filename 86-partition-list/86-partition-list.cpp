/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* X=head;
        ListNode* prevX=NULL;
        
        while(X && X->val<x){
            prevX=X;
            X=X->next;
        }
        if(!X) return head;
        
        ListNode* prev=X;
        ListNode* temp=X->next;
        
        while(temp){
            if(temp->val<x){
                ListNode* node= new ListNode(temp->val);
                node->next=X;
                
                if(prevX) 
                    prevX->next=node;
                else {
                    node->next=head;
                    head=node;
                }
                
                prevX=node;
                prev->next=temp->next;
            }
            else
                 prev=temp;
            
            temp = prev->next;
        }
        
        return head;
    }
};