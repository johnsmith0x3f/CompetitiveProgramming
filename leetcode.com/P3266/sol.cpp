using i64 = long long;
using pli = pair<i64, int>;

const int P = 1e9 + 7;

inline i64 binExp(i64 a, int b) {
    i64 c = 1;
    while(b) {
        if(b & 1) c = c * a % P;
        a = a * a % P, b >>= 1;
    }
    return c;
}

class Solution {
public:
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {
        if(multiplier == 1) return nums;

        int n = nums.size(), mx = 0;
        for(int i = 0; i < n; ++i) mx = max(mx, nums[i]);

        priority_queue<pli, vector<pli>, greater<pli>> q;
        for(int i = 0; i < n; ++i) q.push({ nums[i], i });

        while(k) {
            auto [ x, i ] = q.top();
            if(x > mx) break;

            q.pop(); --k, q.push({ x * multiplier, i });
        }

        for(int i = 0; i < n; ++i) {
            auto [ x, j ] = q.top(); q.pop();
            nums[j] = x % P * binExp(multiplier, k / n + (i < k % n)) % P;
        }

        return nums;
    }
};