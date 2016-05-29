#include <stdio.h>
#include <algorithm>
#include <list>

using namespace std;

int main() {
	int l, d, n;
	scanf("%d %d %d", &l, &d, &n);
	
	list<int> birds;
	
	int tmp;
	while(n--) {
		scanf("%d", &tmp);
		birds.push_back(tmp);
	}
	
	birds.sort();
	
	int num = 0;
	for(int i=6; i<=l-6; i+=d) {
		if(birds.empty() || i+d<=birds.front()) {
			num++;
		} else if(!birds.empty()) {
			i = birds.front();
			birds.pop_front();
		}
	}
	
	printf("%d\n", num);
	
	return 0;
}
