#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *cur = &dummy, *nex = &dummy, *pre = &dummy;

        int count = 0;
        while (cur->next) {
            cur = cur->next;
            count++;
        }

        while (count >= k) {
            cur = pre->next;
            nex = cur->next;

            for (int i = 1; i < k; i++) {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }

            pre = cur;
            count -= k;
        }
        return dummy.next;
    }
};

/*
Example:
Input: 1->2->3->4->5, k = 2
Output: 2->1->4->3->5
*/
