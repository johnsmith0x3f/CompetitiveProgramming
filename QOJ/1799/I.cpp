#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int cas;
    cin >> cas;
    while(cas--) {
        int n;
        cin >> n;

		vector<int> a(32);
		for(int i = 0; i < 32; ++i) a[i] = (n >> i) & 1;

		for(int i = 1; i < 32; ++i)
			if(a[i] ^ 1) a[i] += 1, a[i-1] -= 2;

		if(a[0] >= -1) {
			cout << "YES\n";
			for(int i = 0; i < 32; ++i) cout << a[i] << " \n"[i % 8 == 7];
		}
		else cout << "NO\n";
    }
}
