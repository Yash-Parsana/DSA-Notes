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
ListNode* sortList(ListNode* head) {
        ListNode* p1 = new ListNode(-1);
        ListNode* p2 = p1;
        ListNode* l1 = head;
        vector<int>vec;
        while(l1)
        {
            vec.push_back(l1->val);
            l1= l1->next;
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++)
        {
            ListNode* q = new ListNode(vec[i]);
            p2->next = q;
            p2 = p2->next;
        }
        return p1->next;
    }
};