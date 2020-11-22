//code by daniel

#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define maxt 100000000
int n, m;
int x_dir[4] = {1, -1, 0, 0};
int y_dir[4] = {0, 0, 1, -1};
int xf, yf;
vector<vector<int>> v;

int dfs(int x, int y, int cur_dir, int turns, set<pair<int, int>> vis){
    if(x == xf && y == yf){
        return turns;
    }
    if(x < 0 || x >= n || y < 0 || y >= m || vis.find(make_pair(x, y)) != vis.end()){
        return maxt;
    }
    if(v[x][y] == 1){
        return maxt;
    }
    int minturns = maxt;
    vis.insert(make_pair(x, y));
    for(int i = 0; i < 4; i++){
        if(i == cur_dir){
            minturns = min(minturns, dfs(x+x_dir[i], y+y_dir[i], cur_dir, turns, vis));
        }
        else{
            minturns = min(minturns, dfs(x+x_dir[i], y+y_dir[i], i, turns+1, vis));
        }
    }
    return minturns;
}

int main(){
    cin >> n >> m;
    v.resize(n);
    for(int i = 0; i < n; i++){
        v[i].resize(m);
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
        }
    }

    int x1, y1;
    cin >> x1 >> y1 >> xf >> yf;
    --x1; --y1; --xf; --yf;
    set<pair<int, int>> empty;
    cout << dfs(x1, y1, -1, 0, empty)-1 << endl;
}
