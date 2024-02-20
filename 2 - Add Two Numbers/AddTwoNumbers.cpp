class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        ListNode *node = new ListNode();
        ListNode *tail = node;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            tail = tail->next;
        }
        return node->next;
    }
};