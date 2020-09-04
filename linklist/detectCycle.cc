/**
 * 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        bool is_cycle = false;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (!fast) return nullptr;
            if (slow == fast) {
                is_cycle = true;
                break;
            }
        }
        if (!is_cycle) return nullptr;
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};