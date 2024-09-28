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

const int N = 105;
const int V = 1000005;
const int INF = 0x3f3f3f3f;
int a[N], b[N];
pair<int, bitset<N>> f[V + V];

int main() {
	int n = read();

	int p = read();
	for(int i = 0; i < n; ++i) a[i] = read();

	int q = read();
	for(int i = 0; i < n; ++i) b[i] = read();

	auto work = [=](int p, int *a, int q, int *b) -> void {
		f[0].first = 0, f[0].second.reset();
		for(int i = 1; i < V + V; ++i) f[i].first = INF, f[i].second.reset();
		for(int i = 0; i < n; ++i) {
			for(int j = p + a[i]; j >= a[i]; --j)
				if(f[j - a[i]].first + b[i] < f[j].first) f[j] = f[j - a[i]], f[j].first += b[i], f[j].second.set(n - i - 1);
			for(int j = p + a[i]; j >= p; --j)
				if(f[j].first < f[p].first) f[p] = f[j];
		}
	};

	work(p, a, q, b);
	if(f[p].first < q) puts("NO"), cout << f[p].second.to_string().substr(N - n, n) << "\n", exit(0);

	work(q, b, p, a);
	if(f[q].first < p) puts("NO"), cout << f[q].second.to_string().substr(N - n, n) << "\n", exit(0);

	return puts("YES"), 0;
}

