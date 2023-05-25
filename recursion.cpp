#include <iostream>
using namespace std;

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

int main()
{
    
    return 0;
}