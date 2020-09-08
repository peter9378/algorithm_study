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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int a, b, c = 0;
		ListNode *result = nullptr, *temp = nullptr;

		while (l1 || l2) {
			int up = c;
			a = b = c = 0;
			if (l1) {
				a = l1->val;
				l1 = l1->next;
			}
			if (l2) {
				b = l2->val;
				l2 = l2->next;
			}
			ListNode* current = new ListNode((a + b + up) % 10);
			if (!result) result = current;
			if (temp) temp->next = current;
			temp = current;
			c = (a + b + up) / 10;
		}

		if (c) {
			ListNode* current = new ListNode(1);
			if (!result) result = current;
			if (temp) temp->next = current;
			temp = current;
		}
		return result;
	}
};