#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <list>
#include <queue>
#include <stack>
//#include <unordered_map>
//#include <unordered_set>
#include <functional>

using namespace std;

//code by Aaron

int material[10];

bool canSettle()
{
  return material[1] > 0 && material[2] > 0 && material[3] > 0 && material[5] > 0;
}

bool canTown()
{
  return material[5] >= 3 && material[4] >= 3 && material[1] >= 3;
}

bool cS()
{
  return material[1] > 0 && material[2] >= 3 && material[3] >= 3 && material[5] > 0;
}

void buildS()
{
  material[1] -= 1;
  material[2] -= 3;
  material[3] -= 3;
  material[5] -= 1;
}

bool canCity()
{
  return material[4] >= 3 && material[5] >= 2;
}

void buildCity()
{
  material[5] -= 2;
  material[4] -= 3;
}

int vp = 0;
int settlement = 0;
bool town = false;
int main() {
  for(int i = 1; i <= 5; i++)
  {
    cin >> material[i];
  }

  bool town2 = false;

  if(canTown())
  {
    town2 = true;
  }

  if(canSettle())
  {
    material[1] -= 1;
    material[2] -= 1;
    material[3] -= 1;
    material[5] -= 1;
    vp++;
    settlement++;
  }

  if(town2 && !canTown() && !cS())
  {
    cout << 2 << endl;
    return 1;
  }

  int index = -1;

  int sett = 0;
  while(cS())
  {
    settlement++;
    if(canTown())
      index = settlement;
    buildS();
    sett++;
    vp++;
  }

  //cout << settlement << endl;

  //for(int i = 1; i <= 5; i++)
  //cout << material[i] << endl;
  int cit = 0;
  while(settlement > 0 && canCity())
  {
    vp++;
    buildCity();
    settlement--;
    cit++;
  }

  if(canTown())
  {
    vp+=2;
  }
  else
  {
    if(material[5] > 1 && material[1] > 3)
    {
      vp++;
      material[5] -= 1;
    }
    else if(cit == 0 && sett - index == 1 && index != -1)
    {
      vp++;
    }
  }


  cout << vp << endl;
  return 1;

}
