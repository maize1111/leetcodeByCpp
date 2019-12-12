#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *p = head;
    if (p == nullptr)
    {
        return head;
    }
    ListNode *q = nullptr;
    while (p)
    {
        if (p->val == val)
        {
            p = p->next;
            if (q == nullptr)
            {
                head = p;
            }
            else
            {
                q->next = p;
            }
        }
        else
        {
            q = p;
            p = p->next;
        }
    }

    return head;
}
