#include <bits/stdc++.h>
using namespace std;

#define l "1"
#define s to_string(ans.size() + 1)
#define t to_string(ans.size() + 2)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<string> ans;

	int m = (n - 1) >> 1;
	for(int i = __lg(m); ~i; --i) {
		if((m >> i) & 1) {
			ans.emplace_back("POP " + s + " GOTO " + t + "; PUSH " + s + " GOTO " + s);
		}
		if(i) {
			ans.pop_back();
			ans.emplace_back("POP " + s + " GOTO " + t + "; PUSH " + s + " GOTO " + l);
			ans.emplace_back("POP " + s + " GOTO " + t + "; PUSH " + s + " GOTO " + s);
		}
	}
	ans.emplace_back("HALT; PUSH 128 GOTO 1");

	cout << ans.size() << '\n';
	for(string &instr : ans) cout << instr << '\n';

	return 0;
}
