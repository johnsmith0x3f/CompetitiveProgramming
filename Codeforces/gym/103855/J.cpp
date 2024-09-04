#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 25;
const i64 INF = 0x3f3f3f3f3f3f3f3f;
int n, a[N][N];
i64 K, ans;
vector<i64> l[N][N][2], r[N][N][2];

void DFS(int step, int x, int y, int d, i64 inside, i64 around) {
	inside = max(inside, around), around = max(around, 0ll) + a[x][y];
	if(step >= n) {
		if(inside <= K) (~d ? l : r)[x][y][0].push_back(around);
		if(inside <  K) (~d ? l : r)[x][y][1].push_back(around);
		return;
	}
	if(1 <= x + d && x + d <= n) DFS(step + 1, x + d, y, d, inside, around);
	if(1 <= y + d && y + d <= n) DFS(step + 1, x, y + d, d, inside, around);
}

inline i64 calc(const int &x, const i64 &y, vector<i64> &a, vector<i64> &b) {
	sort(a.begin(), a.end()), sort(b.begin(), b.end());

	i64 res = 0;
	for(int i = int(a.size()) - 1, j = 0; ~i; --i) {
		while(j < int(b.size()) && a[i] + b[j] - x <= y) ++j;
		res += j;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> K;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) cin >> a[i][j];

	DFS(1, 1, 1, +1, -INF, -INF), DFS(1, n, n, -1, -INF, -INF);
	
	for(int i = n, j = 1; i >= 1; --i, ++j)
		ans += calc(a[i][j], K, l[i][j][0], r[i][j][0]) - calc(a[i][j], K-1, l[i][j][1], r[i][j][1]);
	cout << ans << endl;
	return 0;
}


