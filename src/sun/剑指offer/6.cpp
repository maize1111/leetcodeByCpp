#include <bits/stdc++.h>
using namespace std;
//从尾到头打印链表
/*
输入：head = [1,3,2]
输出：[2,3,1]
*/
vector<int> res;
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
//翻转链表
ListNode *reverselist(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *node = reverselist(head->next);
    head->next->next = head;
    head->next = NULL;
    return node;
}
vector<int> reversePrint(ListNode *head)
{
    
    //解法1：反转链表法，会改变原本的链表结构
    // head = reverselist(head);
    // while (head != NULL)
    // {
    //     res.push_back(head->val);
    //     head = head->next;
    // }
    //利用栈的先入后出特性进行倒序打印
    // stack<ListNode *> s;
    // ListNode *node = head;
    // while (node != NULL)
    // {
    //     s.push(node);
    //     node = node->next;
    // }
    // while (!s.empty())
    // {
    //     res.push_back(s.top()->val);
    //     s.pop();
    // }
    //解法3：递归,需要考虑递归深度
    if (head == NULL)
        return res;
    res = reversePrint(head->next);
    res.push_back(head->val);

    return res;
}
int main()
{
    vector<int> input = {1, 3, 2};
    ListNode *head = VectorToListNode(input);
    vector<int> res;
    res = reversePrint(head);
    for (auto r : res)
    {
        cout << r << endl;
    }
    return 0;
}