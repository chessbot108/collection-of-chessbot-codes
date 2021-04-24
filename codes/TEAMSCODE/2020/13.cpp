//we all worked on this


#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>



using namespace std;

int notroot[11000];
    vector<int> adj[11000];
    vector<int> adj2[11000];

int a = 0;
int maxi = 0;


int depth(int cur, int p){
    int ret = 0;
    for(int i = 0; i < adj[cur].size(); i++){
        if(adj[cur][i] == p) continue;
       ret = max(ret,depth(adj[cur][i], cur));
    }
    if(maxi < ret){
      maxi = ret;
      a = cur;
    }
    return ret+1;
}

int main(){
    int n; cin >> n;
    string s;
    int root = 0;
        getline(cin,s);
    memset(notroot,0, sizeof notroot);
    for(int i = 0; i < n; i++){
        getline(cin, s);
        int p = (s[0]-'0')-1;
        for(int j = 2; j < s.length(); j+=2){
            int c = (s[j]-'0')-1;
            notroot[c] = 1;
            adj[p].push_back(c);
            adj[c].push_back(p);
            adj2[c].push_back(c);
        }
    }
    for(int i = 0; i < n; i++){
        if(!notroot[i]){
            root = i;
            break;
        }
    }
    cout << depth(root, 0) << endl;
    maxi = 0;
    cout << depth(a, 0) << endl;
    return 0;
}
