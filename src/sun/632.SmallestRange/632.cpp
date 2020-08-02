#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val, x, y;
    Node(int v, int x, int y) : val(v), x(x), y(y) {}
    bool operator>(const Node &r) const { return val > r.val; }
};
vector<int> smallestRange(vector<vector<int>> &nums)
{
    int k = nums.size();
    if (k == 1)
    {
        return {nums[0][0], nums[0][0]};

    }
    
    priority_queue<Node, vector<Node>, greater<Node>> q;
    int maxv = INT_MIN, minl = INT_MAX, l, r;
    //maxv更新为各区间开头数字的最大值，并把对应的node压入优先队列
    for (int i = 0; i < k; ++i)
    {
        q.push(Node(nums[i][0], i, 0));
        maxv = max(maxv, nums[i][0]);
    }

    while (q.size() == k)
    {
        Node cur = q.top();
        q.pop();
        //收缩区间长度
        if (maxv - cur.val < minl)
            minl = maxv - cur.val, l = cur.val, r = maxv;

        if (cur.y + 1 < nums[cur.x].size())
        {
            maxv = max(maxv, nums[cur.x][cur.y + 1]);
            q.push(Node(nums[cur.x][cur.y + 1], cur.x, cur.y + 1));
        }
    }

    return {l, r};
}
int main()
{
    vector<vector<int>> nums = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    vector<int> res = smallestRange(nums);
    cout << res[0] << "    " << res[1] << endl;

    return 0;
}