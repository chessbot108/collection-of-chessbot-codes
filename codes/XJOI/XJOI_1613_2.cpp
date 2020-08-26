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

#define max_v 210000
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


list<int> adj[max_v], rev[max_v];
int par[max_v];
int color[max_v];
int n, m;
list<int> q; //troll
set<pair<int, int>> vis; //XJOI i want to murder you for this

void Union(int a, int b){
  //dsu with extra steps
  a = par[a], b = par[b]; //a rep cow, if a par[a] = c, then the cow c admires is the same as the cow a admires
  if(a == b) return ;
  if(rev[a] < rev[b]) swap(a, b); //unoptimal to merge big lists into small lists
  for(int x : rev[b]){
    rev[a].push_back(x); //x is in rev[a] if and only if par[x] = a
    par[x] = a; //all the cows in b's list now admire a
  }
  while(!adj[b].empty()){
    adj[a].push_back(adj[b].front());
    adj[b].pop_front();
  }
  if(adj[a].size() >= 2) q.push_back(a); //another to process, lazy checking works
}


int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0; i<m; i++){
    int a, b;
    scanf("%d%d", &a, &b); //the case where a == b gave me a headache. :/
    if(!vis.count(make_pair(a, b)))adj[a].push_back(b);
    vis.insert(make_pair(a, b));
  }

  for(int i = 1; i<=n; i++){
    par[i] = i; //DSU init
    rev[i].push_back(i);
    if(adj[i].size() >= 2){
      q.push_back(i);
    }
  }

  while(!q.empty()){
    int x = q.front(); q.pop_front();
    //the process of merging all the children
    while(adj[x].size() > 1){
      int a = adj[x].front(); adj[x].pop_front();
      Union(adj[x].back(), a); //keep merging all the to the first one until i can't anymore
    }
  }
  int cnt = 1;
  for(int i = 1; i<=n; i++){
    if(color[par[i]] == 0) color[par[i]] = cnt++;
    printf("%d\n", color[par[i]]);
  }

  return 0;
}
