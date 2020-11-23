//daniel

//#include <iostream>
//#include <vector>
//using namespace std;
//int f [1000][1000];
//int bestk [1000][1000];
//void towers(int start, int goal, vector <int> extra, int disks){
//    if(disks == 1){
////        cout << start << " -> " << goal << endl;
//        return;
//    }
//    else{
//        vector <int> nv1;
//        vector <int> nv2;
//        for(int i = 1; i < extra.size(); i++){
//            nv1.push_back(extra[i]);
//            nv2.push_back(extra[i]);
//        }
//        nv1.push_back(goal);
//        towers(start, extra[0], nv1, bestk[disks][extra.size()+2]);
//        towers(start, goal, nv2, disks-bestk[disks][extra.size()+2]);
//        nv1[nv1.size()-1] = start;
//        towers(extra[0], goal, nv1, bestk[disks][extra.size()+2]);
//    }
//}
//int main(int argc, const char * argv[]) {
//    // iteration for solution
//    int n,r;
//    cin >> n >> r; // N disks, R pegs
//    // f[a][b] = a disks, b pegs.
//
//    for(int i = 3; i < r+1; i++){
//        f[1][i] = 1;
//    }
//    for(int j = 0; j < n+1; j++){
//        f[j][2] = 10000000;
//    }
//    f[1][2] = 1;
//    for(int i = 3; i < r+1; i++){
//        for(int j = 2; j < n+1; j++){
//            int best = 2147483647;
//            for(int k = 1; k < j; k++){
//                if(best > 2*f[k][i]+f[j-k][i-1]){
//                    bestk[j][i] = k;
//                    best = 2*f[k][i]+f[j-k][i-1];
//                }
//            }
//            f[j][i] = best;
//        }
//    }
//    cout << f[n][r] << endl;
//    vector <int> v;
//    for(int i = 2; i < r; i++){
//        v.push_back(i);
//    }
//    towers(1, r, v, n);
//    return 0;
//}
//
