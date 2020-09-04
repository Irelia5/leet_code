/**
 * 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode* cur_a = headA;
        ListNode* cur_b = headB;
        while (cur_a != cur_b) {
            cur_a = cur_a == nullptr ? headB : cur_a->next;
            cur_b = cur_b == nullptr ? headA : cur_b->next;
        }
        return cur_b;
    }
};