#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AdjList;
vector<vii> MST;
priority_queue< pair<int,ii> > pq;
vi taken;
vi dfs_num;

#define DFS_WHITE -1
#define DFS_BLACK 1
#define INF 1000000000

int process(int vtx) {
	taken[vtx] = 1;
	for (int j=0; j < AdjList[vtx].size(); j++) {
		ii v = AdjList[vtx][j];
		if (!taken[v.first]) pq.push(pair<int,ii>(-v.second,ii(-v.first,vtx)));
	}
}

int prim(int s) {
	int u,v,w;
	process(s);
	while (!pq.empty()) {
		pair<int,ii> front = pq.top(); pq.pop();
		u = -front.second.first, w = -front.first;
		v = front.second.second;
		if (!taken[u]) {
			MST[u].push_back(ii(v,w));
			MST[v].push_back(ii(u,w));
			process(u);
		}
	}
}

int cost(int u, int d) {
	dfs_num[u] = DFS_BLACK;
	if (u == d) return 0;
	for (int j=0; j < (int)MST[u].size(); j++) {
		ii front = MST[u][j];
		int v = front.first;
		int w = front.second;
		if (v == d) return w;
		if (dfs_num[v] == DFS_WHITE) {
			int c = cost(v, d);
			if (c < INF) {
				return max(c,w);
			}
		}
	}
	return INF;
}

int main() {
	for (int n=1; 1; n++) {
		int c,s,q;
		scanf("%d %d %d", &c,&s,&q);
		if (c == 0 && s == 0 && q == 0) break;
		AdjList.assign(c, vii());
		MST.assign(c, vii());
		taken.assign(c, 0);
		
		while (s--) {
			int c1,c2,d;
			scanf("%d %d %d", &c1,&c2,&d);
			c1--; c2--;
			AdjList[c1].push_back(ii(c2,d));
			AdjList[c2].push_back(ii(c1,d));
		}
		
		if (n > 1) printf("\n");
		printf("Case #%d\n", n);
		while (q--) {
			int c1,c2;
			scanf("%d %d", &c1,&c2);
			c1--; c2--;
			if (!taken[c1]) prim(c1);
			if (!taken[c2]) prim(c2);
			
			dfs_num.assign(c, DFS_WHITE);
			int w = cost(c1, c2);
			if (w < INF) {
				printf("%d\n", w);
			}
			else {
				printf("no path\n");
			}
		}
	}
}

