#include <bits/stdc++.h>
using namespace std;

// Problem: Max fish collected by starting from any water cell (>0),
// moving 4-directionally within connected water cells, summing values.
// Answer is maximum component sum over all connected components of cells with value > 0.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if (!(cin >> m >> n)) return 0;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) cin >> a[i][j];
    }

    vector<vector<char>> vis(m, vector<char>(n, 0));
    auto inb = [&](int x, int y){ return x>=0 && x<m && y>=0 && y<n; };

    long long best = 0;
    const int dx[4] = {1,-1,0,0};
    const int dy[4] = {0,0,1,-1};

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) if (!vis[i][j] && a[i][j] > 0) {
            long long sum = 0;
            // Iterative DFS to avoid deep recursion risks
            vector<pair<int,int>> st;
            st.emplace_back(i, j);
            vis[i][j] = 1;
            while (!st.empty()) {
                auto [x, y] = st.back();
                st.pop_back();
                sum += a[x][y];
                for (int dir = 0; dir < 4; ++dir) {
                    int nx = x + dx[dir], ny = y + dy[dir];
                    if (inb(nx, ny) && !vis[nx][ny] && a[nx][ny] > 0) {
                        vis[nx][ny] = 1;
                        st.emplace_back(nx, ny);
                    }
                }
            }
            best = max(best, sum);
        }
    }

    cout << best << '\n';
    return 0;
}

