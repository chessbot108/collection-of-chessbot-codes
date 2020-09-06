#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <list>
#include <queue>
#include <stack>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>

#define max_v 440
#define LOGN 50
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << (n))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)(ceil(log2((n)))))
using namespace std;


int prefix[max_v], max_val[max_v][max_v], arr[max_v], graph[max_v][max_v], dp[max_v][max_v];

int n, K;

/**

dp[i][j] is the min cost to catch all groups of snakes up to points i after changing nets j times 
dp[i][j] = min(dp[i][j-1], dp[k][j-1] + graph[k][i]) for all values k < i
prefix[i] = sum of all the elements from index 0 to index i, exclusive
max_val[i][j] = maximum value in the interval i to j, inclusive
graph[i][j] = wasted space in the interval i to j (inclusive) if only 1 size change is used
graph[i][j] = max_val[i][j] * (size of inteval) - (sum of all snake groups in interval)
**/


int main(){

	scanf("%d%d", &n, &K);

	for(int i = 0; i<n; i++){
		scanf("%d", &arr[i]);
		max_val[i][i] = arr[i];
		prefix[i+1] = prefix[i] + arr[i]; 
	}
	

	for(int len = 1; len<n; len++){
		for(int i = 0; i + len < n; i++){
			max_val[i][i + len] = max(max_val[i][i + len - 1], arr[i + len]);
		}
	}

	

	for(int i = 0; i<n; i++){
		for(int j = i; j<n; j++){
			graph[i][j] = (max_val[i][j] * ((j - i) + 1)) - (prefix[j+1] - prefix[i]);
		}
	}

  memset(dp, 0x3f, sizeof(dp));
	
	for(int i = 0; i<n; i++){
		dp[i][0] = graph[0][i];
	}


	for(int j = 1; j<=K; j++){
		for(int i = 0; i<n; i++){
			for(int k = 0; k<i; k++){
			  dp[i][j] = min(dp[i][j], dp[k][j-1] + graph[k+1][i]);
			}
		}
	}

	
	printf("%d\n", dp[n-1][K]);


	return 0;

}
