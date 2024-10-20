#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

template <typename T = int>
constexpr T read() {
	T x = 0; bool f = 1; char c = getchar();
	while(isdigit(c)^1) f &= (c != 45), c = getchar();
	while(isdigit(c)) x = (x<<1) + (x<<3) + (c^48), c = getchar();
	return f ? x : -x;
}

inline bool ask(const string &s) {
	cout << "? " << s << "\n", cout.flush();
	return read();
}

inline void aha(const string &s) {
	cout << "! " << s << "\n", cout.flush();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int cas = read();

	while(cas--) {
		int n = read();

		char c = '0';
		string str;

		while(int(str.length()) < n) {
			if(ask(str + c)) str += c;
			else {
				c ^= 1;
				if(ask(str + c)) str += c;
				else break;
			}
		}

		if(int(str.length()) == n) {
			aha(str);
			continue;
		}

		c = '1';
		while(int(str.length()) < n) {
			if(ask(c + str)) str = c + str;
			else {
				c ^= 1;
				if(ask(c + str)) str = c + str;
				else break;
			}
		}

		aha(str);
	}
	return 0;
}

