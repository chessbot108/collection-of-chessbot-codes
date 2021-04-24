//code by aaron
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stack>
#include <cmath>
#include <stdio.h>
 
using namespace std;
 
string n;
 
int prec(char a)
{
  if(a == '+' || a == '-')
    return 1;
  else if(a == '/' || a == '*')
    return 2;
  else if(a == '^')
    return 3;
  else
    return 0;
}
 
string convertToPost(string b)
{
  string a;
  stack<char> st;
  for(int i = 0 ; i < b.length(); i++)
  {
    char c = b[i];
    //cout << "char " << c << endl;
    if(c >= '0' && c <= '9' || c == '.')
    {
      a += c;
    }
    else if(c == '(')
    {
      st.push(c);
      //cout <<"YES" << endl;
    }
    else if(c == ')')
    {
      //cout << c << endl;
      //cout << st.size() << endl;
      while(!st.empty() && st.top() != '(')
      {
        char d = st.top();
        st.pop();
        //cout << d << endl;
        a += d;
      }
      //cout << st.empty() << endl;
      //cout << (st.top() == '(') << endl;
      if(!st.empty() && st.top() == '(')
      {
        char d = st.top();
        st.pop();
        //cout << d << endl;
      }
    }
    else
    {
      a += ' ';
      while(!st.empty() && prec(b[i]) <= prec(st.top()))
      {
        char d = st.top();
        st.pop();
        a += d;
      }
 
      st.push(b[i]);
    }
 
    //cout << "STACK SIZE " << st.size() << endl;
  }
 
  while(!st.empty())
  {
    a += st.top();
    st.pop();
  }
 
  return a;
}
 
void convertToNum(string a)
{
  stack<double> st;
 
  for(int i = 0; i < a.length(); i++)
  {
    char b = a[i];
    if(b == ' ')
      continue;
    //cout << b << endl;
    int aa = i;
    if(b >= '0' && b <= '9' || b == '.')
    {
      while(a[i] >= '0' && a[i] <= '9' || a[i] == '.')
      {
        i++;
      }
      //cout << stold(a.substr(aa, i)) << " " << i << endl;
      st.push(stold(a.substr(aa, i)));
      i--;
    }
    else
    {
      double bb = st.top();
      st.pop();
      double aa = st.top();
      st.pop();
      double cc;
 
      if(b =='+')
        cc = aa + bb;
      else if(b == '-')
        cc = aa - bb;
      else if(b == '*')
        cc = aa * bb;
      else if(b == '/')
        cc = aa / bb;
      else if(b == '^')
        cc = pow(aa , bb);
      //else
        //cout << "ERRRORORORORORORORORO" << endl;
 
      st.push(cc);
 
      //cout << cc << endl;
       
    }
  }
 
  printf("%.3lf\n", st.top());
}
 
int main() {
 
  cin >> n;
   
  string a = convertToPost(n);
 
  convertToNum(a);
  return 0;
}
