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
 ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head, *prev = NULL, *back = NULL;
        bool f = false;
        while(curr){
            if(!f)
                back = prev;
            prev=curr;
            curr = curr->next;
            f=false;
            while(curr && curr->val==prev->val){
                curr=curr->next;
                f=true;
            }
            if(!back && f){
                head = curr;
                prev=curr;
            }
            if(back && f){
                back->next = curr;
                prev=curr;
            }
        }
        return head;
    }
};