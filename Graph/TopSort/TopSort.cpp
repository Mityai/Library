/*
 * TopSort.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: dima
 */

#include <bits/stdc++.h>

const int N = int(1e5);

std::vector< std::vector<int> > g;
bool us[N];
int vert[N];
int h;

void dfs(int v) {
	us[v] = true;
	for (int u : g[v]) {
		if (us[u] == false) {
			dfs(u);
		}
	}

	vert[--h] = v;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	g.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;

		g[u].push_back(v);
	}

	h = n;
	for (int v = 0; v < n; v++) {
		if (us[v] == false) {
			dfs(v);
		}
	}

	puts("Sorted:");
	for (int i = 0; i < n; i++) {
		printf("%d ", vert[i] + 1);
	}
	printf("\n");
}
