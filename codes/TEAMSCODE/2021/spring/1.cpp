//code by pikaninja
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
int main() {
   int n;
   cin >> n;
   vector<int> record = vector<int>();
   string s;
   cin >> s;
   int a[n];
   for(int i = 0; i < n; i++){
       cin >> a[i];
   }
   for(int i = 0; i < n; i++){
       char c = s[i];
       if(a[i]){
           c = record[record.size()-a[i]];
       }
       cout << c;
       record.push_back(c);
   }
}
