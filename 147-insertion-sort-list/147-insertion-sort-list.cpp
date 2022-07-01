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
 ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode *runner;
        ListNode *curr = head->next;

        while (curr) {
            runner = head;

            while (runner && runner != curr) {
                
                if (runner->val > curr->val) {
                    int temp = runner->val;
                    runner->val = curr->val;
                    curr->val = temp;
                }

                runner = runner->next;
            }

            curr = curr->next;
        }

        return head;
    }
};