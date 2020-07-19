//code by weiming
//note: 8/10 cases during the test
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

#define max_v 1100000
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

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}

int arr[max_v];
/**

adslk;jfasdlkfj;klasdfj;klsadfj;klsadjf;klasdjf;klsadjf;klsadfj;sadlkjf
asdl;kfjasd;lkfjsad;klfjsakd;lfj;klsadjf;klasdjf
asfkjsa;dkfjsakl;f;kljsfdklj;fadsjkl;fsadjklfsda;jklfsad
fsda;lkfsda;lfsadkljfsdjklfdsajklfdasjklfsda;
sad;fsdalfsdaljk;fsdajl;kfsdakljfsdakljfsdaj;kl
asdfsdalkfsdjklfsdjklfsdkjlfsdakjlfsjadkl
fsda;lkfsdajlk;fsdjklfsdjklfsdakljfsdajklfsda
fsda;lkfsda;lkfsadljk;fsdajkl;fsdakjlfsdajklfsdajkl;fsdakljfsdaljkfsdakljfsad;'
fsad;lfsda;ljkfsdalkj;sdfaklj;fsdjklfsdkjlfsdljkjklfsd;fsdklafsdaklj;jfkl;sda

**/
int main(){
	
  int n, m;
  scanf("%d%d", &n, &m);
  for(int i = 0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  int ind = lower_bound(arr, arr + n, m) - &arr[0];
  if(arr[ind] == m) printf("%d", ind + 1);
  else printf("0");
	return 0;
}

