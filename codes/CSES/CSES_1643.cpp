#include <iostream>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[(int)2e5 +10];

ll dnq(int l, int r){
    if(l + 1 >= r) return arr[l];
    int mid = (l + r)/2;
    ll ans = max(dnq(l, mid), dnq(mid, r)), left = arr[mid - 1], right = arr[mid], sum = 0ll;
    for(int i = mid - 1; i>=l; i--){
        sum += arr[i];
        left = max(left, sum);
    }
    sum = 0ll;
    for(int i = mid; i<r; i++){
        sum += arr[i];
        right = max(right, sum);
    }
    return max(ans, left + right);
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    cout << dnq(0, n) << '\n';
    return 0;
}