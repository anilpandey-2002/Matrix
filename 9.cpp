// kth_smallest_in_row_col_sorted_matrix
#include <bits/stdc++.h>
using namespace std;

int getElementsGreaterThanOrEqual(int num, int n, int mat[4][4])
{
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] > num)
        {
            return ans;
        }

        if (mat[i][n - 1] <= num)
        {
            ans += n;
            continue;
        }

        int greaterThan = 0;
        for (int jump = n / 2; jump >= 1; jump /= 2)
        {
            while (greaterThan + jump < n &&
                   mat[i][greaterThan + jump] <= num)
            {
                greaterThan += jump;
            }
        }

        ans += greaterThan + 1;
    }
    return ans;
}

int kthSmallest(int mat[4][4], int n, int k)
{

    int l = mat[0][0], r = mat[n - 1][n - 1];

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int greaterThanOrEqualMid = getElementsGreaterThanOrEqual(mid, n, mat);

        if (greaterThanOrEqualMid >= k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
    int n = 4;
    int mat[4][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {25, 29, 37, 48},
        {32, 33, 39, 50},
    };
    cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
    return 0;
}
