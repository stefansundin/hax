#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define LSOne(S) (S & (-S))

int main() {
	int x,n;
	while (scanf("%d %d",&x,&n) != EOF) {
		x *= 10000000;

		//printf("hej0!\n"); fflush(stdout);

		list<int> got;
		vector<int> l; l.assign(100000100, 0);
		//int l[100001];
		/*for (int i=0; i < 100000000; i++) {
			l[i] = false;
		}*/
		//memset(l,-1,sizeof l);
		 //got.assign(10, n);
		//got.push_back(100);

		//printf("hej1!\n");

		for (int i=0; i < n; i++) {
			int y;
			scanf("%d", &y);
			//printf("read %d\n",y); fflush(stdout);
			l[y]++;
			got.push_back(y);

		}

		//printf("hej!\n");

		int l1=-1,l2=-1,diff=-1;
		for (list<int>::iterator it=got.begin(); it != got.end(); it++) {
			int y = *it;
			//printf("loop %d\n", y);
			if ((x>y && x-y <= 100000000 && l[x-y] > 0)) {
				if (x-y == y && l[x-y] == 1) continue;
				if (diff == -1) {
					l1=min(y,x-y);
					l2=max(y,x-y);
					diff = abs(l1-l2);
				}
				else {
					int t1=min(y,x-y),t2=max(y,x-y);
					int tdiff = abs(t1-t2);
					if (tdiff > diff) {
						l1 = t1;
						l2 = t2;
						diff = tdiff;
					}
				}
			}
		}

		if (diff == -1) {
			printf("danger\n");
		}
		else {
			printf("yes %d %d\n", l1,l2);
		}
	}

	return 0;
}
