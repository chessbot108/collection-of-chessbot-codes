#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cassert>
#define cont continue
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define oom scanf
#define moo printf
#define mool puts("");
#define x first
#define y second
#define tern(a, b, c) ((a) ? (b) : (c))
#define piii pair<pii, pii>
//notlikeduck
using namespace std;
int n, arr[20];
vector<pii> p;
vector<pii> lines;

piii P[20][20];

int sign(const pii& a, const pii& b, const pii& c){
  return tern((b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x) > 0, 1, -1);
}

inline bool intersect(const piii& a, const piii& b){
  return (sign(a.x, a.y, b.x) != sign(a.x, a.y, b.y)) && (sign(b.x, b.y, a.x) != sign(b.x, b.y, a.y)); //death and constant factors
}



int main(){
  cin >> n;
  /**
  while(n--){
    int a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g >> h; //notlike duck
    moo("%s\n", tern(intersect(mp(mp(a, b), mp(c, d)), mp(mp(e, f), mp(g, h))), "YES", "NO"));
  }
  **/
  if(n > 8){
    moo("0\n");
    return 0;
  }
  for(int i = 0; i<n; i++){
    int X, Y; cin >> X >> Y;
    p.pb(mp(X, Y));
  }
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      P[i][j] = mp(p[i], p[j]);
    }
  }
  for(int i = 0; i<n; i++) arr[i] = i;
  int tot = 0, cur; //looool
  do{ //step 1
    lines.clear();
    lines.pb(mp(arr[1], arr[2]));
    lines.pb(mp(arr[2], arr[0]));
    lines.pb(mp(arr[1], arr[0])); //step 2
    bool wo = 1;
    for(int t = 3; t<n &&wo; t++){
      int i = arr[t], temp = 0, j;
      for(int s = 0; s<t &&wo; s++){
        j = arr[s];
        cur = 0;
        for(int k = 0; k<lines.size(); k++){ //4 nested for loops be like
          if(j == lines[k].x || j == lines[k].y) cont;
          if(intersect(P[i][j], P[lines[k].x][lines[k].y])){
            //moo("int: %d %d %d %d\n", i, j, lines[k].x, lines[k].y);
            cur = 1;
            //assert(false);
          }
        }
        //moo("%d\n", cur);
        if(!cur){
          temp++;
          lines.pb(mp(i, j));
        }
      }
      if(temp != 3) wo = 0;
    }
    if(wo){
      tot++;
      //for(int i = 0; i<n; i++) moo("%d ", arr[i]); mool;
    }
    //moo("next it\n");
  } while(next_permutation(arr, arr + n));
  moo("%d\n", tot);
  return 0;
}
