#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
vector< pair<int, ii> > edgelist;
typedef vector<int> vi;

vi pset;
void initSet(int N) {
	pset.assign(N, 0);
	for (int i = 0; i < N; i++) {
		pset[i] = i;
	}
}
int findset(int i) {
	return (pset[i] == i) ? i : (pset[i] = findset(pset[i]));
}
bool isSameSet(int i, int j) {
	return findset(i) == findset(j);
}
void unionSet(int i, int j) {
	pset[findset(i)] = findset(j);
}

int main() {
	int m,n,a,b,weight;
	while (true) {
		int total = 0;
		scanf("%d %d\n", &m, &n);
		if (m == 0 && n == 0) return 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d\n", &a, &b, &weight);
			total += weight;
			edgelist.push_back(make_pair(weight, ii(a, b)));
		}
		sort(edgelist.begin(), edgelist.end());
		
		int mst_cost = 0; initSet(m);
		for (int i = 0; i < n; i++) {
			pair<int, ii> front = edgelist[i];
			if (!isSameSet(front.second.first, front.second.second)) {
				mst_cost += front.first;
				unionSet(front.second.first, front.second.second);
			}
		}
		printf("%d\n", total - mst_cost);
		edgelist.clear();
	}
	return 0;
}
