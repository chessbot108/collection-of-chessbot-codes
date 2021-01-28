#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define max_v 110000
#define cont continue
#define lsb(x) ((x)&-(x))

using namespace std;

//trying to impl cdq dnq

struct p{
    int x, y, z, ind;
    p(){}
    p(int a, int b, int c, int d){ x = a, y = b, z = c, ind = d;}
    bool operator < (const p& b) const{
        //sort by greater x, then lesser y, then lesser z. very interesting logic
        //this'll make the dnq work
        return (x == b.x) ? ((y == b.y) ? z < b.z : y < b.y) : x > b.x; 
    }
} arr[max_v], tmp[max_v];

int ans[max_v], BIT[max_v], rec[max_v], n;

int S(int k){ return (!k) ? 0 : BIT[k] + S(k - lsb(k));}
void U(int k, int val){ for(; k<=n; k += lsb(k)) BIT[k] += val;}

void dnq(int l, int r){
    //[l, r) as all things should be
    if(l + 1 == r) return ; //empty case
    int mid = (l + r) / 2, sz = l, j = l, k = mid, cnt = 0;
    //mid is mid, sz is total pointer
    //j is left pointer, k is right pointer, cnt is how far right pointer advanced
    dnq(l, mid); dnq(mid, r);
    while(j < mid && k < r){
        if(arr[j].y > arr[k].y){
            U(arr[j].z, 1);
            rec[cnt++] = arr[j].z;
            tmp[sz++] = arr[j++];
        }else{
            ans[arr[k].ind] += cnt - S(arr[k].z);
            tmp[sz++] = arr[k++];
        }
    }
    while(j < mid) tmp[sz++] = arr[j++];
    while(k < r) ans[arr[k].ind] = ans[arr[k].ind] + cnt - S(arr[k].z), tmp[sz++] = arr[k++];

    for(int i = 0; i < cnt; i++) U(rec[i], -1);
    for(int i = l; i < r; i++) arr[i] = tmp[i]; 
}


int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(0); 
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i].x >> arr[i].y >> arr[i].z; arr[i].ind = i;
    }
    sort(arr, arr + n);
    dnq(0, n);
    for(int i = 0; i<n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}

