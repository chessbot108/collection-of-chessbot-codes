//code by bckt
#include <iostream>
#include <cstring>

using namespace std;

#define MAXN 100100

char s[MAXN];
int v[MAXN];

int main() {
	scanf("%s", s);
	memset(v,0,sizeof(v));
	for (int i = 0; s[i]; ++i)
		v[s[i]]++;
	char r = 'a';
	for (int i = 'b'; i <= 'z'; ++i)
		if (v[i] > v[r])
			r = i;
	printf("%c\n%s\n", r, s);

}
