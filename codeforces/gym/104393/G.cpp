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
	int x = read();

	vector<int> ans;
	for(int d = 1; d * d < x; ++d) {
		if(x % d) continue;
		if(((d + x / d) & 1) ^ 1) ans.push_back((d + x / d) / 2);
	}
	sort(ans.begin(), ans.end());

	int ss = ans.size();
	printf("%d\n", ss);
	for(int i = 0; i < ss; ++i) printf("%d%c", ans[i], " \n"[i == ss-1]);
	return 0;
}

