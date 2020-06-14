// xjoi_algoithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <utility>
#include <vector>
#define max_v 1010
using namespace std;
class disj_set {
	int parent[max_v], rank[max_v], n;
public:
	disj_set(int n) {
		this->n = n;
		make_set();
	}
	void make_set() {
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}
	int find(int index) {
		if (index != parent[index]) {
			parent[index] = find(parent[index]);
		}
		return parent[index];
	}
	void link(int x_rep, int y_rep) {
		if (rank[x_rep] > rank[y_rep]) {
			parent[y_rep] = x_rep;
		}
		else {
			parent[x_rep] = y_rep;
			if (rank[x_rep] == rank[y_rep]) {
				rank[y_rep]++;
			}
		}
		
	}
	void Union(int x, int y) {
		int x_rep = find(x);
		int y_rep = find(y);
		link(x_rep, y_rep);
	}
};



int main()
{
	
}
