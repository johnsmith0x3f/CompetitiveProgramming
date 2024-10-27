#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;

		vector<int> p(n + 1);
		for(int i = 1; i <= n; ++i) cin >> p[i];

		int ans = 0;
		vector<bool> vst(n + 1, 0);
		for(int i = 1; i <= n; ++i) {
			if(vst[i]) continue;

			int num = 0;
			for(int j = i; !vst[j]; j = p[j]) ++num, vst[j] = 1;
			ans += num / 2 - ((num & 1) ^ 1);
		}
		cout << ans << "\n";
	}
	return 0;
}
