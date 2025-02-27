#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 6e6 + 5;
const int P = 998244353;

struct PAM {
	int n, tot, las, len[N], fail[N], to[N][10], num[N];
	char s[N];

	PAM() {
		n = las = 0, tot = -1;
		newnode(0), newnode(-1);
		fail[0] = 1, s[0] = '~';
	}

	inline int newnode(const int &l) {
		len[++tot] = l, fail[tot] = 0;
		memset(to[tot], 0, sizeof(to[tot]));
		return tot;
	}

	inline int findfail(const int &i, int x) {
		while(s[i - len[x] - 1] != s[i]) x = fail[x];
		return x;
	}

	inline void insert(char c, const int &v) {
		s[++n] = c, c -= '0';

		int now = findfail(n, las);
		if(to[now][c] == 0) {
			int nxt = newnode(len[now] + 2);
			fail[nxt] = to[findfail(n, fail[now])][c], to[now][c] = nxt;
		}
		las = to[now][c], num[las] += v;
	}

	inline i64 count() {
		i64 res = 0;
		for(int i = tot; i >= 2; --i) num[fail[i]] += num[i];
		for(int i = 2; i <= tot; ++i)
			if(len[i] <= n / 2) res = (res + 1ll * num[i] * num[i] % P * len[i] % P) % P;

		return res;
	}
} pam;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;

	for(int i = 0; i < n; ++i) pam.insert(s[i], 0);
	for(int i = 0; i < n; ++i) pam.insert(s[i], 1);
	cout << pam.count() << "\n";

	return 0;
}
