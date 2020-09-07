/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* reverseList2(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* cur = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return cur;
    }
};