//#include <iostream>
//
//using namespace std;
//
//#define maxn 110
//#define maxW 510
//
//int max(int a, int b){
//    return (a > b) ? a : b;
//}
//
//int n, W, S;
//int wt[maxn], val[maxn], sz[maxn];
//int K[maxn][maxW][maxW];
//int main(){
//    cin >> n >> W >> S;
//    for(int i = 0; i < n; i++){
//        cin >> val[i] >> wt[i] >> sz[i];
//    }
//    int i, w, s;
//    for (i = 0; i <= n; i++){
//        for (w = 0; w <= W; w++){
//            for (s = 0; s <= S; s++){
//                if (i == 0 || w == 0 || s == 0){
//                    K[i][w][s] = 0;
//                }
//                else if (wt[i - 1] <= w && sz[i-1] <= s){
//                    K[i][w][s] = max(val[i - 1] + K[i - 1][w - wt[i - 1]][s - sz[i - 1]], K[i - 1][w][s]);
//                }
//                else{
//                    K[i][w][s] = K[i - 1][w][s];
//                }
//            }
//        }
//    }
//    printf("%d\n", K[n][W][S]);
//    return 0;
//}
