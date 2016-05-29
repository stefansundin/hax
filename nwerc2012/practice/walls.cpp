// problem med testfall 8

#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000

double dist(double x1,double y1,double x2,double y2) {
	return hypot(x1-x2, y1-y2);
}

int sq(int x) {
	return x*x;
}

int main() {
	int l,w,n,r;
	scanf("%d %d %d %d", &l,&w,&n,&r);
	//r += 1e-9;

	vi coverage;
	while (n--) {
		int x,y;
		scanf("%d %d", &x,&y);

		bool left,top,right,bottom;
		left=top=right=bottom=false;
		/*
		if (hypot((-l/2.) - x, (0)-y) <= r+1e-9) left=true;
		if (hypot((l/2.) - x, (0)-y) <= r+1e-9) right=true;
		if (hypot((0) - x, (-w/2.)-y) <= r+1e-9) bottom=true;
		if (hypot((0) - x, (w/2.)-y) <= r+1e-9) top=true;
		*/

		if (sq(2*x-l)+sq(2*y) <= sq(2)*r*r) left=true;
		if (sq(2*x+l)+sq(2*y) <= sq(2)*r*r) right=true;
		if (sq(2*x)+sq(2*y-w) <= sq(2)*r*r) bottom=true;
		if (sq(2*x)+sq(2*y+w) <= sq(2)*r*r) top=true;

		/*
		if (dist(x,y,l/2.0,0)  <= r+1e-9) right=true;
		if (dist(x,y,0,-w/2.0) <= r+1e-9) bottom=true;
		if (dist(x,y,0,w/2.0)  <= r+1e-9) top=true;
		*/
		/*
		printf("%f < %d: %d\n", dist(x,y,-l/2.0,0), r, left);
		printf("%f < %d: %d\n", dist(x,y,l/2.0,0),  r, right);
		printf("%f < %d: %d\n", dist(x,y,0,-w/2.0), r, bottom);
		printf("%f < %d: %d\n", dist(x,y,0,w/2.0),  r, top);
		printf("\n");
		*/

		int mask = (left?(1<<3):0) | (right?(1<<2):0) | (bottom?(1<<1):0) | (top?(1<<0):0); // left|right|bottom|top
		if (!mask) continue;

		bool found = false;
		for (int i=0; i < coverage.size(); i++) {
			if ((mask&coverage[i]) == mask) {
				// (0001 & 0101) == 0001, skip
				found = true;
				break;
			}
			if ((mask&coverage[i]) == coverage[i] && mask != coverage[i]) {
				// (0111 & 0101) == 0101 && 0111 != 0101, replace
				coverage.erase(coverage.begin()+i);
				break;
			}
		}
		if (found) continue;

		coverage.push_back(mask);
	}

	int best=INF, num=0;
	sort(coverage.begin(), coverage.end());
	do {
		int mask = 0;
		for (int i=0; i < coverage.size(); i++) {
			//printf("%d ", coverage[i]);
			mask |= coverage[i];
			num++;
			if (mask == 0b1111) {
				best = min(best,num);
				break;
			}
		}
		//printf("\n");
	} while (next_permutation(coverage.begin(), coverage.end()));

	if (best < INF) {
		printf("%d\n", best);
	}
	else {
		printf("Impossible\n");
	}
}
