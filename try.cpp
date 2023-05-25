#include <iostream>
#include <string>
#include <vector>
using namespace std;

void tarSumSubsets (vector <int> arr, int i, int tar, string asf)
{
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
    int n, tar, i;
    cin >> n;
    vector <int> arr (n);

    for (i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cin >> tar;

    tarSumSubsets (arr, 0, tar, "");
    return 0;
}