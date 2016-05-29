// ncpc2010
// stefan

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
	int n;
	scanf("%d\n",&n);
	while (n--) {
		char l[100];
		gets(l);
		if (!strcmp("P=NP",l)) {
			printf("skipped\n");
			continue;
		}
		int a,b;
		sscanf(l,"%d+%d", &a,&b);
		printf("%d\n",a+b);
	}
}
