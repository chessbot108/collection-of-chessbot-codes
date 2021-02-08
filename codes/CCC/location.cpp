#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    freopen("location.in", "r", stdin);
    freopen("location.out", "w+", stdout);
    int n, x = 0, y = 0;
    cin >> n;
    while(n--){
        char dir; cin >> dir;
        if(dir == 'U'){
            y++;
        }else if(dir == 'L'){
            x--;
        }else if(dir == 'R'){
            x++;
        }else{
            y--;
        }
    }
    cout << x << " " << y << '\n';
    return 0;
}