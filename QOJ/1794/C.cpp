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

inline void work() {
	int n = read();
	vector<vector<int>> vec(n+2);
	for(int i = 1; i <= n; ++i) {
		int l = read(), r = read();
		vec[l].push_back(r);
	}

	for(int i = 1; i <= n; ++i) {
		auto &r = vec[i];
		if(r.empty()) return void(puts("0"));

		sort(r.begin(), r.end());
		for(int j = 0, ss = r.size(); j+1 < ss; ++j) {
			if(r[j] == r[j+1]) return void(puts("0"));
			vec[r[j]+1].push_back(r[j+1]);
		}
	}
	puts("1");
}

int main() {
	int cas = read();
	while(cas--) work();
	return 0;
}

