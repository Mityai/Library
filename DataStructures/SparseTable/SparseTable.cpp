/*
 * SparseTable.cpp
 *
 * minimum on range
 * [0..n)
 * Requests:
 * 0 <= l <= r < n
 *
 *  Created on: Mar 29, 2015
 *      Author: dima
 */

#include <bits/stdc++.h>

const int N = int(1e5);
const int K = 20;

int n;
int a[N];
int f[K][N];
int logK[N];

void calculate() {
	for (int i = 0; i < n; i++) {
		f[0][i] = a[i];
	}

	for (int k = 0; (1 << (k + 1)) < n; k++) {
		for (int i = 0; i < n; i++) {
			f[k + 1][i] = std::min(f[k][i], f[k][i + (1 << k)]);
		}
	}

	for (int i = 2; i < n; i++) {
		logK[i] = logK[i >> 1] + 1;
	}
}

int getMin(int L, int R) {
	int k = logK[R - L + 1];
	return std::min(f[k][L], f[k][R - (1 << k) + 1]);
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	calculate();

	int q;
	scanf("%d", &q);

	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d%d", &l, &r);

		printf("Minimum on [%d..%d] = %d\n", l, r, getMin(l - 1, r - 1));
	}
}
