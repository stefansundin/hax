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

int main() {
	int t,i;
	scanf("%d", &t);
	for (i=0; i < t; i++) {
		double c,f,x, r=0;
		scanf("%lf %lf %lf", &c, &f, &x);
		// printf("C: %lf, F: %lf, X: %lf\n", c, f, x);

		int farms = 0;
		double rate = 2;
		while (true) {
			// printf("rate: %lf, time passed: %lf, time to buy next farm: %lf\n", rate, r, c/rate);
			double r_no_more_farms = x/rate;
			double r_one_more_farms = c/rate+x/(rate+f);
			// printf("r_no_more_farms: %lf\n", r_no_more_farms);
			// printf("r_one_more_farms: %lf\n", r_one_more_farms);
			if (r_one_more_farms < r_no_more_farms) {
				r += (c/rate);
				rate += f;
				// printf("Buy farm after %lf\n", r);
			}
			else {
				r += r_no_more_farms;
				// printf("Finish after %lf\n", r_no_more_farms);
				break;
			}
		}

		printf("Case #%d: %lf\n", i+1, r);
	}
}
