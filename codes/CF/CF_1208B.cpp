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

#define max_v 2100
#define int_max 0x3f3f3f3f
#define cont continue
#define pow_2(n) (1 << (n))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)(ceil(log2((n)))))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int freq[max_v], arr[max_v], srt[max_v], temp[max_v];
int n, ans = max_v, cnt;

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(0);
	cin >> n;
  for(int i = 0; i<n; i++){
    cin >> arr[i];
    srt[i] = arr[i];
  }
  sort(srt, srt + n);
  for(int i = 0; i<n; i++){
    arr[i] = lower_bound(srt, srt + n, arr[i]) - &srt[0];
    freq[arr[i]]++;
    if(freq[arr[i]] == 1) cnt++;
  }
  if(cnt == n) ans = 0;
  for(int l = 0; l<n; l++){
    for(int i = 0, cnt = 0; i<n; i++) temp[i] = freq[i];
    for(int r = l, rem = 0; r<n; r++){
      temp[arr[r]]--;
      if(temp[arr[r]] >= 1) rem++;
      if(cnt + rem == n) ans = min(ans, r - l + 1);
    }
  }
  cout << ans << endl;
	return 0;
}

