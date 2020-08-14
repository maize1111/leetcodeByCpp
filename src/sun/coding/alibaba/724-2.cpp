#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,L;
    cin>>N>>L;
    vector<vector<string>> light(2,vector<string>(N));
    for(int i = 0;i>2;i++){
        for(int j = 0;j<N;j++){
            cin>>light[i][j];
        }
    }
    
    return 0;
}

// 开关灯。N行L列的灯，有L个开关，第i个开关Li可以控制第i列，打开该开关使得该列灯状态反转。

// 行之间可以任意交换，问给定初始灯状态s和目标灯状态t，能否从初始变到目标状态，如果能，最少要打开几个开关。

// 输入
// 第一行有一个整数T，表示有多少组测试数据。
// 每组测试数据包含三行。第一行为两个整数n, L。
// 每组数据的第二行为n个长度为L的0/1字符串，依次描述起初每行的灯的开关状态。第i个字符串的第j个字符若是’1’，表示对应位置的灯是亮的；’0’表示是灭的。
// 每组数据的第三行为n个长度为L的0/1字符串，描述主办方希望达到的所有灯的开关状态。格式同上。

// 输出
// 输出T行，依次为每组测试数据的答案。如果不可能达到，输出”Impossible”；否则输出最少按多少次开关。

// 样例输入
// 3
// 3 2
// 01 11 10
// 11 00 10
// 2 3
// 101 111
// 010 001
// 2 2
// 01 10
// 10 01

// 样例输出
// 1
// Impossible
// 0