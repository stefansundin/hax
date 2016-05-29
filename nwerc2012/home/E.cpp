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
	int n,i;
	ll s;
	while (scanf("%d",&n) != EOF) {
		s = n +1 ;

		for (i=2;i<=n/2.0;i++){
			int x = 2*(i-1)-1;
			s+=n*x/i;
		}
		printf("%lld\n", s);
	}
	
	return 0;
}
