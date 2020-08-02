#include <bits/stdc++.h>
using namespace std;
//删除链表的节点
//需要注意链表长度为1，和需要删除尾节点的情况
/*
输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
*/
//链表数据结构
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//vector转链表
ListNode *VectorToListNode(vector<int> &list)
{
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item : list)
    {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}
ListNode *deleteNode(ListNode *head, int val)
{
    if (head->val == val)
        return head->next;
    ListNode *fast = head;
    ListNode *slow = new ListNode(NULL);
    slow->next = head;
    while (fast->val != val)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = fast->next;
    return head;
}
int main()
{
    vector<int> input = {4,5,1,9};
    int val = 5;
    ListNode *head = VectorToListNode(input);
    head = deleteNode(head,val);
    
    return 0;
}