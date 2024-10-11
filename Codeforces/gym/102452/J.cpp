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

const int P = 1e9 + 7;
int m;
int f[5005][65][65];
vector<int> d, p(5005);

inline i64 digit(int k, int sum, int res, bool lead, bool limit) {
	if(k < 0) return res == 0 && lead == 0;
	if(~f[k][sum][res] && !lead && !limit) return f[k][sum][res];

	i64 ret = 0;
	for(int i = 0; i <= (limit ? d[k] : 9); i++)
		ret += digit(k - 1, (sum + i) % m, (res + (p[k] - sum + m) * i) % m, lead && (i == 0), limit && (i == d[k]));
	if(!lead && !limit) f[k][sum][res] = ret % P;
	return ret % P;
}

int main() {

	int cas = read();
	while(cas--) {
		string L, R;
		cin >> L >> R;
		m = read();

		p[0] = 1;
		for(int i = 1, ss = max(L.size(), R.size()); i < ss; i++) p[i] = p[i - 1] * 10 % m;

		i64 foo = 0;
		d.clear();
		for(int i = int(R.size()) - 1; ~i; i--) {
			d.push_back(R[i] - '0');
			for(int j = 0; j < m; ++j)
				for(int k = 0; k < m; ++k) f[i][j][k] = -1;
		}
		foo = digit(int(R.size()) - 1, 0, 0, 1, 1);

		i64 bar = 0;
		d.clear();
		for(int i = int(L.size()) - 1; ~i; i--) {
			d.push_back(L[i] - '0');
			for(int j = 0; j < m; ++j)
				for(int k = 0; k < m; ++k) f[i][j][k] = -1;
		}
		bar = digit(int(L.size()) - 1, 0, 0, 1, 1);

		i64 baz = 0, qux = 0, quy = 0, sum = 0;
		for(int i = 0; i < int(L.size()); i++) qux += p[int(L.size()) - i - 1] * (L[i] - '0') % m, quy += sum * (L[i] - '0') % m, sum += L[i] - '0';
		baz = (qux % m == quy % m);

		printf("%lld\n", (foo - bar + baz + P) % P);
	}
	return 0;
}

