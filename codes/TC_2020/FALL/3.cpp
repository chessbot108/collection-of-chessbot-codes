//miles

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin,s);
    string x = "";
    for(int i = 0; i < s.length(); i++){
        x+=s[i];
        if(x == "LLL"){
            cout << "A";
            x = "";
        }else if(x == "SSL"){
            cout << "T";
            x = "";
        }else if(x == "SLL"){
            cout << "G";
            x = "";
        }else if(x == "SLS"){
            cout << "C";
            x = "";
        }
    }
}
