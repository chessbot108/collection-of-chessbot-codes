#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <utility>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <random>
#include <chrono>
#include <queue>
#define cont continue
#define lb long double
#define pow2(n) (1 << (n))
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ins insert
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define add(a, b) (((a)%mod + (b)%mod)%mod)
#define mul(a, b) (((a)%mod * (b)%mod)%mod)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define tern(a, b, c) ((a) ? (b) : (c))
//the following ones give off usaco vibes
#define pbenq priority_queue
#define moo printf
#define oom scanf
#define mool puts("") 
#define loom getline

const ll mod = 1e9 + 7;
const int MX = 1e5 +10, int_max = 0x3f3f3f3f;

using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}


struct point{
  int x, y;
  lb angle, dist;
  point(){}
  point(int a, int b){
    x = a, y = b;
    dist = sqrt((lb)(a*a) + (lb)(b*b));
    angle = sin(y/dist); //SOH
  }
  bool operator < (const point& b) const{
    return angle < b.angle;
  }
};

lb get_cost(const point& a, const point& b){
  return tern(a.angle - b.angle > 0, a.angle - b.angle, b.angle - a.angle) * b.dist;
}


int main(){
  cin.tie(0) -> sync_with_stdio(0);
  point a = point(1, 0);
  point b=  point(1, 1);
  point c = point(2, 3);
  moo("%Lf\n", get_cost(a, c) + get_cost(c, b));
	return 0;
}


