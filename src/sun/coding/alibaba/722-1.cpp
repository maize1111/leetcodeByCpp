#include <bits/stdc++.h>
using namespace std;
//输入n，求[1,n]的排列组合个数，其中相邻的数字之差的绝对值不能等于1
//使用回溯
//可能会超时
//超过10 计算时间就有点多了
//done

int res = 0;
void backtrack(int num, vector<int> &track)
{
    if (track.size() == num)
    {
        res++;
        return;
    }
    for (int i = 1; i <= num; i++)
    {
        if(track.size()>0){
            if(abs(track[track.size()-1]-i)==1){
                continue;
            }
        }
        //这一步耗时，可以使用visited记录数字的使用情况，会减少时间复杂度
        vector<int>::iterator it;
        it = find(track.begin(), track.end(), i);
        if (it != track.end())
        {
            continue;
        }

        track.push_back(i);
        backtrack(num, track);
        track.pop_back();
    }
}
int main()
{
    int N;
    cin >> N;
    vector<int> track;
    backtrack(N, track);
    cout << res << endl;
    return 0;
}