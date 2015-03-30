/*
 * DisjointSetUnion.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: dima
 */

#include <bits/stdc++.h>

const int N = int(1e5);

int p[N];
int rnk[N];

void makeSet(int x) {
	p[x] = x;
	rnk[x] = 0;
}

int findSet(int x) {
	return x == p[x] ? x : p[x] = findSet(p[x]);
}

void unionSets(int x, int y) {
	x = findSet(x);
	y = findSet(y);

	if (x == y) return;

	p[y] = x;

	if (rnk[x] < rnk[y]) {
		std::swap(x, y);
	}

	p[y] = x;

	if (rnk[x] == rnk[y]) {
		rnk[x]++;
	}
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		makeSet(i);
	}

	int q;
	scanf("%d", &q);

	for (int i = 0; i < q; i++) {
		char c;
		int v, u;
		scanf(" %c%d%d", &c, &v, &u);

		if (c == '+') {
			unionSets(v, u);
		} else if (c == '?') {
			findSet(v) == findSet(u) ? puts("Yes") : puts("No");
		}
	}
}
