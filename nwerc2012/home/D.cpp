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
	int N;
	while (scanf("%d",&N) != EOF) {
		bitset<7*4> seg;
		for (int i=0; i < N; i++) {
			char in[4]; scanf(" %c%c:%c%c",&in[0],&in[1],&in[2],&in[3]);
			seg[
			printf("in: %c%c%c%c\n",in[0],in[1],in[2],in[3]);
		}

	}

	return 0;
}
