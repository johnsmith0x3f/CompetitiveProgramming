#include <bits/stdc++.h>
using namespace std;

int main() {
	int tt;
	cin >> tt;
	while(tt--) {
		int n;
		cin >> n;

		string s;
		cin >> s;
		s = "1" + s + "1";

		int flag = 0;
		for(int i = 1; i <= n; ++i) {
			if(s[i] == '1' && (s[i - 1] == '1' || s[i + 1] == '1')) {
				flag = 1;
				break;
			}
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}
