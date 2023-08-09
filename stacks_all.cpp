#include <iostream>
#include <vector>
using namespace std;

template <typename T> // Typename for the template type class or function (generalization)

class stack // Stack class implemented using vector class
{
private: // Vector made private to prevent the changes
    vector<T> s;

public:
    void push(T val) // pushing back element into the vector stack
    {
        s.push_back(val);
    }
    T top() // returns the top of stack
    {
        return s[s.size() - 1];
    }
    bool empty() // returns bool true if stack is empty, false otherwise
    {
        return s.size() == 0;
    }
    void pop() // pop out the top most element from the stack
    {
        if (!s.empty())
        {
            s.pop_back();
        }
    }
    int size() // returns the size of stack
    {
        return s.size();
    }
};

void nextGreater(int arr[], int n)
{
    /**
     * Takes in an array and prints next greater element for every element
     * The stack stores index of elements instead of elements
     * result array stores the final values for array
     */

    int *result = new int[n];
    int i;
    for (i = 0; i < n; ++i)
    {
        result[i] = -1;
    }

    stack<int> s;

    for (i = 0; i < n; ++i)
    {
        while (!s.empty() && arr[s.top()] < arr[i])
        {
            result[s.top()] = arr[i];
            s.pop();
        }

        s.push(i);
    }

    for (i = 0; i < n; ++i)
    {
        cout << arr[i] << "," << result[i] << endl;
    }
    return;
}

void stocks(int arr[], int n)
{
    /**
     * Returns span of each stock
     * A span of a stock's price on a given day, i, is the maximum number of consecutive days before the (i+1)th day, for which stock's price on these days is less than or equal to that on the ith day
     * Efficient implementation using stacks
     */

    stack<int> stk;
    int i, k = 1;

    for (i = 0; i < n; ++i)
    {
        if (arr[i - 1] <= arr[i])
        {
            stk.push(k);
            k++;
        }
        else
        {
            while (!stk.empty())
            {
                stk.pop();
                k--;
            }
        }
        if (stk.empty())
        {
            stk.push(k);
            k++;
        }

        cout << stk.top() << " ";
    }
    return;
}

void insertAtBottom(stack<int> &s, int x) // Inserts the value at bottom of stack
{
    int data;
    if (s.empty())
    {
        s.push(x);
        return;
    }

    data = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(data);
    return;
}

void reverseStack(stack<int> &s) // Recursive function to reverse a stack
{
    int x;
    if (s.empty())
    {
        return;
    }

    x = s.top();
    s.pop();

    reverseStack(s);
    insertAtBottom(s, x);
    return;
}

bool balanced(string str)
{
    /**
     * 
     */
    
    stack<char> stk1;
    stack<char> stk2;
    stack<char> stk3;
    int i;
    for (i = 0; i < str.length(); ++i)
    {
        if (str[i] == '(')
        {
            stk1.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (stk1.empty() || stk1.top() != '(')
            {
                return false;
            }
            stk1.pop();
        }
        else if (str[i] == '{')
        {
            stk2.push(str[i]);
        }
        else if (str[i] == '}')
        {
            if (stk2.empty() || stk2.top() != '{')
            {
                return false;
            }
            stk2.pop();
        }
        else if (str[i] == '[')
        {
            stk3.push(str[i]);
        }
        else if (str[i] == ']')
        {
            if (stk3.empty() || stk3.top() != '[')
            {
                return false;
            }
            stk3.pop();
        }
    }
    return stk1.empty() && stk2.empty() && stk3.empty();
}

int celebrity(bool **arr, int n)
{
    stack<int> stk;
    int C, a, b, i;

    for (i = 0; i < n; ++i)
    {
        stk.push(i);
    }

    while (stk.size() > 1)
    {
        a = stk.top();
        stk.pop();
        b = stk.top();
        stk.pop();

        if (arr[a][b])
        {
            stk.push(b);
        }
        else
        {
            stk.push(a);
        }
    }

    C = stk.top();
    stk.pop();

    for (i = 0; i < n; ++i)
    {
        if ((i != C) && ((arr[C][i]) || (!arr[i][C])))
        {
            return -1;
        }
    }

    return C;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    stocks(arr, n);
    return 0;
}