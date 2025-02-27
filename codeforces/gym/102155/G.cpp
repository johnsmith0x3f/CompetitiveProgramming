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
const long double EPS = 1e-11;
int x[N], y[N];
long double k[N], l[N];

int main() {
	int n = read();

	for(int i = 0; i <= n; i++) x[i] = read(), y[i] = read();

	for(int i = 1; i <= n; i++) k[i] = (long double)(y[i] - y[i - 1]) / (x[i] - x[i - 1]);

	int m = n - 1;
	for(int i = 1; i <= m; i++) l[i] = (k[i + 1] - k[i]) / 2;

	long double lsum = 0.0;
	for(int i = 1; i <= m; i++) lsum += l[i];
	if(fabs(k[1] + lsum) > EPS || fabs(k[n] - lsum) > EPS) puts("No"), exit(0);

	long double ysum = 0.0, sumy = 0.0;
	for(int i = 1; i <= m; i++) ysum += l[i] * (x[i] - x[0]), sumy += l[i] * (x[n] - x[i]);
	if(fabs(y[0] - ysum) > EPS || fabs(y[n] - sumy) > EPS) puts("No"), exit(0);

	return puts("Yes"), 0;
}

