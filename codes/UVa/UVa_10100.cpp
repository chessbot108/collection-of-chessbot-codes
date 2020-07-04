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

#define max_v 1100
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

map<string, int> ID;
vector<int> A, B;
string a, b;

int dp[max_v][max_v], tag = 1;

int get_ID(string& t){
  if(ID[t] != 0) return ID[t];
  ID[t] = tag++;
  //cout << "added " + t + "\n";
  //for(auto it = ID.begin(); it != ID.end(); it++){
  //  cout << it->second + " ";
  //}
  //puts("");
  return tag - 1;
}

void process(string& s, vector<int>& v){
  for(int i = 0; i<s.size(); i++){
    if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))) s[i] = ' ';
  }
  //cout << s << endl; 
  s += " !\n";
  istringstream iss(s);
  string temp;
  while(iss >> temp){
    if(temp == "!") break;
    v.push_back(get_ID(temp));
  }

  //for(int i = 0; i<v.size(); i++) printf("%d ", v[i]);
  //puts("");
}

int LCS(){
  int n = A.size(), m = B.size();
  
  for(int i = 1; i<=n; i++){
    for(int j = 1; j<=m; j++){
      //printf("%d %d %d\n", i, j, dp[i][j]);
      if(A[i - 1] == B[j - 1]){
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }else{
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
     // printf("%d %d %d\n", i, j, dp[i][j]);
    }
  }
  return dp[n][m];
}


int main(){
  int kase = 0;
	while(!cin.eof()){
    getline(cin, a);
    getline(cin, b);
    A.clear(); B.clear(); ID.clear();
    memset(dp, 0, sizeof(dp));
    if(a.empty() || b.empty()){ printf("%2d. Blank!\n", ++kase); cont;}
    process(a, A);
    process(b, B);
    printf("%2d. Length of longest match: %d\n", ++kase, LCS());
  }
	return 0;
}

