#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool issafe (vector <vector <int>> maze, int sr, int sc)
{
    /**
     * Helping function for the floodfill problem
     * returns true if the cell is safe and false if not
     */

    if (sr >= maze.size() || sr < 0)
    {
        return false;
    }
    if (sc >= maze[0].size() || sc < 0)
    {
        return false;
    }
    if (maze[sr][sc] == 1)
    {
        return false;
    }
    return true;
}

void floodFill (vector <vector <int>> maze, int sr, int sc, string asf)
{
    /**
     * Floodfill is a problem similar to the maze solving problem.
     * A maze is entered in form of 2D vector 0 (possible steps), 1 (blockages)
     * Initially we are at the top left and we need to get to the bottom right using the best possble method
     * The solution is stored in a string with initials representing the directions
     * The relative ordering of directions are t l d r.
     */

    if ((sr == maze.size() - 1) && (sc == maze[0].size() - 1))
    {
        cout << asf << endl;
        return;
    }

    if (issafe (maze, sr-1, sc))
    {
        maze[sr][sc] = 1;
        floodFill (maze, sr-1, sc, asf + "t");
    }
    if (issafe (maze, sr, sc-1))
    {
        maze[sr][sc] = 1;
        floodFill (maze, sr, sc-1, asf + "l");
    }
    if (issafe (maze, sr+1, sc))
    {
        maze[sr][sc] = 1;
        floodFill (maze, sr+1, sc, asf + "d");
    }
    if (issafe (maze, sr, sc+1))
    {
        maze[sr][sc] = 1;
        floodFill (maze, sr, sc+1, asf + "r");
    }
    maze[sr][sc] = 0;
}

void towerOfHanoi (int n, int from, int to, int aux)
{
    /**
     * It is one of the standard questions of recursions.
     * inputs are n (number of elements), from (id of fram tower), to (id of to tower), aux (id of auxiliary tower).
     */

    if (n == 0)
    {
        return;
    }

    towerOfHanoi (n-1, from, aux, to);
    cout << n << "[" << from << " -> " << to << "]" << endl;
    towerOfHanoi (n-1, aux, to, from);
}

void tarSumSubsets (vector <int> arr, int i, int tar, string asf)
{
    /**
     * Inputs an array of numbers and prints all subsets with sum equals to the target value
     * Subsets are non repeating and in same order as the array.
     */
    if (tar < 0)
    {
        return;
    }

    if (i == arr.size())
    {
        if (tar == 0)
        {
            asf = asf + ".";
            cout << asf << endl;
        }
        return;
    }

    tarSumSubsets (arr, i+1, tar - arr[i], asf + to_string(arr[i]) + ", ");
    tarSumSubsets (arr, i+1, tar, asf);
    return;   
}

int main()
{
    
    return 0;
}

/* The input sample function for the floodfill problem
int main()
{
    int n, m, i, j;
    cin >> n >> m;

    vector <vector <int>> arr (n, vector <int> (m));

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
        }
    }

    floodFill (arr, 0, 0, "");
    return 0;
}
*/
