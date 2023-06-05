#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int conversion(int num, int sb, int db)
{
    /**
     * Converts num from source base to destination base
     * sb and db can be any base <= 10, not limited to standard b o d bases
     */

    int ans = 0;        // Any  Base to Decimal
    int mult = 1;
    while(num != 0)
    {
        int rem = num % 10;
        ans  = ans + rem * mult;
        mult = mult * sb;
        num = num / 10;
    }

    mult = 1;           // Refresing the variables
    num = ans;
    ans = 0;

    while(num != 0)     //Decimal to Any number
    {
        int rem = num % db;
        ans  = ans + rem * mult;
        mult = mult * 10;
        num = num / db;    
    }  
    return ans;  
}

int kadane (int n, int arr[])
{
    /**
     * Standard Kadane's algorithm for calculating the largest contiguous sum in the array.
     * if currsum attains a negative value, then it is initialized to 0 and hence maxsum is calculated by adding the element to currsum.
     * Each time currsum is compared with maxsum and max of these is assigned to maxsum.
     */

    int i, maxsum = INT_MIN, currsum = 0;

    for (i = 0; i < n; ++i)
    {
        currsum += arr[i];
        maxsum = max (currsum, maxsum);

        if (currsum < 0)
        {
            currsum = 0;
        }
    }
    return maxsum;
}

int round_sumarr (int n, int arr[])
{
    /**
     * Calculates largest sum in circular array by calculating smallest contiguous sum in of array and then subtracting it from the main array.
     * This is similar to calculating largest sum in negative of array by Kadane's algorithm and then adding sum to the sum of array.
     */

    int i, sum = 0, ans;

    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
    }

    int* negarr = new int[n];

    for (i = 0; i < n; ++i)
    {
            negarr[i] = -arr[i];
    }

    ans = sum + kadane(n, negarr);
    return sum;
}

int maxPathSum(int ar1[], int ar2[], int m, int n)
{
    /**
     * Inputs two arrays and computes max sum with them
     * The sum is calculated from start of any array and can end with any array.
     * The shift between array can only be done at common elements among the arrays.
     */

	int i = 0, j = 0;
	int result = 0, sum1 = 0, sum2 = 0;

	while (i < m && j < n)
	{

		if (ar1[i] < ar2[j])
			sum1 += ar1[i++];

		else if (ar1[i] > ar2[j])
			sum2 += ar2[j++];

		else
		{
			result += max(sum1, sum2) + ar1[i];
			sum1 = 0;
			sum2 = 0;
			i++;
			j++;
		}
	}

	while (i < m)
		sum1 += ar1[i++];

	while (j < n)
		sum2 += ar2[j++];

	result += max(sum1, sum2);

	return result;
}

void arraysum_triplets (int n, int arr[], int target)
{
    /**
     * Prints all the triplets (subsets) of array which sums upto the target value.
     * n is the size of array.
     * output is in the form "num1, num2 and num3".
     */

    int i, j, k;
    sort (arr, arr+n);

    for (i = 0; i < n; ++i)
    {
        j = i+1;
        k = n-1;

        while (j < k)
        {
            if (arr[i]+arr[j]+arr[k] == target)
            {
                cout << arr[i] << ", " << arr[j] << " and " << arr[k] << endl;
                ++j;
                --k;
            }
            else if (arr[i]+arr[j]+arr[k] > target)
            {
                --k;
            }
            else
            {
                ++j;
            }
        }
    }
    return;
}

int rainwaterTrapping (vector <int> &height)
{
    /**
     * The arrays represent height of towers with unit width
     * If rainwater was supposed to be trapped in between them, then the maximum possible value of entrapped water will be given by the function
     * May be implemented using stack but is more confusing, a subtle approach is used.
     */

    int i;
    vector <int> leftgreat (height.size(), 0);
    vector <int> rightgreat (height.size(), 0);
    int leftg = 0;
    int rightg = 0;

    for (i = 0; i < height.size(); ++i)
    {
        if (height[i] > leftg)
        {
            leftg = height[i];
        }
        leftgreat[i] = leftg;
    }

    for (i = height.size()-1; i >= 0; --i)
    {
        if (height[i] > rightg)
        {
            rightg = height[i];
        }
        rightgreat[i] = rightg;
    }

    int ans = 0;

    for (i = 0; i < height.size(); ++i)
    {
        ans += min (leftgreat[i], rightgreat[i]) - height[i];
    }

    return ans;
}

int findMinSwap(int arr[] , int n)
{
    /**
     * Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.
     */

    // Declare a vector of pair    
    vector<pair<int,int>> vec(n);
     
    for(int i=0;i<n;i++)
    {
        vec[i].first=arr[i];
        vec[i].second=i;
    }
 
    // Sort the vector w.r.t the first
    // element of pair
    sort(vec.begin(),vec.end());
 
    int ans=0,c=0,j;
 
    for(int i=0;i<n;i++)
    {  
        // If the element is already placed
        // correct, then continue
        if(vec[i].second==i)
            continue;
        else
        {
            // swap with its respective index
            swap(vec[i].first,vec[vec[i].second].first);
            swap(vec[i].second,vec[vec[i].second].second);
        }
         
        // swap until the correct
        // index matches
        if(i!=vec[i].second)
            --i;
         
        // each swap makes one element
        // move to its correct index,
        // so increment answer
        ans++;
    }
 
    return ans;
}

int main()
{

    return 0;
}