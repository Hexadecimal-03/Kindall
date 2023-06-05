#include <iostream>
#include <algorithm>
using namespace std;

int getbit (int n, int i)       //Gives the value of bit at position
{
    return ((n & (1<<i)) != 0);
}

int setbit (int n, int i)       //Sets the bit 1 at position
{
    return (n | (1<<i));
}

int clearbit (int n, int i)     //Sets the bit 0 at position
{
    return (n & (~(1<<i)));
}

int updatebit (int n, int i, int value)     //Sets the bit "value" at position
{
    n = (n & (~(1<<i)));        //Clearing the bit at i'th place
    return (n | (value<<i));    //Setting the value at i'th place as value = value
}

bool ispower2 (int n)           //Checks if the number is power of two
{
    return !(n && (n & n-1));
}

void subsets (int arr[], int n)     //Returns all subsets using bitmanipulation
{
    int i, j;
    
    for (i = 0; i < (1<<n); ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (i & (1<<j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

int unique (int arr[], int n)       //Returns unique number in the array where all other numbers are occuring twice (or other even times).
{
    int xorsum = 0;
    for (int i = 0; i < n; ++i)
    {
        xorsum = xorsum^arr[i];
    }
    return xorsum;
}

void unique2 (int arr[], int n)        //Prints two numbers that are occuring once
{
    int i, j, xorsum = 0;
    for (i = 0; i < n; ++i)
    {
        xorsum = xorsum^arr[i];
    }
    int count = 0;
    while (!(xorsum & (1<<count)))
    {
        count++;
    }
    int newxor = 0;
    for (i = 0; i < n; ++i)
    {
        if (getbit (arr[i], count))
        {
            newxor = newxor^arr[i];
        }
    }
    cout << newxor << " " << (newxor^xorsum) << endl;
}

void unique3 (int arr[], int n)         //Prints a number that is not occuring thrice
{
    int i, j;
    int ans = 0;
    for (i = 0; i < 64; ++i)
    {
        int count = 0;
        for (j = 0; j < n; ++j)
        {
            if (getbit (arr[j], i))
            {
                count++;
            }
        }
        if (count%3)
        {
            ans = setbit (ans, i);
        }
    }

    cout << ans << endl;
}

int sumofbits (int n)       //returns sum of bits in n
{
    int ans = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (getbit (n, i))
        {
            ans++;
        }
    }

    return ans;
}

bool isPowerOffour (int n)      //Returns true if n is power of four.
{
    if (!(n & (n-1)))
    {
        for (int i = 0; i < 64; ++i)
        {
            if (n & (1<<i))
            {
                if (i%2 == 0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    // int arr[4] = {1, 2, 3, 4};
    // subsets (arr, 4);
    // int arr[10] = {1, 2, 3, 10, 1, 3, 3, 1, 2, 2};
    /*
    int* ptr;
    ptr = sumbitsarrupton (6, ptr);

    for (int i = 0; i < 7; ++i)
    {
        cout << *(ptr + i) << " ";
    }
    */
   cout << isPowerOffour (0);
}