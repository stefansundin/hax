// ncpc2010
// stefan

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int l,d,n;
	vector<int> birds;
	scanf("%d %d %d", &l, &d, &n);

	birds.push_back(6-d);
	birds.push_back(l-6+d);
	while (n--) {
		int b;
		scanf("%d", &b);
		birds.push_back(b);
	}
	sort(birds.begin(), birds.end());

	int num = 0;
	for (int i=1; i < birds.size(); i++) {
		// how many birds between birds[i] and birds[i-1], with at least d apart?
		num += (birds[i]-birds[i-1]-d)/d;
	}

	printf("%d\n", num);
}
