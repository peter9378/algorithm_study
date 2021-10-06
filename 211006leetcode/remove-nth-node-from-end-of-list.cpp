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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return nullptr;

        ListNode temp(-1);
        temp.next = head;

        ListNode* slow = &temp;
        ListNode* fast = &temp;

        for (int i = 0; i < n; i++)
            fast = fast->next;

        while (fast->next) 
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* target = slow->next;
        slow->next = slow->next->next;
        
        delete target;
        
        return temp.next;
    }
};
