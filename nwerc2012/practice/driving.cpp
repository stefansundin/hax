// ncpc2010
// stefan

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,p;
	scanf("%d %d", &n,&p);
	
	vector<int> cars;
	while (n--) {
		int d;
		scanf("%d", &d);
		cars.push_back(d);
	}
	#define INF 1000000000
	int res=0;
	sort(cars.begin(), cars.end());
	for (int i=0; i < cars.size(); i++) {
		int x = p*(i+1)-(cars[i]-cars[0]);
		res = max(res,x);
	}
	printf("%d\n", res);
}
