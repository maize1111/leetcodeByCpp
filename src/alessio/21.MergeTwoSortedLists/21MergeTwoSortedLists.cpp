#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    else if (l2 == NULL)
    {
        return l1;
    }
    else if (l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l2->next, l1);
        return l2;
    }
}

int main()
{
    return 0;
}