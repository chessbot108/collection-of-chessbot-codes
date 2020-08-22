
//code by daniel. done after the test
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 100010

int n, m;
vector<int> v[maxn];

vector<int> traverse(vector<int> path, int ind){
    path.push_back(ind);
    if(v[ind].size() == 0){
        return path;
    }
    
    vector<int> longest = path;
    for(int i = 0; i < v[ind].size(); i++){
        int next = v[ind][i];
        if(find(path.begin(), path.end(), next) == path.end()){
            vector<int> comp = traverse(path, next);
            if(comp.size() > longest.size()){
                longest = comp;
            }
        }
    }
    return longest;
}

void find_median(){
    vector<int> empty;
    vector<int> path;
    path = traverse(empty, 1);
    int a = path[path.size()-1];
    path = traverse(empty, a);
    if(path.size()%2 == 0){
        int x = path[(path.size()-1)/2];
        int y = path[path.size()/2];
        printf("%d %d\n", min(x, y), max(x, y));
    }
    else{
        int x = path[path.size()/2];
        printf("%d", x);
    }
    return;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b; scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    find_median();
    return 0;
}
