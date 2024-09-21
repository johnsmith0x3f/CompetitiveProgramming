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
	int n = read(); i64 rating = 1500;
	for(int i = 1; i <= n; ++i)
		if((rating += read()) >= 4000) printf("%d\n", i), exit(0);
	return puts("-1"), 0;
}

