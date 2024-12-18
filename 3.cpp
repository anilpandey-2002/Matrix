// median_in_row_wise_sorted_matrix
int binaryMedian(vector<vector<int>> &matrix, int r, int c)
{
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        mn = min(mn, matrix[i][0]);

        mx = max(mn, matrix[i][c - 1]);
    }

    int desired = (r * c + 1) / 2;
    while (mn < mx)
    {
        int mid = mn + (mx - mn) / 2;
        int place = 0;

        for (int i = 0; i < r; ++i)
        {
            place += upper_bound(matrix[i].begin(), matrix[i].begin() + c, mid) - matrix[i].begin();
        }

        if (place < desired)
            mn = mid + 1;
        else
            mx = mid;
    }
    return mn;
}
