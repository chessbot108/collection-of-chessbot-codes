//code by tomas
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int A = 0, B = 0, x = 0;
    int arr[n + m];
    while(x < n + m){
        if(A >= n){
            arr[x++] = b[B++];
        } else if(B >= m){
            arr[x++] = a[A++];
        } else if(a[A] < b[B]){
            arr[x++] = a[A++];
        } else {
            arr[x++] = b[B++];
        }
    }
    for(int i = 0; i < n + m; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
