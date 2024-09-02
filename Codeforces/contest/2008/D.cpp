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

int main() {
	int cas = read();
	while(cas--) {
		int n = read();
		vector<int> p(n+1);
		for(int i = 1; i <= n; ++i) p[i] = read();
		string s;
		cin >> s; s = '~' + s;

		vector<int> ans(n+1), vst(n+1, 0);
		for(int i = 1; i <= n; ++i) {
			if(vst[i]) continue;
			int num = (s[i] == '0');
			for(int j = p[i]; j != i; j = p[j]) num += (s[j] == '0');
			for(int j = p[i]; !vst[j]; j = p[j]) ans[j] = num, vst[j] = 1;
		}
		for(int i = 1; i <= n; ++i) printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}

