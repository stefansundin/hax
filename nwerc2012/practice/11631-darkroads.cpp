#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AdjList;
vi taken;
priority_queue<ii> pq;

int n,m;

void process(int vtx) {
	taken[vtx] = 1;
	for (int j=0; j < AdjList[vtx].size(); j++) {
		ii v = AdjList[vtx][j];
		if (!taken[v.first]) pq.push(ii(-v.second, -v.first));
}}

int main() {
	while (1) {
		//memset(AdjList, 0, sizeof AdjList);
		//AdjList.assign(m, 0);
		
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0) break;
		AdjList.assign(m, vii());
		
		int total_length = 0;
		while (n--) {
			int x,y,z;
			scanf("%d %d %d", &x, &y, &z);
			AdjList[x].push_back(ii(y,z));
			AdjList[y].push_back(ii(x,z));
			
			total_length += z;
		}
		
		int u,w,mst_cost;
		
		taken.assign(m, 0);
		process(0);
		mst_cost = 0;
		while (!pq.empty()) {
			ii front = pq.top(); pq.pop();
			u = -front.second, w = -front.first;
			if (!taken[u])
				mst_cost += w, process(u);
		}
		
		printf("%d\n", total_length-mst_cost); //fflush(stdout);
	}
}
