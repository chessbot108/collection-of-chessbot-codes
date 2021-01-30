#include <iostream>
using namespace std;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        if(a%b == 0){
            cout << "1\n";
        }else if(a > b){
            cout << ((a%b) ? 2 : 1) << '\n';
        }else{
            cout << ((b%a) ? b/a +1 : b/a) << '\n';
        }
    }
    return 0;
}