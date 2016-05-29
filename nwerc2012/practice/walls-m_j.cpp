#include <stdio.h>
#include <algorithm>
#include <list>

using namespace std;


#include <cmath>


int l, w, n; double r;

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}

bool left = false, right = false, top = false, down = false;

int count(int x, int y) {
	int inc = 0;
	if(!down && dist(x, y, (double)-l/2.0, 0) <= r) {
		inc++;
	}
	
	if(!top && dist(x, y, (double)l/2.0, 0) <= r) {
		inc++;
	}
	
	if(!left && dist(x, y, 0, (double)-w/2.0) <= r) {
		inc++;
	}
	if(!right && dist(x, y, 0, (double)w/2.0) <= r) {
		inc++;
	}
	return inc;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	int i1 = count(a.first, a.second);
	int i2 = count(b.first, b.second);
	
	if(i1!=i2) return i1>i2;
	
	int dist1 = a.first*a.first + a.second*a.second;
	int dist2 = b.first*b.first + b.second*b.second;
	
	return dist1>dist2;
}


int main() {
	scanf("%d %d %d %lf", &l, &w, &n, &r);
	
	list<pair<int, int> > cranes;
	
	int x, y;
	while(n--) {
		scanf("%d %d", &x, &y);
		cranes.push_back(pair<int, int>(x,y));
		//printf("%d %d\n",x,y);
	}
	
	cranes.sort(cmp);
	
	
	int num = 0;
	while(!cranes.empty()) {
		pair<int, int> i = cranes.front();
		
		bool inc = false;
		if(!down && dist(i.first, i.second, (double)-l/2.0, 0) <= r) {
			inc = true;
			down = true;
		}
		
		if(!top && dist(i.first, i.second, (double)l/2.0, 0) <= r) {
			inc = true;
			top = true;
		}
		
		if(!left && dist(i.first, i.second, 0, (double)-w/2.0) <= r) {
			inc = true;
			left = true;
		}
		if(!right && dist(i.first, i.second, 0, (double)w/2.0) <= r) {
			inc = true;
			right = true;
		}
		
		if(inc) num++;
		
		//printf("hej: %d %d %d\n", i.first, i.second, count(i.first, i.second));
		
		if(left && right && top && down) break;
		
		cranes.pop_front();
		cranes.sort(cmp);
	}
	
	if(left && right && top && down) {
		printf("%d\n", num);
	} else {
		printf("Impossible\n");
	}
	
	return 0;
}
