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

long long fdp[110];
long long fac(int x) {
	if (fdp[x] != 0) return fdp[x];
	if (x == 0) return 1;
	fdp[x] = x*fac(x-1);
	return fdp[x];
}

int main() {
	memset(fdp,0,sizeof fdp);
	//printf("fac(10): %d\n", fac(10));

	int k;
	while (scanf("%d\n",&k) != EOF) {
		char M[110], C[110];
		gets(M); gets(C);
		//scanf("%s\n", M); scanf("%s\n", C);

		int len = strlen(M);
		int numblocks = len/k;
		bool impossible = false;

		//printf("len: %d\nM: %s\nC: %s\n", len,M,C);
		//printf("processing: %s\n",M);

		map<int,vi> sol;

		// process block 0
		for (char c='a'; c <= 'z'; c++) {
			//printf("c: %c\n", c);

			int numm = 0, numc=0;
			for (int i=0; i < k; i++) {
				if (M[i] == c) numm++;
				if (C[i] == c) numc++;
			}
			if (numm != numc) {impossible = true; break;}
			//if (numc > 0) printf("%c: %d\n", c,numc);

			if (numc > 1) {
				for (int i=0; i < k; i++) {
					if (M[i] == c) {
						for (int j=0; j < k; j++) {
							if (C[j] == c) {
								if (sol.count(i) == 0) {
									sol[i] = vi();
								}
								sol[i].push_back(j);
							}
						}
					}
				}

			}
		}
		if (impossible) { printf("0\n"); continue; }

		/*
		for (int i=0; i < k; i++) {
			if (sol.count(i) > 0) {
				printf("%d maps to", i);
				for (int j=0; j < sol[i].size(); j++) {
					printf(" %d", sol[i][j]);
				}
				printf("\n");
			}
		}
		*/


		// process block 1..n
		for (int I=1; I < numblocks; I++) {
			//printf("processing block %d\n", I);

			// check if impossible
			for (char c='a'; c <= 'z'; c++) {
				//printf("c: %c\n", c);

				int numm = 0, numc=0;
				for (int i=0; i < k; i++) {
					if (M[I*k+i] == c) numm++;
					if (C[I*k+i] == c) numc++;
				}
				if (numm != numc) {impossible = true; break;}
			}
			if (impossible) break;

			// check mappings
			vector<ii> del;

			for (int i=0; i < k; i++) {
				if (sol.count(i) > 0) {
					for (int j=0; j < sol[i].size(); j++) {
						//printf(" %c != %c : %d\n", M[I*k+i], C[I*k+sol[i][j]], (M[I*k+i] != C[I*k+sol[i][j]]));
						if (M[I*k+i] != C[I*k+sol[i][j]]) {
							//printf("%d no longer maps to %d\n", i,sol[i][j]);
							del.push_back(ii(i,sol[i][j]));
						}
					}
				}
			}

			for (int i=0; i < del.size(); i++) {
				ii d = del[i];
				//printf("del %d -> %d\n", d.first,d.second);
				for (vi::iterator it = sol[d.first].begin(); it != sol[d.first].end(); it++) {
					if (*it == d.second) {
						sol[d.first].erase(it);
						break;
					}
				}
			}


		}
		if (impossible) { printf("0\n"); continue; }

		long long res = 0, rmax = 0;
		bool any = false;

		/*
		for (char c='a'; c <= 'z'; c++) {
			int numm = 0;
			for (int i=0; i < k; i++) {
				if (M[i] == c) numm++;
			}
			if (numm > 0) any=true;
			if (numm > 1) {
				res += fac(numm);

			}
		}
		*/

		int taken[255]; memset(taken,0,sizeof taken);
		for (int i=0; i < k; i++) {
			if (sol.count(i) > 0) {

				if (sol[i].size() > 1 && !taken[M[i]]) {
					any = true;
					res += fac(sol[i].size());
					taken[M[i]] = 1;
				}
			}
		}
		if (!any) res++;

		printf("%lld\n", res);

	}

	return 0;
}
