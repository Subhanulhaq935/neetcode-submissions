class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int width = j - i;
                int height = min(heights[i], heights[j]);
                int m = width * height;

                area = max(area, m);
            }
        }
        return area;
    }
};
