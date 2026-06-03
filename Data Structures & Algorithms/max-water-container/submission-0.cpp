class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n - 1;
        int area = 0;

        while (i < j) {
            int width = j - i;
            int height = min(heights[i], heights[j]);
            int m = width * height;

            area = max(area, m);

            if (heights[i] > heights[j])
                j--;
            else
                i++;
        }

        return area;
    }
};
