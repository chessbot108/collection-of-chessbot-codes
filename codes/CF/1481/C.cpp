#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int max_v = 1e5 + 10;
//so i just have to make sure the last painter does not make the fences worse
//then we can paint all bad painters to the last painter's fence and he'll fix it for us. yayyy
vector<int> adj[max_v]; //which indeces per color
int a[max_v], b[max_v], c[max_v], freq[max_v]; //good naming
int n, m;
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i<=max(n, m); i++){
            adj[i].clear();
            a[i] = b[i] = c[i] = freq[i] = 0;
        } //sum of n < 1e5 so this is fine
        for(int i = 1; i<=n; i++){
            cin >> a[i]; 
        }
        for(int i = 1; i<=n; i++){
            cin >> b[i]; 
        }
        for(int i = 1; i<=m; i++){
            cin >> c[i]; 
            freq[c[i]]++;
        }

        int scape = -1;
        for(int i = 1; i<=n; i++){
            if(b[i] == c[m]){
                scape = i;
                break;
            }
        }
        if(scape == -1){
            cout << "NO\n";
            continue; //the last painter will hinder our progress
        }

        for(int i = 1; i<=n; i++){
            if(a[i] != b[i]){
                adj[b[i]].push_back(i);
            }
        }
        bool solv = 1;
        for(int i = 1; i<=n; i++){
            if(freq[i] < adj[i].size()) solv = 0;
        }
        if(!solv){
            cout << "NO\n";
            continue; //there are not enough painters
        }
        cout << "YES\n";
        for(int i = 1; i<=m; i++){
            if(adj[c[i]].size()){
                cout << adj[c[i]].back() << " ";
                adj[c[i]].pop_back();
            }else{
                cout << scape << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}