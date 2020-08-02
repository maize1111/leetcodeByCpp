#include <bits/stdc++.h>
using namespace std;
vector<string> maxNumOfSubstrings(string s)
{
    //贪心
    vector<int> lastTime(26,-1); // 在字符串s上字符'a'-'z'首次出现的位置
    vector<int> firstTime(26,-1); // 在字符串s上字符'a'-'z'最后出现的位置
    vector<int> lt;               // 升序存储所有字符最后出现的位置

    //为上述三个数组赋值
    vector<string> ans;
    for(int i = 0; i < s.size(); i++){
        if(firstTime[s[i]-'a'] == -1) firstTime[s[i]-'a'] = i;
        lastTime[s[i]-'a'] = i;
    }
    for(int i : lastTime){
        if(i != -1){
            lt.push_back(i);
        }
    }
    sort(lt.begin(), lt.end());

    //判断每个lt[i]可以目标子串的终点，如果可以，将该字串加入答案中。
    int last_loc = -1;
    for(int i = 0; i < lt.size(); i++){
        int c = s[lt[i]] - 'a';
        int pre = firstTime[c], k = lt[i];
        while(k > pre){
            if(lastTime[s[k]-'a'] > lt[i] || k <= last_loc) break;
            pre = min(pre, firstTime[s[k--]-'a']);
        }
        if(k == pre){
            ans.push_back(s.substr(pre, lt[i]-pre+1));
            last_loc = lt[i];
        }
    }
    return ans;
}

int main()
{
    string s = "adefaddaccc";
    vector<string> res ;
    res = maxNumOfSubstrings(s);

    return 0;
}

// 输入：s = "adefaddaccc"
// 输出：["e","f","ccc"]
// 解释：下面为所有满足第二个条件的子字符串：
// [
//   "adefaddaccc"
//   "adefadda",
//   "ef",
//   "e",
//   "f",
//   "ccc",
// ]
