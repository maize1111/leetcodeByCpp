#include<bits/stdc++.h>
using namespace std;
//字节提前批面试
//已知地铁线路图，问两站点间的最短路径如何选择
//面试中脑子一团浆糊，没有和面试官确认如何定义最短路径
//参考pat 1131 
//找出经过站点数最少的路径，路径不唯一则选择中转次数最少的路径
//input 
// 4
// 7 1 2 3 4 5 6 7
// 9 8 7 10 11 12 13 4 15 16
// 13 17 18 9 20 2 21 15 23 6 24 25 26
// 4 6 27 28 29
//start 20 end 5
//https://blog.csdn.net/a1552100455/article/details/102941536?utm_medium=distribute.pc_relevant.none-task-blog-baidujs-6&spm=1001.2101.3001.4242
vector<vector<int> > gra(100,vector<int>());
map<int, int> line;
int visited[10000];
int start, end1, minsize = INT_MAX,mincnt = INT_MAX;
vector<int> temp, res;
void dfs(int v) {//根据图顺移，每个点必然遍历多次，但要保证本次遍历不能出现环路，所以visited具有本次有效性
	if (v == end1 && temp.size() <= minsize ) {
		int preLine = -1, cnt = 0;
		for (int i = 1; i < temp.size(); i++) {//统计中转站
			if (line[temp[i - 1] * 10000 + temp[i]] != preLine) cnt++;
			preLine = line[temp[i - 1] * 10000 + temp[i]];
		}
		if (temp.size() < minsize) {
			minsize = temp.size();
			mincnt = cnt;
			res = temp;
		}
		else if (temp.size() == minsize && cnt < mincnt) {
			mincnt = cnt;
			res = temp;
		}
		return;
	}
	if (v == end1) return;
	for (int i = 0; i < gra[v].size(); i++) {
		if (visited[gra[v][i]] == 0) {
			visited[gra[v][i]] = 1;
			temp.push_back(gra[v][i]);
			dfs(gra[v][i]);
			temp.pop_back();
			visited[gra[v][i]] = 0;//本次遍历结束，下一条路径有可能还会用到
		}
	}
}
int main() {
	int n, k;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int m, pre, temp;
		scanf("%d %d", &m, &pre);
		for (int j = 1; j < m; j++) {
			scanf("%d", &temp);
			gra[pre].push_back(temp);
			gra[temp].push_back(pre);
			line[pre * 10000 + temp] = line[temp * 10000 + pre] = i;
			pre = temp;
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &start, &end1);
		mincnt =  INT_MAX;
        minsize = INT_MAX;
		visited[start] = 1;
		temp.clear();
		temp.push_back(start);
		dfs(start);
		visited[start] = 0;//不要忘记擦屁股
		printf("%d\n", res.size() - 1);
		int preLine = -1, start = res[0];
		for (int j = 1; j < res.size(); j++) {
			if (line[res[j - 1] * 10000 + res[j]] != preLine) {
				if (preLine != -1) 
					printf("Take Line#%d from %04d to %04d.\n", preLine, start, res[j-1]);
				preLine = line[res[j - 1] * 10000 + res[j]];
				start = res[j - 1];
			}
		}
		printf("Take Line#%d from %04d to %04d.\n", preLine, start, end1);
	}
	return 0;
}
