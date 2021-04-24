#include <iostream>
//40/100 code by daniels
using namespace std;

int main(){
    int n;
    cin >> n;
    int costs[n];
    for(int i = 0; i < n; i++){
        cin >> costs[i];
    }
    
    int total = 0;
    string s;
    bool orig = true, rev = true;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < s.length()/2; j++){
            if(s[j] < s[s.length()-j-1]){
                rev = false;
            }
            if(s[j] > s[s.length()-j-1]){
                orig = false;
            }
        }
        if(rev == false){
            if(orig == false){
                total = 0;
                break;
            }
            else{
                total += costs[i];
            }
        }
        
        rev = true;
        orig = true;
    }
    
    if(total == 0){
        cout << -1 << endl;
    }
    else{
        cout << total << endl;
    }
}
