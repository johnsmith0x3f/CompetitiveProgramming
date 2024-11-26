#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int p[N], id[N];

struct Cyclic {
	int i, x, y, z;
};

bool operator < (const Cyclic &a, const Cyclic &b) {
	vector<pair<int, int>> va;
	va.emplace_back(id[a.i + 0], a.x), va.emplace_back(id[a.i + 1], a.y), va.emplace_back(id[a.i + 2], a.z);
	va.emplace_back(id[b.i + 0], b.i + 0), va.emplace_back(id[b.i + 1], b.i + 1), va.emplace_back(id[b.i + 2], b.i + 2);
	sort(va.begin(), va.end());

	vector<pair<int, int>> vb;
	vb.emplace_back(id[b.i + 0], b.x), vb.emplace_back(id[b.i + 1], b.y), vb.emplace_back(id[b.i + 2], b.z);
	vb.emplace_back(id[a.i + 0], a.i + 0), vb.emplace_back(id[a.i + 1], a.i + 1), vb.emplace_back(id[a.i + 2], a.i + 2);
	sort(vb.begin(), vb.end());

	for(int i = 0; i < 6; ++i)
		if(va[i] != vb[i]) return va[i] < vb[i];
	return 0;
}

inline void solve() {
	int n, k;
	cin >> n >> k;

	for(int i = 1; i <= n; ++i) cin >> p[i], id[p[i]] = i;

	if(n % 2 == 0) {
		if(k > 1) {
			cout << "-1" << '\n';
			return;
		}

		vector<int> ans(n + 1);
		for(int i = 1; i <= n; i += 2) ans[id[i]] = i + 1, ans[id[i + 1]] = i;

		for(int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];

		return;
	}

	vector<Cyclic> q;
	for(int i = 1; i + 2 <= n; i += 2) {
		q.push_back({ i, i + 1, i + 2, i + 0 });
		q.push_back({ i, i + 2, i + 0, i + 1 });
	}

	if(k-- > q.size()) {
		cout << "-1" << '\n';
		return;
	}

	sort(q.begin(), q.end());
	for(auto c : q) cout << c.i << ' ' << c.x << ' ' << c.y << ' ' << c.z << '\n';

	vector<int> ans(n + 1);
	for(int i = 1; i < q[k].i; i += 2) ans[id[i]] = i + 1, ans[id[i + 1]] = i;
	ans[id[q[k].i]] = q[k].x, ans[id[q[k].i + 1]] = q[k].y, ans[id[q[k].i + 2]] = q[k].z;
	for(int i = q[k].i + 3; i <= n; i += 2) ans[id[i]] = i + 1, ans[id[i + 1]] = i;

	for(int i = 1; i <= n; ++i) cout << ans[i] << " \n"[i == n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--) solve();
	
	return 0;
}
