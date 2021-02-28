#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int max_v = 110;
int arr[max_v];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        for(int i = 0; i<n; i++){
            cin >> arr[i]; 
        }
        int end = -1;
        for(int i = 0; i<k; i++){
            int s = 0;
            while(arr[s + 1] <= arr[s] && s < n - 1) s++;
            arr[s]++;
            if(s == n - 1){
                end = -1;
                break;
            }else{
                end = s + 1; //0 to 1 based
            }
        }
        //complexity bounded at min(k, sum of hi)
        cout << end << '\n';
    }

    return 0;
}