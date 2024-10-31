#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int B = 137;
const int P = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s;
	vector<string> a(1), b(1);
	while(cin >> s, s != "$") a.push_back(s);
	while(cin >> s, s != "$") b.push_back(s);

	int n = int(a.size()) - 1, m = int(b.size()) - 1;
	vector<u64> pow(m, 1);
	for(int i = 1; i < m; ++i) pow[i] = pow[i - 1] * B;

	i64 H = 0;
	map<string, int> last;
	for(int i = 1; i <= m; ++i) H = (H * B + (last.find(b[i]) != last.end() ? i - last[b[i]] : 0)) % P, last[b[i]] = i;

	vector<int> pre(n + 1, 0);
	last.clear();
	for(int i = 1; i <= n; ++i) pre[i] = last[a[i]], last[a[i]] = i;

	vector<int> nxt(n + 1, 0);
	last.clear();
	for(int i = n; i >= 1; --i) nxt[i] = last[a[i]], last[a[i]] = i;

	i64 now = 0;
	for(int i = 1; i <= m; ++i) now = (now * B + (pre[i] ? i - pre[i] : 0)) % P;

	for(int l = 1, r = m; r <= n; ++l, ++r) {
		if(now == H) {
			cout << l << "\n";
			break;
		}

		if(0 < nxt[l] && nxt[l] <= r) now = (now - (nxt[l] - l) * pow[r - nxt[l]] % P + P) % P;
		if(r < n) now = (now * B + (pre[r + 1] > l ? r + 1 - pre[r + 1] : 0)) % P;
	}

	return 0;
}
