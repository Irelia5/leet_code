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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            } else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        ListNode* list = head->next;
        delete head;
        return list;
    }

    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        else if (!l2) return l1;
        else if (l1->val < l2->val) {
            l1->next = mergeTwoLists2(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists2(l1, l2->next);
            return l2;
        }
    }
};