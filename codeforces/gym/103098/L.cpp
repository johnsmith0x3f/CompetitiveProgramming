#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define int i64

template <typename T = int>
constexpr T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c)^1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x<<1) + (x<<3) + (c^48), c = getchar();
	return f ? x : -x;
}

int tet[6][3] = {
	{ 7, 0, 0 },
	{ 1, 1, 1 },
	{ 2, 3, 0 },
	{ 1, 3, 0 },
	{ 3, 1, 0 },
	{ 3, 2, 0 }
};

const int P = 1000000007;

struct Matrix {
	int n, m, a[64][64];
	Matrix() {
		n = m = 0;
		for(int i = 0; i < 64; ++i)
			for(int j = 0; j < 64; ++j) a[i][j] = 0;
	}
	Matrix operator * (const Matrix &o) const {
		Matrix res;
		res.n = n, res.m = o.m;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < o.m; ++j) {
				for(int k = 0; k < m; ++k) res.a[i][j] += a[i][k] * o.a[k][j] % P, res.a[i][j] %= P;
			}
		}
		return res;
	}
	Matrix operator ^ (int b) const {
		Matrix res, c = *this;
		res.n = res.m = n;
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j) res.a[i][j] = 0;
		while(b) {
			if(b&1) res = res * c;
			c = c * c, b >>= 1;
		}
		return res;
	}
} A, B;

int a[64][64], sss[64], sst[64], rev[64];
int f[512][512], g[512][512];

signed main() {

	for(int s = 0; s < 512; ++s) f[s][s] = 1;
	for(int i = 0; i < 6; ++i) {
		for(int j = 0; j < 3; ++j) {
			int x = tet[i][0] << j, y = tet[i][1] << j, z = tet[i][2] << j;
			if(x > 7 || y > 7 || z > 7) continue;
			int tile = x << 6 | y << 3 | z;

			for(int s = 0; s < 512; ++s)
				for(int t = 0; t < 512; ++t)
					if((t & tile) == 0) g[s][t|tile] += f[s][t];
			for(int s = 0; s < 512; ++s)
				for(int t = 0; t < 512; ++t) f[s][t] += g[s][t], g[s][t] = 0;
		}
	}
	for(int i = 0; i < 512; ++i) {
		for(int j = 0; j < 512; ++j) {
			if(((i & 7) == 0) && (j & (7 << 6)) == (7 << 6)) a[i >> 3][j & ((7 << 6)-1)] += f[i][j];
		}
	}
	int num = 0;
	for(int i = 0; i < 64; ++i) {
		sss[i] = 0, sst[i] = 0;
		for(int j = 0; j < 64; ++j) {
			if(i != j) sss[i] += a[i][j], sst[i] += a[j][i];
		}
		if(sss[i] && sst[i]) rev[num++] = i;
	}
	B.n = B.m = num;
	for(int i = 0; i < num; ++i) {
		for(int j = 0; j < num; ++j) {
			B.a[i][j] = a[rev[i]][rev[j]];
//			printf("%d ", B.a[i][j]);
		}
//		printf("\n");
	}

	A.n = num, A.m = 1;
	for(int i = 0; i < num; ++i) A.a[i][0] = a[56][rev[i]];
	
//	Matrix tmp = B * A;
//	printf("%lld %lld\n", tmp.n, tmp.m);
//	for(int i = 0; i < tmp.n; ++i) {
//		for(int j = 0; j < tmp.m; ++j) {
//			printf("%lld ", tmp.a[i][j]);
//		}
//		printf("\n");
//	}

	int cas = read();
	while(cas--) {
		int n = read();
		if(n == 1) {
			puts("1");
			continue;
		}
		Matrix ans = (B ^ (n-2)) * A;
		printf("%lld\n", ans.a[num-1][0]);
	}
	return 0;
}

