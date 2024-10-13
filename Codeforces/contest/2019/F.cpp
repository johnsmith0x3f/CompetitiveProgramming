#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
constexpr T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c) ^ 1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? x : -x;
}

const int N = 2e5 + 5;
int a[N], fa[N], siz[N];
map<int, vector<int>> id;

int find(const int &x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

inline void merge(const int &u, const int &v) {
	int fu = find(u), fv = find(v);
	if(a[fu] > a[fv]) swap(fu, fv);
	fa[fu] = fv, siz[fv] += siz[fu];
}

int main() {
	int cas = read();
	while(cas--) {
		int n = read();
		for(int i = 1; i <= n; i++) a[i] = read();

		id.clear();
		for(int i = 1; i <= n; i++) id[a[i]].push_back(i);
		for(int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;

		for(auto it = id.rbegin(); it != id.rend(); it++) {
			vector<int> vv = it->second;
			for(int x : vv) {
				if(x > 1 && a[find(x - 1)] > a[x]) merge(x - 1, x);
				if(x < n && a[find(x + 1)] > a[x]) merge(x + 1, x);
			}
		}
	}

	return 0;
}
