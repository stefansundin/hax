#include <stdio.h>
#include <algorithm>
using namespace std;

int k;
float maxsum = 0, sum = 0;
char c;

char data[100100];

int main() {
	scanf("%d\n", &k);
	
	float k_sum = 0;
	int j = 0;
	while (scanf("%c", &c) == 1) {
		if (c == '\n') break;
		data[j++] = (c == '0') ? -1 : 1;
	}
	
	for(int i=0; i<k; i++) {
		k_sum += data[i];
		//printf("k%d %d %d\n", i, k_sum, data[i]);
	}
	int start = 0;
	int startmax = 0;
	float len = k;
	float lenmax = k;
	sum = k_sum;
	maxsum = k_sum;
	for(int i=k; i<j; i++) {
		k_sum += data[i];
		k_sum -= data[i-k];
		
		if (k_sum == k) {
			startmax = i-k+1;
			lenmax = k;
			break;
		}
		
		if (k_sum/k >= (sum+data[i])/(len+1)) {
			sum = k_sum;
			start = i-k+1;
			len = k;
		} else {
			len++;
			//printf("pick\n");
			sum = sum+data[i];
		}
		//sum = max(k_sum+data[i], sum);
		if (sum/len > maxsum/lenmax) {
			maxsum = sum;
			lenmax = len;
			startmax = start;
		} else if (sum/len == maxsum/lenmax) {
			lenmax = min(lenmax, len);
			startmax = start;
		}
		//printf("i%d %f %f %f %d\n", i, sum/len, maxsum/lenmax, k_sum/k, data[i]);
	}
	
	printf("%d %.0f\n", startmax+1, lenmax);
	
	return 0;
}
