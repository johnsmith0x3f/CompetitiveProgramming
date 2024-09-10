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

int tet[6][3] = {
	{ 7, 0, 0 },
	{ 1, 1, 1 },
	{ 2, 3, 0 },
	{ 1, 3, 0 },
	{ 3, 1, 0 },
	{ 3, 2, 0 }
};

struct Matrix {
	int* a[8];
	int* operator [] (const int &i) const {
		return a[i];
	}
} A, B;

int a[64][64];

int main() {

	for(int i = 0; i < 6; ++i) {
		for(int j = 0; j < 3; ++j) {
			for(int s = 0; s < 8; ++s)
				for(int t = 0; t < 8; ++t)
					if(((s >> j) & tet[i][0]) == 0 && ((t >> j) & tet[i][1]) == 0) ;
		}
	}
	for(int s = 0; s < 8; ++s) {
		for(int t = 0; t < 8; ++t) {
		}
	}
	return 0;
}

