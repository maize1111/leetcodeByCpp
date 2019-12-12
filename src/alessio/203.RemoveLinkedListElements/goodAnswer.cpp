#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {

        ListNode *dummyHead = new ListNode(-1);

        dummyHead->next = head;

        ListNode *prev = dummyHead;

        while (prev->next)
        {
            if (prev->next->val == val)
            {
                ListNode *deletenode = prev->next;
                prev->next = prev->next->next;
            }
            else
            {
                prev = prev->next;
            }
        }

        return dummyHead->next;
    }
};
