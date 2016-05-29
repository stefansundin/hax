//stefan

#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	char data[1010];
	gets(data);
	int len = strlen(data);
	
	int num = (data[0] != data[1])+(data[1] == 'D');
	for (int i=2; i < len; i++) {
		if (data[i] == 'D') num+=2;
	}
	printf("%d\n", num);
	
	num = (data[0] != data[1])+(data[1] == 'U');
	for (int i=2; i < len; i++) {
		if (data[i] == 'U') num+=2;
	}
	printf("%d\n", num);

	num = 0;
	for (int i=1; i < len; i++) {
		if (data[i] != data[i-1]) num++;
	}
	printf("%d\n", num);
}
