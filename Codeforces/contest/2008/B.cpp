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

inline void solve() {
	int n = read();
	string s;
	cin >> s; s = '~' + s;
	int b = sqrt(n);
	if(b * b != n) return void(puts("No"));
	for(int l = 1, r = b; r <= n; l += b, r += b) {
		int flag = (s[l] == '1' && s[r] == '1');
		for(int i = l+1; i <= r-1; ++i)
			if(s[i] != '0' + (l == 1 || r == n)) flag = 0;
		if(!flag) return void(puts("No"));
	}
	puts("Yes");
}

int main() {
	int cas = read();
	while(cas--) solve();
	return 0;
}

