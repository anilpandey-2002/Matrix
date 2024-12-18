// max_size_rectangle
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mhist(int row[], int m1)
    {

        stack<int> result;

        int top_val; // Top of stack

        int max_area = 0; // Initialize max area in current

        int area = 0; // Initialize area with current top

        int i = 0;

        for (i = 0; i < m1;)
        {
            if (result.empty() || row[result.top()] <= row[i])
                result.push(i++);

            else
            {

                top_val = row[result.top()];
                result.pop();

                area = row[top_val] * (result.empty() ? i : i - result.top() - 1);

                max_area = max(area, max_area);
            }
        }

        while (!result.empty())
        {
            top_val = row[result.top()];
            result.pop();

            area = row[top_val] * (result.empty() ? i : i - result.top() - 1);

            max_area = max(area, max_area);
        }
        return max_area;
    }

    int kewl(int M[MAX][MAX], int n, int m)
    {
        int res = mhist(M[0], m);

        for (int i = 1; i < n; i++)
        {

            for (int j = 0; j < m; j++)
            {
                if (M[i][j])
                    M[i][j] += M[i - 1][j];
            }

            res = max(res, mhist(M[i], m));
        }
        return res;
    }

    int maxArea(int M[MAX][MAX], int n, int m)
    {
        return kewl(M, n, m);
    }
};
