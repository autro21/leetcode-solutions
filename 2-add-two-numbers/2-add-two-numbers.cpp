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
	ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *root = new ListNode(0);
		ListNode *curr = root;
		int carry = 0;
		while (l1 || l2) {

			int vl = carry;
			if (l1)
				vl += l1->val, l1 = l1->next;
			if (l2)
				vl += l2->val, l2 = l2->next;
			if(vl > 9)
				carry = 1;
			else{
				carry = 0;
			}
			//cerr << vl << " " << carry << endl;
			curr->next = new ListNode(vl % 10);
			curr = curr->next;
		}

		if (carry) {
			curr->next = new ListNode(carry);
		}

		return root->next;
	}
};