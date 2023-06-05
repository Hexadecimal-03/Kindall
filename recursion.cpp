#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
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

bool issafe (vector<vector<bool>> board, int row, int col)
{
    /**
     * Helping function for n-queen function.
     * Specifies whether tile is safe for queen if all queens of previous rows are filled.
     */

    int i;

    for (i = 0; i < board.size(); ++i)
    {
        if (board[row][i] || board[i][col])
        {
            return false;
        }
    }

    int x, y;
    x = row;
    y = col;

    while (row >= 0 && col >= 0)
    {
        if (board[row][col])
        {
            return false;
        }
        row--;
        col--;
    }

    while (x >= 0 && y < board.size())
    {
        if (board[x][y])
        {
            return false;
        }
        x--;
        y++;
    }

    return true;
}

void queens (vector<vector<bool>> board, int row, string asf)
{
    /**
     * n-queen problem, gives all possible outcomes.
     * input is a 2D bool vector of specified size with all entries as false.
     */

    int i;
    if (row == board.size())
    {
        cout << asf << ". " << endl;
        return;
    }

    for (i = 0; i < board[0].size(); ++i)
    {
        if (issafe(board, row, i))
        {
            board[row][i] = true;
            char r = row + '0';
            char c = i + '0';

            queens (board, row+1, asf + r + '-' + c + ", ");
        }
        board[row][i] = false;
    }
}

/* //Sample main() function for n-queens problem
int main()
{
    int n;
    cin >> n;
    vector<vector<bool>> board (n, vector<bool> (n, false));

    queens (board, 0, "");

    return 0;
}
*/

bool canplace (int** board, int i, int j, int n, int number)
{
    /**
     * Helper function for soduku solver. Checks whether number can be placed at that tile
     * same number must not be in the horizontal line, vertical line or in the box same as the number.
     */
	int x, y;
	for(x = 0; x < n; x++)
	{
		if (board[x][j] == number || board[i][x] == number)
		{
			return false;
		}
	}

	int rn = sqrt(n);
	int sx = (i/rn)*rn;
	int sy = (j/rn)*rn;

	for (x = sx; x < sx+rn; x++)
	{
		for (y = sy; y < sy+rn; y++)
		{
			if (board[x][y] == number)
			{
				return false;
			}
		}
	}
	return true;
}

bool sodukusolver (int** board, int i, int j, int n)
{
    /**
     * The solver enters nxn matrix n must be a square number (solver is not limited to the 9*9 soduku only)
     * Enter matrix and enter 0 for empty spaces 
     */

	int k;
	if (i == n)		//reached last row
	{
		return true;
	}

	if (j == n)
	{
		return sodukusolver (board, i+1, 0, n);
	}

	if (board[i][j] != 0)
	{
		return sodukusolver (board, i, j+1, n);
	}

	for (k = 1; k <= n; ++k)
	{
		if (canplace (board, i, j, n, k))
		{
			board[i][j] = k;

			if (sodukusolver (board, i, j+1, n))
			{
				return true;
			}
		}
	}

	board[i][j] = 0;
	return false;
}

/*  // Sample main function for sodukusolver
int main()
{
	int i, j, n;
	cin >> n;

	int** board = new int* [n];
	for (i = 0; i < n; ++i)
	{
		board[i] = new int [n];
	}

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}
	}

	if (sodukusolver(board, 0, 0, n))
	{
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < n; ++j)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}

	return 0;
}
*/

int partition (int* v, int s, int e)
{
    /**
     * Helper function for quicksort function
     * It specifies an index for partition of array for merge sort
     */

    int i = s-1;
    int j;

    for (j = s; j < e; ++j)
    {
        if (v[j] <= v[e])
        {
            ++i;
            swap (v[i], v[j]);
        }
    }
    swap (v[i+1], v[e]);
    return i+1;
}

void quicksort (int* v, int s, int e)
{
    /**
     * Quicksort function also commonly known as mergesort
     * Implemented using recursion and a helper function partition
     */

    if (s >= e)
    {
        return;
    }

    int indx = partition (v, s, e);
    quicksort (v, s, indx-1);
    quicksort (v, indx+1, e);
}

//-------------------------------------------------------------------------------------//
// Some mini functions related to recursion in arrays and permutations and combinations

int sum (int n)                 //Sum of numbers till n
{
    if (n == 0)
    {
        return 0;
    }
    return n + sum (n-1);
}

void inc (int n)                //Prints in increasing order till n
{
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    inc (n-1);
    cout << n << endl;
    return;
}

void decr (int n)               //Prints in decreasing order from n
{
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    cout << n << endl;
    decr (n-1);
    return;
}

int fib (int n)                 //fibonacci number of index n
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int factorial (int n)           //Factorial of number n
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorial (n-1);
}

