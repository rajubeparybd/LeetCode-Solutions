class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *curr, *prev, *next;

        curr = head;
        prev = nullptr;
        next = head->next;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};