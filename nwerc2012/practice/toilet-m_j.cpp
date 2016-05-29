#include <stdio.h>
#include <algorithm>
#include <list>

using namespace std;

int main() {
	char c;
	char prev3;
	scanf("%c", &prev3);
	//prev3 = prev2 = prev1;
	int p1 = 0, p2 = 0, p3 = 0;
	
	if (prev3 == 'U') {
		p2++;
	} else {
		p1++;
	}
	
	bool first = true;
	
	while(true) {
		scanf("%c", &c);
		if(c!='U' && c!='D') break;
		if(c=='U') {
			if(prev3=='D') {
				p3+=1;
			} else if(first) {
				p2-=2;
			}
			p2+=2;
			//p1+=2;
		} else { // D
			if(prev3=='U') {
				p3+=1;
			} else if(first) {
				p1-=2;
			}
			p1+=2;
			//p2+=2;
		}
		prev3 = c;
		first = false;
	}
	
	printf("%d\n%d\n%d\n", p1, p2, p3);
	
	return 0;
}
