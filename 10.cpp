// common_ele_in_all_rows
void common_ele(int mat[M][N], int n, int m)
{
    map<int, int> mp;

    for (int j = 0; j < m; j++)
    {
        mp[mat[0][j]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (mp[mat[i][j]] == i)
            {
                mp[mat[i][j]] = i + 1;
            }

            if (i == n - 1 && mp[mat[i][j]] == n)
                cout << mat[i][j] << " ";
        }
    }
}