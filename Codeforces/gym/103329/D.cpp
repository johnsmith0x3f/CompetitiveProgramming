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

const int N = 1003;
const int M = 1000006;
int inq[N], vst[N][N];
int l[M], id[M];
set<int> to[N];
vector<int> ans[M];

inline void solve() {
	int n = read(), k = read();
	for(int i = 1; i <= n; ++i) vst[i][i] = 1;
	for(int i = 1; i <= k; ++i) l[i] = read(), id[i] = i;
	sort(id+1, id+k+1, [](const int &x, const int &y) {
		return l[x] > l[y];
	});
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(i != j) to[i].insert(j);

	int pos = 1, now = 1;
	for(int i = 1; i <= k; ++i) {
		ans[id[i]].push_back(now = pos);
		for(int j = 1; j <= l[id[i]]; ++j) {

		}
	}
	for(int i = 1; i <= k; ++i)
		for(int j = 0; j < int(ans[i].size()); ++j) printf("%d%c", ans[i][j], " \n"[j == int(ans[i].size())-1]);
}

int main() {
	int cas = read();
	while(cas--) solve();
	return 0;
}

