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

#define max_v 110000
#define LOGN 50
#define int_max 0x3f3f3f3f
#define cont continue
#define byte_max 0x3f
#define pow_2(n) (1 << (n))
//tree
#define lsb(n) ((n)&(-(n)))
#define LC(n) (((n) << 1) + 1)
#define RC(n) (((n) << 1) + 2)
#define LOG2(n) ((int)(ceil(log2((n)))))
using namespace std;

void setIO(const string& file_name){
	freopen((file_name+".in").c_str(), "r", stdin);
	freopen((file_name+".out").c_str(), "w+", stdout);
}


/**
 * the suffix array is split into 2 parts.
 * sorting the suffixes and computing the lcp
 * then it's rmq with sparse table. :/
 * 
 * i'll be following teacher's template code for this.
 * i get the alg, but the code will be hard
 *
 * sorting will be with binary lifting and radix sort
 *  so the string will be partitioned by each character,
 *  the i will find the rank of each character
 *  then every substring of in the string will be formed by 2 characters, 
 *  i can sort the substring by the order of the characters
 *  and so on for subtrings length 4
 *  instead of checking all 4 characters, i will compare the ranking of the 
 *  2 size 2 substrings it consists of
 *
 *  and since the ranking will be less than n, i can radix sort on it1
 *
 *  making an n log n sorting alg
 * 
 *  the proof for lcs is too long to write here. :/
**/

char str[max_v];
int sa[max_v], tmp[max_v], rank[max_v], buckets[max_v], lcp[max_v]; //using buckets for readability


int main(){
	
	return 0;
}

