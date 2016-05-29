#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
map< string, int > mymap;
vector< pair<int, int> > parents(100);
map<string, int>::iterator cip, p1ip, p2ip;

double num_conn(int ch) {
	if (ch == -1) return 0;
	if (ch == 0) return 1;
	pair<int,int> p = parents[ch];
	//printf("numconn ch=%d f=%d s=%d\n",ch,p.first,p.second);
	return (num_conn(p.first) + num_conn(p.second)) / 2;
}

int main() {
	fill(parents.begin(),parents.end(),pair<int,int>(-1,-1));
	int n, m, ci,p1i,p2i; int id = 0;
	scanf("%d %d\n",&n, &m);
	
	char c[12],p1[12],p2[12];
	scanf("%s\n", &c[0]);
	mymap.insert(pair<string,int>(c,id++));
	
	while (n--) {
		scanf("%s %s %s\n", &c[0], &p1[0], &p2[0]);
		p1ip = mymap.find(p1);
		if (p1ip == mymap.end()) {
			p1i = id++; mymap.insert(pair<string,int>(p1,p1i));
		} else { p1i = p1ip->second; }
		p2ip = mymap.find(p2);
		if (p2ip == mymap.end()) {
			p2i = id++; mymap.insert(pair<string,int>(p2,p2i));
		} else { p2i = p2ip->second; }
		cip = mymap.find(c);
		if (cip == mymap.end()) {
			ci = id++; mymap.insert(pair<string,int>(c,ci));
		} else { ci = cip->second; }
		//printf("%d %d \n", p1i,p2i);
		parents[ci] = pair<int, int>(p1i, p2i);
		//printf("added %d %d %d\n", ci,  parents[ci].first, parents[ci].second);
	}
	double max_val = 0; int mpers = -1;
	while (m--) {
		scanf("%s\n", c);
		cip = mymap.find(c);
		if (cip == mymap.end()) continue;
		double calc = num_conn(cip->second);
		//printf("cip=%d calc=%.20lf maxval=%lf\n",cip->second,calc,max_val);
		if (calc > max_val) {
			max_val = calc;
			mpers = cip->second;
			//printf("mpers=%d\n",mpers);
		}
	}
	//printf("mpers=%d\n",mpers);
	for (map<string,int>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
		//printf("%d %s\n", (*it).second, (*it).first.c_str());
		/*pair<int,int> p = parents[(*it).second];
			printf("%d %s %d %d\n", (*it).second, (*it).first.c_str(), p.first,p.second);
			*/
		if ((*it).second == mpers) {
			printf("%s\n", (*it).first.c_str());
		}
	}
}

