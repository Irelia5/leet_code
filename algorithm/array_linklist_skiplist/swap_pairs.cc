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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* add_head = new ListNode(-1, head);
        ListNode* pre = add_head;
        while (pre->next && pre->next->next) {
            ListNode* left = pre->next;
            ListNode* right = left->next;
            pre->next = right;
            left->next = right->next;
            right->next = left;
            pre = pre->next->next;
        }
        pre = add_head->next;
        delete add_head;
        return pre;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* back = head->next;
        head->next = swapPairs(back->next);
        back->next = head;
        return back;
    }
};