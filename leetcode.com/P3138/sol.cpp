class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.size();

        vector<vector<int>> c(n + 1, vector<int>(26));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < 26; ++j) c[i + 1][j] += c[i][j] + (j == s[i] - 'a');

        for(int i = 1; i < n; ++i) {
            if(n % i) continue;

            bool flag = 1;
            for(int j = i; j <= n; j += i)
                for(int k = 0; k < 26; ++k) flag &= (c[j][k] - c[j - i][k] == c[i][k]);

            if(flag) return i;
        }

        return n;
    }
};