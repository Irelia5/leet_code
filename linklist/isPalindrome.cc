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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = nullptr;
        ListNode* p = nullptr;
        while (fast && slow && fast->next) {
            p = slow;
            fast = fast->next->next;
            slow = slow->next;

            p->next = pre;
            pre = p;
        }
        if (fast) slow = slow->next;
        while (p) {
            if (p->val != slow->val) return false;
            p = p->next;
            slow = slow->next;
        }
        return true;
    }
};