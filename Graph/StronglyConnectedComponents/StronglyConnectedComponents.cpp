/*
 * StronglyConnectedComponents.cpp
 *
 *  Created on: Mar 30, 2015
 *      Author: dima
 */

#include <bits/stdc++.h>

const int N = int(1e5);

std::vector< std::vector<int> > g, gTr;
bool us[N];
int vert[N];
int curComp[N];
int compRef[N];
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

void dfsTr(int v) {
	us[v] = true;
	curComp[h++] = v;
	for (int u : gTr[v]) {
		if (us[u] == false) {
			dfsTr(u);
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	g.resize(n);
	gTr.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u, --v;

		g[u].push_back(v);
		gTr[v].push_back(u);
	}

	h = n;
	for (int v = 0; v < n; v++) {
		if (us[v] == false) {
			dfs(v);
		}
	}

	memset(us, 0, sizeof(us));
	int col = 0;
	for (int i = 0; i < n; i++) {
		int v = vert[i];
		if (us[v] == false) {
			h = 0;
			dfsTr(v);

			for (int j = 0; j < h; j++) {
				compRef[curComp[j]] = col;
			}
			col++;
		}
	}

	for (int v = 0; v < n; v++) {
		printf("Vertex %d is in #%d SSC\n", v + 1, compRef[v] + 1);
	}
}