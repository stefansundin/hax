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

int n,k;
int votes[10];
int ndom=0;
int lo = 1;

vector<double> vote(int x, double a, double b, double c, double d, double e) {
		if (x>=(k-ndom)) {
				vector<double> r;

				r.assign(5, 0.0);

				int maxx = max(a, max(b, max(c, max(d, e))));

				double num = 0;
				if (maxx == a) num++;
				if (maxx == b) num++;
				if (maxx == c) num++;
				if (maxx == d) num++;
				if (maxx == e) num++;

				double res = 1.0/num;

				if (maxx == a) r[0] = res;
				if (maxx == b) r[1] = res;
				if (maxx == c) r[2] = res;
				if (maxx == d) r[3] = res;
				if (maxx == e) r[4] = res;

				//printf("num: %lf %d\t %d %d %d\n", res, lo++, a, b, c);
				for (int i=0; i<3; i++) {
					//printf("hmm: %lf\n", r[i]);
				}

				return r;
		} else {
				vector<double> res;
				res.assign(5,0.0);

				for (int i=0; i<n; i++) {
					double q = ndom+x;

					if (i==0) {
						vector<double> m = vote(x+1, a+1, b, c, d, e);
						res[0] += (a / q)*m[0];
						res[1] += (b / q)*m[1];
						res[2] += (c / q)*m[2];
						res[3] += (d / q)*m[3];
						res[4] += (e / q)*m[4];
					}
					if (i==1) {
						vector<double> m = vote(x+1, a, b+1, c, d, e);
						res[0] += (a / q)*m[0];
						res[1] += (b / q)*m[1];
						res[2] += (c / q)*m[2];
						res[3] += (d / q)*m[3];
						res[4] += (e / q)*m[4];
					}
					if (i==2) {
						vector<double> m = vote(x+1, a, b, c+1, d, e);
						res[0] += (a / q)*m[0];
						res[1] += (b / q)*m[1];
						res[2] += (c/ q)*m[2];
						res[3] += (d/ q)*m[3];
						res[4] += (e/ q)*m[4];
					}
					if (i==3) {
						vector<double> m = vote(x+1, a+1, b, c, d+1, e);
						res[0] += (a/ q)*m[0];
						res[1] += (b/ q)*m[1];
						res[2] += (c/ q)*m[2];
						res[3] += (d/ q)*m[3];
						res[4] += (e/ q)*m[4];
					}
					if (i==4) {
						vector<double> m = vote(x+1, a, b, c, d, e+1);
						res[0] += (a/ q)*m[0];
						res[1] += (b/ q)*m[1];
						res[2] += (c/ q)*m[2];
						res[3] += (d/ q)*m[3];
						res[4] += (e/ q)*m[4];
					}
				}
				return res;
		}
}

int main() {
	while (scanf("%d %d",&n,&k) != EOF) {
		ndom=0;
		memset(votes, 0, sizeof votes);
		for (int i=0; i < n; i++) {
			scanf("%d", &votes[i]);
			ndom += votes[i];
		}

		vector<double> res = vote(0, votes[0], votes[1], votes[2], votes[3], votes[4]);

		double maax = 0;
		int ind = 0;
		double sum = 0;
		for (int i=0; i<res.size(); i++) {
				if (res[i] > maax) {
					ind = i;
					maax = res[i];
				}
		}

		for (int i=0; i<res.size(); i++) {
				if (res[i] != maax) {
					sum += res[i];
				}
		}

		res[ind] = 1-sum;

		for (int i=0; i<n; i++) {
			printf("pub %d: %.2lf %\n", i+1, res[i]*100);
		}

		/*double test[10];
		for (int i=0; i<10; i++) {
			test[i] = 1;
		}
		double nvotes = ndom;
		printf("nvotes: %lf\n", nvotes);
		for (int i=0; i < k-ndom; i++) {

			for (int j=0; j<n; j++) {
				for (int k=1; k <= i; k++) {
					test[j] *= (double)(k+votes[j])/nvotes;
				}
			}
			nvotes++;*/
		}

		/*double sum = 0;
		for (int i=0; i<10; i++) {
			sum += test[i];
			printf("%lf %lf\n", test[i], sum);
		}*/



	return 0;
}