int pow (int n, int p)          //n raised to power p
{
    if (p == 0)
    {
        return 1;
    }
    return n * pow(n, p-1);
}

int lastocc (int arr[], int n, int i, int key)      //Last occurence index of key in arr of size n
{
    if (i == n)
    {
        return -1;
    }
    int restarray = lastocc (arr, n, i+1, key);
    
    if (restarray != -1)
    {
        return restarray;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}

int firstocc (int arr[], int n, int i, int key)     //First occurence index of key in arr of size n
{
    if (i == n)
    {
        return -1;
    }

    if (arr[i] == key)
    {
        return i;
    }
    return firstocc(arr, n, i+1, key);
}

bool sorted (int arr[], int n)  //Sorts the array in recursive manner
{
    if (n == 1)
    {
        return 1;
    }
    return ((arr[0] < arr[1]) && sorted(arr+1, n-1));
}

void reverse (string s)         //Prints string in reverse
{
    if (s.length() == 0)
    {
        return;
    }
    reverse (s.substr(1));
    cout << s[0];
    return;
}

string moveallx (string s)         //moves all "x" to nlast of string
{
    if (s.length() == 0)
    {
        return  "";
    }

    string ans = moveallx (s.substr(1));

    if (s[0] == 'x')
    {
        return ans + s[0];
    }
    return s[0] + ans;
}

string removedup (string s)         //removes duplicates in the string
{
    if (s.length() == 0)
    {
        return "";
    }

    string ans;

    if (s[0] == s[1])
    {
        ans = removedup(s.substr(1));
    }
    else
    {
        ans = s[0] + removedup(s.substr(1));
    }

    return ans;
}

void replacepi (string s)           //Replaces "pi" to "3.14" in a string
{
    if (s.length() == 0)
    {
        return;
    }

    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        replacepi (s.substr (2));
        return;
    }
    cout << s[0];
    replacepi (s.substr (1));
    return;
}

void subseq (string s, string ans)          //prints all subsequences of the string
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    subseq (s.substr(1), ans);
    subseq (s.substr(1), ans + s[0]);
    return;
}

void keypad (string n, string arr[], string ans)        //takes two numbers of keypad and then prints all combinations of these alphabets
{
    if (n.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    string value = arr[n[0] - '0'];

    for (int i = 0; i < value.length(); ++i)
    {
        keypad (n.substr (1), arr, ans + value[i]);
    }
}

/* Sample main function for keypad function
int main()
{
    string s;
    string arr[10] = {"", "./", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    cin >> s;

    keypad (s, arr, "");

    return 0;
}
*/

int minindex (int* arr, int i, int n)      //Returns index of smallest element in array (inpace operation)
{
    int k, min = INT_MAX, mindex;
    for (k = i; i < n; ++i)
    {
        if (arr[i] < min)
        {
            mindex = i;
            min = arr[i];
        }
    }
    return mindex;
}

void swap (int* arr, int i, int j)        //Inplace swap function for inplace sorting
{
    int temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

void sort (int* arr, int i, int n)      //Inplace sort function for an array
{
    int mindex;
    if (i >= n)
    {
        return;
    }

    mindex = minindex (arr, i, n);

    swap (arr, i, mindex);

    sort (arr, i+1, n);
}

void permutation (string s, string ans)            //Prints all permutations of given string
{
    int i;
    string ros;
    
    if (s.length() == 0)
    {
        cout << ans << endl;
    }

    for (i = 0; i < s.length(); ++i)
    {
        ros = s.substr(0, i) + s.substr(i+1);

        permutation (ros, ans + s[i]);
    }
}

int countpath (int start, int end)                  //Returns the number of ways to get to end from start in a board game with the help of a dice
{
    int i, count = 0;

    if (start == end)
    {
        return 1;
    }
    else if (start > end)
    {
        return 0;
    }

    for (i = 1; i <= 6; ++i)
    {
        count += countpath (start + i, end);
    }
    return count;
}

int CountPathMaze (int n, int i, int j)         //number of ways to move to end of maze from i, j as starting point
{
    if (i == n-1 && j == n-1)
    {
        return 1;
    }
    else if (i >= n || j >= n)
    {
        return 0;
    }

    return CountPathMaze (n, i+1, j) + CountPathMaze (n, i, j+1);
}

int tiling (int n)                  //returns the number of ways 2x1 tiles can be fitted in 2xn grid
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else if (n < 0)
    {
        return 0;
    }

    return tiling (n-1) + tiling (n-2);
}

int pairingfrnds (int n)            //Returns number of ways friends can be paired or left alone
{
    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }

    return pairingfrnds (n-1) + (pairingfrnds (n-2) * (n-1));
}

//------------------------------------------------------------------------------------//


int main()
{
    
    return 0;
}