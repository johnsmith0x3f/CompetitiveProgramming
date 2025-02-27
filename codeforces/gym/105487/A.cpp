#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int z0, h, u0, v0, u1, v1;
	cin >> z0 >> h >> u0 >> v0 >> u1 >> v1;

	int q;
	cin >> q;
	while(q--) {
		int x, y, z;
		cin >> x >> y >> z;

		cout << (min(u0, u1) <= x && x <= max(u0, u1) && min(v0, v1) <= y && y <= max(v0, v1) && z0 <= z && z <= z0 + h ? "YES" : "NO") << '\n';
	}

	return 0;
}
