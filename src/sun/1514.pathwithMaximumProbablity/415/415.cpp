#include <bits/stdc++.h>
using namespace std;
string addStrings(string num1, string num2)
{
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    int n1 = 0;
    int n2 = 0;
    string res = "";
    int n = 0;
    while (i >= 0 || j >= 0)
    {
        if (i < 0)
        {
            n1 = 0;
        }
        else
        {
            n1 = num1[i] - '0';
            i--;
        }
        if (j < 0)
        {
            n2 = 0;
        }
        else
        {
            n2 = num2[j] - '0';
            j--;
        }
        n = n1 + n2 + carry;
        carry = n / 10;
        n = n % 10;
        res = string(1, '0' + n) + res;
    }
    if (carry != 0)
    {
        res = string(1, '0' + carry) + res;
    }
    return res;
}
int main()
{
    string num1 = "0";
    string num2 = "0";
    string res = addStrings(num1,num2);
    cout<<res<<endl;
    
    return 0;
}