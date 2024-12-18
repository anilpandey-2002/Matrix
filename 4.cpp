// row_with_maximum
int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int row = 0, col = m - 1, ans = -1;

    while (col >= 0 && row < n)
    {
        if (arr[row][col] == 1)
        {
            one = max(one, col);
            ans = max(ans, row);
            col--;
        }
        else
            row++;
    }
    return ans;
}
