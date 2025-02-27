#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template <typename T = int>
constexpr T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c)^1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x<<1) + (x<<3) + (c^48), c = getchar();
	return f ? x : -x;
}

const int S = 502;
const int N = 100005;
int B[N], L[S], R[S];
int a[N], b[N], c[N], d[N], l[N], r[N], id[N];
i64 num[N], sum[S], ans[N];

int main() {
	int n = read(), m = read(), q = read(), s = sqrt(n) + 1;
	for(int i = 1; i <= n; ++i) c[i] = read();
	for(int i = 1; i <= m; ++i) b[i] = read(), a[i] = read();
	for(int i = 1; i <= q; ++i) d[i] = read(), l[i] = read(), r[i] = read(), id[i] = i;

	for(int i = 1; i <= n; ++i) B[i] = (i - 1) / s + 1;
	for(int i = 1; i <= n; ++i) {
		if(i % s == 1) L[B[i]] = i;
		if(i % s == 0) R[B[i]] = i;
	}
	R[B[n]] = n;

	sort(id+1, id+q+1, [](const int &x, const int &y) {
		return d[x] < d[y];
	});
	for(int i = 1, j = 1; i <= q; ++i) {
		while(j <= d[id[i]]) sum[B[b[j]]] += min(num[b[j]] + a[j], i64(c[b[j]])) - min(num[b[j]], i64(c[b[j]])), num[b[j]] += a[j], ++j;

		if(B[l[id[i]]] == B[r[id[i]]]) {
			for(int k = l[id[i]]; k <= r[id[i]]; ++k) ans[id[i]] += min(num[k], i64(c[k]));
		}
		else {
			for(int k = l[id[i]]; k <= R[B[l[id[i]]]]; ++k) ans[id[i]] += min(num[k], i64(c[k]));
			for(int k = L[B[r[id[i]]]]; k <= r[id[i]]; ++k) ans[id[i]] += min(num[k], i64(c[k]));
			for(int k = B[l[id[i]]]+1; k < B[r[id[i]]]; ++k) ans[id[i]] += sum[k];
		}
	}

	for(int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
	return 0;
}

