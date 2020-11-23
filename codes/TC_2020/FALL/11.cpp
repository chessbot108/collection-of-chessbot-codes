//william 60/150

#include <iostream>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <utility>

using namespace std;

#define MAXN 1000100

long long n, enc[MAXN];

struct TreapNode
{
	long long elem, rs, ls, prioirty;
	TreapNode *r, *l;
};

long long randint() {return rand();}
TreapNode* getnode(long long elem) {
	TreapNode* nn = new TreapNode;
	nn->elem = elem; nn->rs = 0; nn->ls = 0;
	nn->prioirty = randint();
	nn->r = nullptr;
	nn->l = nullptr;
	return nn;
}

TreapNode* left_rotate(TreapNode* top) {
	TreapNode *r = top->r, *rl = r->l;
	top->r = rl;
	top->rs = r->ls;
	r->l = top;
	r->ls = top->ls + top->rs + 1;
	return r;
}

TreapNode* right_rotate(TreapNode* top) {
	TreapNode *l = top->l, *lr = l->r;
	top->l = lr;
	top->ls = l->rs;
	l->r = top;
	l->rs = top->rs + top->ls + 1;
	return l;
}

TreapNode* insert(TreapNode* curr, long long elem) {
	if (!curr) return getnode(elem);
	if (curr->elem < elem) {
		curr->r = insert(curr->r, elem);
		curr->rs++;
		if (curr->r->prioirty > curr->prioirty)
			curr = left_rotate(curr);
	}
	else {
		curr->l = insert(curr->l, elem);
		curr->ls++;
		if (curr->l->prioirty > curr->prioirty)
			curr = right_rotate(curr);
	}
	return curr;
}

TreapNode* treap = NULL;

long long get(TreapNode* curr, long long alsobelow, long long want) {
	//cout << curr->elem << " " << alsobelow << endl;
	if (curr->ls + 1 + alsobelow == want) return curr->elem;
	if (alsobelow + 1 + curr->ls > want) return get(curr->l, alsobelow, want);
	return get(curr->r, alsobelow + 1 + curr->ls, want);
}

long long median() {
	long long sz = treap->ls + treap->rs + 1;
	if (sz%2) return (get(treap, 0, (sz+1)/2));
	return ( get(treap, 0, (sz/2)) + get(treap, 0, (sz/2)+1) )/2;
}

long long ans[MAXN][6];
long long maxsofar, minsofar, tot;
long long stsize, bstart;

map<long long,long long> disc;
pair<long long,long long> segtree[MAXN * 4]; // ind, cnt
long long fromdisc[MAXN], converted[MAXN], lastapp[MAXN];

pair<long long,long long> max(pair<long long,long long> a, pair<long long,long long> b) {
	if (a.second > b.second) return a;
	if (b.second > a.second) return b;
	if (a.first == -1) return b;
	if (b.first == -1) return a;
	if (lastapp[a.first] > lastapp[b.first]) return a;
	return b;
}


void update(long long c) {
	c += bstart;
	segtree[c].second++;
	c = (c-1)/2;
	while (c >= 0) {
		segtree[c] = max(segtree[c*2+1], segtree[c*2+2]);
		if (c == 0) break;
		c = (c-1)/2;
	}
}

int main() {
	srand(time(NULL));
	
	scanf("%lld", &n);
	for (long long i = 0; i < n; i++) scanf("%lld", &enc[i]);

	bstart = 1; while (bstart < n) bstart *= 2;
	stsize = bstart * 2 - 1; bstart--;

	for (long long i = 0; i < n; i++) lastapp[i] = -1;

	for (long long i = 0; i < stsize; i++)
		segtree[i] = make_pair(-1, -1);

	for (long long i = bstart; i < stsize; i++)
		segtree[i].first = i-bstart, update(i-bstart);
		
	minsofar = enc[0];
	maxsofar = enc[0];
	tot = enc[0];
	ans[0][5] = enc[0];
	treap = insert(treap, enc[0]);

	for (long long i = 0; i < 5; i++) ans[0][i] = enc[0];

	for (long long i = 1; i < n; i++) {
		ans[i][5] = median() ^ enc[i];
		treap = insert(treap, ans[i][5]);

		minsofar = min(minsofar, ans[i][5]);
		maxsofar = max(maxsofar, ans[i][5]);
		tot += ans[i][5];

		ans[i][0] = minsofar;
		ans[i][1] = maxsofar;
		ans[i][2] = tot;
		ans[i][3] = median();

		disc[ans[i][5]] = -1;
		//cout << ans[i][4] << endl;
	}

	long long c = 0;
	for (auto i : disc) {
		fromdisc[c]=i.first, disc[i.first] = c++;
		//cout << i.first << " " << c - 1 << endl;
	}
	for (long long i = 0; i < n; i++)
		converted[i] = disc[ans[i][5]];
	for (long long i = 0; i < n; i++) lastapp[i] = -1;

	lastapp[converted[0]] = 0;
	update(converted[0]);
	//cout << converted[0] << endl;
	ans[0][4] = segtree[0].first;

	for (long long i = 1; i < n; i++) {
		lastapp[converted[i]] = i;
		update(converted[i]);
		/*
		cout << converted[i] << ":\n";
		for (long long i = 0; i < stsize; i++)
			cout << "(" << segtree[i].first << ", " << segtree[i].second << ") ";
		cout << endl;
		*/
		ans[i][4] = segtree[0].first;
	}
	
	for (long long i = 0; i < n; i++) {
		for (long long j = 0; j < 4; j++) {
			printf("%lld ", ans[i][j]);
		}
		printf("%lld", fromdisc[ans[i][4]]);
		printf("\n");
	}
	






}
