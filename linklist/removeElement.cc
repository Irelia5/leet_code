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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;
        ListNode* add_head = new ListNode(-1);
        add_head->next = head;
        ListNode* pre = add_head;
        ListNode* cur = head;
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                ListNode* temp = cur;
                cur = cur->next;
                delete temp;
            } else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        ListNode* temp = add_head->next;
        delete add_head;
        return temp;
    }
};