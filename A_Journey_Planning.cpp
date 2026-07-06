class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    int time = 0;
    vector<pair<int, int>> rotten;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 2) {
          rotten.push_back({i, j});
        }
      }
    }
    int total_rotten = rotten.size();
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};

    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < rotten.size(); i++) {
      q.push({{rotten[i].first, rotten[i].second}, 0});
    }
    while (!q.empty()) {
      int r = q.front().first.first;
      int c = q.front().first.second;
      int curr_time = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int newr = r + x[i], newc = c + y[i];
        if (newr < m && newc < n && newr >= 0 && newc >= 0) {
          if (grid[newr][newc] == 1) {
            grid[newr][newc] = 2;
            q.push({{newr, newc}, curr_time + 1});
            time = max(time, curr_time + 1);
          }
        }
      }
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          return -1;
        }
      }
    }
    return time;
  }
};