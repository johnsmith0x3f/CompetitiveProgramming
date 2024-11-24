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

const int N = 10005;
const int M = 105;
int a[M];

int main() {
	int n = read(), m = read(), num = 0;
	for(int i = 1; i <= m; ++i) a[i] = read(), num += a[i] & 1;

	if(num > 2 - (n & 1)) puts("Impossible"), exit(0);

	if(m == 1) {
		if(a[1] == 1) printf("1\n1\n1\n"), exit(0);
		else printf("%d\n2\n%d 1\n", n, n-1), exit(0);
	}

	for(int i = 1; i < m; ++i)
		if(a[i] & 1) swap(a[m], a[i]);
	for(int i = 1; i < m; ++i)
		if(a[i] & 1) swap(a[1], a[i]);

	for(int i = 1; i <= m; ++i) printf("%d%c", a[i], " \n"[i == m]);

	if(a[1] == 1) printf("%d\n", m-1);
	else printf("%d\n%d ", m, a[1]-1);

	for(int i = 2; i <= m; ++i) printf("%d%c", a[i] + (i == m), " \n"[i == m]);

	return 0;
}

