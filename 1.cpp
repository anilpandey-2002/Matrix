// spiral_traversal_on_matrix
vector<int> spirallyTraverse(vector<vector<int>> matrix, int R, int C)
{

    vector<int> ans;

    if (matrix.size() == 0)
        return ans;

    bool seen[R][C];
    memset(seen, false, sizeof(seen));
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    int r = 0, c = 0, di = 0;

    for (int i = 0; i < R * C; i++)
    {
        ans.push_back(matrix[r][c]);
        seen[r][c] = true;
        int cr = r + dr[di];
        int cc = c + dc[di];

        if (0 <= cr && cr < R && 0 <= cc && cc < C && !seen[cr][cc])
        {
            r = cr;
            c = cc;
        }
        else
        {
            di = (di + 1) % 4;
            r += dr[di];
            c += dc[di];
        }
    }
    return ans;
}
