bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    if (matrix.empty() || matrix[0].empty())
    {
        return false;
    }
    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = m * n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int e = matrix[mid / n][mid % n];

        if (target < e)
        {
            end = mid - 1;
        }
        else if (target > e)
        {
            start = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}
