class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int area = treveseid(grid, i, j, m, n);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }

    int treveseid(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            return 0;
        }

        grid[i][j] = 0;

        int area = 1;
        area += treveseid(grid, i, j + 1, m, n);
        area += treveseid(grid, i + 1, j, m, n);
        area += treveseid(grid, i, j - 1, m, n);
        area += treveseid(grid, i - 1, j, m, n);

        return area;
    }
};
