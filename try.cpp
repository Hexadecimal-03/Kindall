#include <iostream>
#include <vector>
using namespace std;

bool issafe (vector <vector <char>> maze, int sr, int sc, vector <vector <bool>> ans)
{
    if (sr >= maze.size() || sr < 0)
    {
        return false;
    }
    if (sc >= maze[0].size() || sc < 0)
    {
        return false;
    }
    if (maze[sr][sc] == 'X' || ans[sr][sc])
    {
        return false;
    }
    return true;
}

bool ratinmaze (vector <vector <char>> maze, int sr, int sc, vector <vector <bool>> &ans)
{
    if (sr == maze.size()-1 && sc == maze[0].size()-1)
    {
        ans[sr][sc] = true;
        return true;
    }

    if (issafe (maze, sr, sc, ans))
    {
        ans[sr][sc] = true;
        if (ratinmaze (maze, sr, sc-1, ans))
        {
            return true;
        }
        if (ratinmaze (maze, sr, sc+1, ans))
        {
            return true;
        }
        if (ratinmaze (maze, sr+1, sc, ans))
        {
            return true;
        }
        if (ratinmaze (maze, sr-1, sc, ans))
        {
            return true;
        }

        ans[sr][sc] = false;
        return false;
    }

    return false;
}

int main()
{
    int n, m, i, j;
    cin >> n >> m;
    vector <vector <char>> maze (n, vector <char> (m));

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            cin >> maze[i][j];
        }
    }

    vector <vector <bool>> ans (n, vector <bool> (m, false));

    if (ratinmaze (maze, 0, 0, ans))
    {
        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < m; ++j)
            {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        cout << "NO PATH FOUND" << endl;
    }

    return 0;
}