#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// Complete the maxRegion function below.

int getBiggestRegion(int i, int j, vector<vector<int>>& grid, int rows, int cols)
{
    if((i < 0 || i >= rows) || (j < 0 || j >= cols))
    {
        return 0;
    }
        
    if(grid[i][j] == 0)
    {    
        return 0;
    }
    
    int count = 1;
    grid[i][j] = 0;
    
    count += getBiggestRegion(i - 1, j - 1, grid, rows, cols);
    count += getBiggestRegion(i, j - 1, grid, rows, cols);
    count += getBiggestRegion(i + 1, j - 1, grid, rows, cols);
    
    count += getBiggestRegion(i - 1, j, grid, rows, cols);
    count += getBiggestRegion(i + 1, j, grid, rows, cols);
    
    count += getBiggestRegion(i - 1, j + 1, grid, rows, cols);
    count += getBiggestRegion(i, j + 1, grid, rows, cols);
    count += getBiggestRegion(i + 1, j + 1, grid, rows, cols);
    
    return count;

}

int maxRegion(int rows, int cols, vector<vector<int>> grid)
{    
    bool* visited = new bool[cols * rows]{};
        
    int max = 0;
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            int result = getBiggestRegion(j, i, grid, rows, cols);
                
            if(result > max)
                max = result;
        }
    }
    
    return max;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(n, m, grid);

    fout << res << "\n";

    fout.close();

    return 0;
}
