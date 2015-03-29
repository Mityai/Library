/*
 * FenwickTree.cpp
 *
 * [0..n)
 * Sum, Add, Set
 * Requests:
 * 0 <= l <= r < n
 *
 *  Created on: Mar 29, 2015
 *      Author: dima
 */

#include <bits/stdc++.h>

const int N = int(1e6);

int n;
int fenw[N];
int a[N];

inline int up(int x) {
	return x | (x + 1);
}

inline int down(int x) {
	return x & (x + 1);
}

void add(int pos, int val) {
	for (int i = pos; i < n; i = up(i)) {
		fenw[i] += val;
	}
}

int getSum(int pos) {
	int ret = 0;
	for (int i = pos; i >= 0; i = down(i) - 1) {
		ret += fenw[i];
	}
	return ret;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);

		add(i, a[i]);
	}

	int q;
	scanf("%d", &q);

	for (int i = 0; i < q; i++) {
		std::string request;
		std::cin >> request;

		if (request == "add") {
			int pos, val;
			scanf("%d%d", &pos, &val);

			--pos;
			add(pos, val);
			a[pos] += val;
		} else if (request == "set") {
			int pos, val;
			scanf("%d%d", &pos, &val);

			--pos;
			add(pos, val - a[pos]);
			a[pos] = val;
		} else if (request == "sum") {
			int l, r;
			scanf("%d%d", &l, &r);

			printf("%d\n", getSum(r - 1) - getSum(l - 2));
		}
	}
}