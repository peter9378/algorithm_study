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
		string sum = "";
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
			sum += (char)((a + b + up) % 10 + '0');
			c = (a + b + up) / 10;
		}
		if (c) sum += "1";

		ListNode *result = nullptr, *temp = nullptr;
		for (auto s : sum) {
			ListNode* current = new ListNode(s - '0');
			if (!result) result = current;
			if (temp) temp->next = current;
			temp = current;
		}

		return result;
	}
};