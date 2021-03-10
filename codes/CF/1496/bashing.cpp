
// Example program
#include <iostream>
#include <string>
using namespace std;
int main()
{
    cout << (int)1e2 << endl;
    for(int i = 0; i<1e2; i++){
        if(i%2 == 0) cout << 0 << " " <<  (long long)(1e8) << endl;
        else cout << (long long)(1e8) << " " << 0 << endl;
    }
    
    return 0;
}

