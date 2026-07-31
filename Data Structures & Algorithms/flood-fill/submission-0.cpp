class Solution {
public:
    void helper(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {

        int m = image.size();
        int n = image[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n)
            return;

        if (image[r][c] != oldColor)
            return;

        image[r][c] = newColor;

        helper(image, r + 1, c, oldColor, newColor);
        helper(image, r - 1, c, oldColor, newColor);
        helper(image, r, c + 1, oldColor, newColor);
        helper(image, r, c - 1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int oldColor = image[sr][sc];

        if (oldColor == color)
            return image;

        helper(image, sr, sc, oldColor, color);

        return image;
    }
};