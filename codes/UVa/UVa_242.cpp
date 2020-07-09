

#include <iostream>

#include <cmath>

#include <algorithm>

#include <cstring>

#include <cstdio>

#include <cstdlib>

#include <vector>

#include <map>

#include <stack>

//#include <bitset>

#include <queue>

//#include <unordered_map>

#include <set>

#include <string>

#include <sstream>

#include <functional>

#include <list>

#include <fstream>



#define cont continue

#define int_max 0x3fffffff

#define byte_max 0x3f

#define max_v 20

#define MAX 2000



using namespace std;



int stamps[max_v][max_v];

int N[max_v];

int dp[MAX];

vector<pair<pair<int, int>, pair<int, int> > > sol;



int main(){

    int n;

    while(cin >> n){

        if(n == 0) break;

        

        memset(stamps, 0, sizeof(stamps));

        memset(N, 0, sizeof(N));

        memset(dp, 0, sizeof(dp));

        sol.clear();

        

        int S;

        cin >> S;

        for(int i = 0; i<S; i++){

            cin >> N[i];

            for(int j = 0; j<N[i]; j++){

                cin >> stamps[i][j];   

            }

        }

        

        //cout << "input works!!\n";

        

        for(int i = 0; i<S; i++){

            

            dp[0] = 0;

            

            for(int j = 1; j <= stamps[i][N[i] - 1] * n + 1; j++){

                

                int& cur = dp[j];

                cur = int_max;

                

                for(int k = 0; k<N[i]; k++){

                    if(j < stamps[i][k]) cont;

                    

                    cur = min(cur, dp[j - stamps[i][k]] + 1); 

                    

                }

                //printf("%d %d\n", j, cur);

                if(cur > n){

                    sol.push_back(make_pair(make_pair(MAX - j, N[i]), make_pair(stamps[i][N[i] - 1], i)));

                    break;

                }

                

            }

            

        }

        

        sort(sol.begin(), sol.end());

        

        printf("max coverage = %d :", (MAX - sol[0].first.first) - 1);

        

        for(int i = 0; i<N[sol[0].second.second]; i++){

            printf(" %d", stamps[sol[0].second.second][i]);   

        }

        

        cout << endl;

        

        

    }

    

    

    

    

    

    return 0;

}


