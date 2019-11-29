#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s)
{
    // 使用map会大幅增加内存和时间
    unordered_map<char, int> dic{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    int result = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0 || (dic[s[i]] <= dic[s[i - 1]]))
        {
            result += dic[s[i]];
        }
        else
        {
            result += dic[s[i]] - 2 * dic[s[i - 1]];
        }
    }

    return result;
}

// Test Function
int main()
{
    string input;

    while (cin >> input)
    {
        cout << romanToInt(input) << endl;
    }

    return 0;
}
