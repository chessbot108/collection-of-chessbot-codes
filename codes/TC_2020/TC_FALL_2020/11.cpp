//code by miles


#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct Node{
    int states[3];
    int count;
};
int main(){
    int comp[3];
    cin >> comp[0] >> comp[1] >> comp[2];
    if(comp[0]%2 == 1){
        cout << "NO";
        return 0;
    }
    int vis[comp[0]][comp[1]][comp[2]];
    memset(vis,0,sizeof vis);
    Node start;
    start.states[0] = comp[0];
    start.states[1] = 0;
    start.states[2] = 0;
    start.count = 0;
    vis[comp[0]][0][0] = 1;
    queue<Node> q;
    q.push(start);
    cout << vis[2][3][1] << endl;
    while(!q.empty()){
        Node top = q.front();
        q.pop();
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i == j){
                    continue;
                }
                int compacity = comp[j]-top.states[j];
                int maxmove = top.states[i];
                int mvamount = min(compacity,maxmove);
                Node node;
                node.states[0] = top.states[0];
                node.states[1] = top.states[1];
                node.states[2] = top.states[2];
                node.states[i]-=mvamount;
                node.states[j]+=mvamount;
                node.count = top.count+1;
                for(int one = 0; one < 3; one++){
                    for(int two = 0; two < 3; two++){
                        if(one == two){
                            continue;
                        }
                        if(node.states[one] == node.states[two] && node.states[one] == comp[0]/2){
                            cout << node.count;
                            return 0;
                        }
                    }
                }
                if(!vis[node.states[0]][node.states[1]][node.states[2]]){
                    
                   int a = node.states[0], b = node.states[1], c = node.states[2];
                   vis[a][b][c] = 1; 
                   q.push(node);
                }
            }
        }
    }
    cout << "NO";
}
