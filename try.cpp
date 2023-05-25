#include <iostream>
using namespace std;

void towerOfHanoi (int n, int from, int to, int aux)
{
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
    int n, from, aux, to;
    cin >> n >> from >> to >> aux;

    towerOfHanoi (n, from, to, aux);
    return 0;
}