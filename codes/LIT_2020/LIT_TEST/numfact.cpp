//code by william
#include <iostream>
#include <utility>

using namespace std;

#define MAXN 110000
#define MOD 1000000007
#define add first
#define mult second
#define ll long long
#define pll pair<ll,ll>

int n, m, bstart, stsize;
pll blank = make_pair(0, 1);
pll segtree[4 * MAXN];

int p(int c) {return (c-1)/2;}
int c1(int c){return (c*2+1);}
int c2(int c){return (c*2+2);}

pll combine(pll f, pll s) {return make_pair(((f.add * s.mult) % MOD + s.add) % MOD, (f.mult * s.mult) % MOD);}

void update(int ind, pll newval) {
	segtree[ind + bstart] = newval;
	ind = p(ind + bstart);
	while (ind >= 0) {
		segtree[ind] = combine(segtree[c1(ind)], segtree[c2(ind)]);
		if (ind == 0) break;
		else ind = p(ind);
	}
}

pll query(int c, int cmin, int cmax, int minb, int maxb) {
	if (cmin > maxb || cmax < minb) return blank;
	if (cmin >= minb && cmax <= maxb) return segtree[c];
	return combine(query(c1(c), cmin, (cmin+cmax)/2, minb, maxb),
				   query(c2(c),1+(cmin+cmax)/2,cmax, minb, maxb));
}

int main() {
	scanf("%d%d", &n, &m);

	bstart = 1;
	while (bstart < n) bstart *= 2;
	stsize = bstart * 2, bstart--, stsize--;

	for (int i = 0; i < stsize; i++) segtree[i] = blank;

	for (int i = 0; i < n; i++) {
		char type; scanf(" %c", &type);
		ll val; scanf("%lld", &val);
		if (type == '+')
			update(i, make_pair(val, 1));
		else if (type == '-')
			update(i, make_pair(-val, 1));
		else if (type == '*')
			update(i, make_pair(0, val));
	}

	for (int i = 0; i < m; i++) {
		// cout << i << " " << m << endl;
		//for (int j = 0; j < stsize; j++)
		//	cout << "(" << segtree[j].add << " " << segtree[j].mult << ") ";
		//cout << endl;
		char type; scanf(" %c", &type);
		if (type == 'q') {
			ll x, y; scanf(" %lld %lld", &x, &y);
			pll op = query(0, 0, bstart, 0, y-1);
			printf("%lld\n", (x * op.mult + op.add) % MOD);
		}
		else {
			ll ind, val; char newop;
			scanf(" %lld %lld %c", &ind, &val, &newop);
			ind--;
			if (newop == '+')
				update(ind, make_pair(val, 1));
			else if (newop == '-')
				update(ind, make_pair(-val, 1));
			else if (newop == '*')
				update(ind, make_pair(0, val));
			
		}
	}
	return 0;

}

