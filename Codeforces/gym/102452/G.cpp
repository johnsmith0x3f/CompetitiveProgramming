#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template <typename T = int>
constexpr T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c) ^ 1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
	return f ? x : -x;
}

const int N = 1e5 + 5;
const int INF = 1e9;
int p[N], c[N];

int main() {
	int K = read(), cur = 1, las = 0;

	if(K == 1) puts("2\n1\n1 2\n"), exit(0);

	while(K > 1) {
		p[cur] = las, c[cur] = (K & 1) ? log2(K) + 1 : INF;
		p[cur + 1] = cur, c[cur + 1] = 1;
		p[cur + 2] = cur + 1, c[cur + 2] = 1;
		las = cur, cur += 3, K >>= 1;
	}
	p[cur] = las, c[cur] = 1;

	printf("%d\n", cur);
	for(int i = 2; i <= cur; ++i) printf("%d%c", p[i], " \n"[i == cur]);
	for(int i = 1; i <= cur; ++i) printf("%d%c", c[i], " \n"[i == cur]);
	return 0;
}

