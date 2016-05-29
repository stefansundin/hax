#include <cstdio>
#include <algorithm>

using namespace std;

bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
	if (a.first == b.first) return a.second.first < b.second.first;
	return a.first > b.first;
}

bool cmp2(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
	return a.second.first < b.second.first;
}

int main() {
	int tests;
	
	scanf("%d", &tests);
	
	while (tests--) {
		int p, n;
		
		scanf("%d %d", &p, &n);
		
		vector<pair<int, pair<int, int> > > pers;
		int sum = 0;
		for (int i=0; i<n; i++) {
			int a;
			scanf("%d", &a);
			pers.push_back(pair<int, pair<int, int> >(a, pair<int, int>(i, 0)));
			sum += a;
		}
		
		if (sum < p) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		
		sort(pers.begin(), pers.end(), cmp);
		
		int avg = p/n;
		int rem = p % n;
		int full = 9999999;
		
		for (int i=0; i<n; i++) {
			if (pers[i].first >= avg) {
				pers[i].first -= avg;
				pers[i].second.second += avg;
				p -= avg;
			} else {
				pers[i].second.second += pers[i].first;
				p -= pers[i].first;
				pers[i].first = 0;
				full = min(full, i);
			}
		}
		
		while (p > 0) {
			for (int i=0; i<full && i<n; i++) {
				if (pers[i].first > 0) {
					pers[i].first--;
					pers[i].second.second++;
					p--;
					if (p <= 0) break;
				}
			}
		}
		
		sort(pers.begin(), pers.end(), cmp2);
		
		for (int i=0; i<n; i++) {
			printf("%d", pers[i].second.second);
			if(i+1<n) {
				printf(" ");
			}
		}
		printf("\n");
		
	}

	return 0;
}