//code by william and miles
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>

using namespace std;

#define MAXN 2100
#define pint pair<long long,long long>
#define RED 1
#define BLUE 0
#define ll long long
#define MOD 1000000007

ll r, b, s;
pint books[MAXN * 2];
ll reddp[MAXN], bluedp[MAXN];
ll auxred[MAXN], auxblue[MAXN], ar2[MAXN], ab2[MAXN];

int main() {
	scanf("%lld%lld%lld", &r, &b, &s);
	for (int i = 0; i <= s; i++) reddp[i] = 0, bluedp[i] = 0;
	reddp[0] = 1, bluedp[0] = 1;
	for (int i = 0; i < r; i++)
		scanf("%lld", &books[i].first), books[i].second = RED;
	for (int i = r; i < r+b; i++)
		scanf("%lld", &books[i].first), books[i].second = BLUE;

	sort(books, books+r+b);

	for (int i = 0; i < r+b; i++) {
		if (i < r+b-1 && books[i].first == books[i+1].first) {
			memset(auxred, 0, sizeof(auxred));
			memset(auxblue, 0, sizeof(auxblue));

			memset(ar2, 0, sizeof(ar2));
			memset(ab2, 0, sizeof(ab2));

			// normal case
			for (int j = 0; j <= s - books[i].first; j++)
				auxred[j + books[i].first] = (auxred[j + books[i].first] + bluedp[j]) % MOD;
			for (int j = 0; j <= s - books[i].first; j++)
				auxblue[j + books[i].first] = (auxblue[j + books[i].first] + reddp[j]) % MOD;

			// stack on top of each other
			for (int j = 0; j <= s - books[i].first; j++)
				ar2[j + books[i].first] = (ar2[j + books[i].first] + auxblue[j]) % MOD;
			for (int j = 0; j <= s - books[i].first; j++)
				ab2[j + books[i].first] = (ab2[j + books[i].first] + auxred[j]) % MOD;

			// combine
			for (int j = 0; j <= s; j++)
				reddp[j] = (reddp[j] + ar2[j] + auxred[j]) % MOD;
			for (int j = 0; j <= s; j++)
				bluedp[j] = (bluedp[j] + ab2[j] + auxblue[j]) % MOD;

			i++; continue;
		}

		if (books[i].second == RED)
			for (int j = 0; j <= s - books[i].first; j++)
				reddp[j + books[i].first] = (reddp[j + books[i].first] + bluedp[j]) % MOD;
		else
			for (int j = 0; j <= s - books[i].first; j++)
				bluedp[j + books[i].first] = (bluedp[j + books[i].first] + reddp[j]) % MOD;
	}
	ll ans = (reddp[s] + bluedp[s]) % MOD;
	//for (int i = 1; i <= s; i++)
		//ans = (ans + reddp[i] + bluedp[i]) % MOD;
	printf("%lld\n", ans);
  return 0;
}
