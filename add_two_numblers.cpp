/*
 * @author:      Swing
 * @create:      2019-12-21 15:25
 * @description: You are given two non-empty linked lists representing two non-negative integers. The digits are stored
 * in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 */



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int sum = 0;
        ListNode *l3 = NULL;
        ListNode **node = &l3;

        while (l1 != NULL || l2 != NULL || sum > 0) {
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            (*node) = new ListNode(sum % 10);
            sum /= 10;
            node = &((*node)->next);
        }

        return l3;

    }

    void test() {
        ListNode *l1 = new ListNode(2);
        l1->next = new ListNode(4);
        l1->next->next = new ListNode(3);

        ListNode *l2 = new ListNode(5);
        l2->next = new ListNode(6);
        l2->next->next = new ListNode(4);

        ListNode *l3 = addTwoNumbers(l1, l2);

        std::cout << l3->val;
        l3 = l3->next;
        std::cout << l3->val;
        l3 = l3->next;
        std::cout << l3->val << std::endl;
    }
};
