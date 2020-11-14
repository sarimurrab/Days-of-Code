#include<bits/stdc++.h>
using namespace std;

int min_subset_diff(int * arr, int n)
{
    // first I need to find out the range
    int range =0;
    for(int i=0;i<n;i++)
        range+=arr[i];

    
    // To get the last row of subset sum...
    // which include the all possible sum using differnt subsets....
    bool t[n+1][range+1];
    //step1 - initialization
    for(int i=0;i<n+1;i++)
    for(int j=0;j<range+1;j++)
    {
        if(i==0)
        t[i][j] = false;
        if(j==0)
        t[i][j] = true;
    }

    //step 2 - top down process
    for(int i=1;i<n+1;i++)
    for(int j=1;j<range+1;j++)
    {
        if(arr[i-1]<=j)
        {
            t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
        }
        else
        {
            t[i][j] = t[i-1][j];
        }
    }

    // This is the half range we were looking for
    vector<int> v;
    for(int j=0;j<=range/2;j++)
    {
        if(t[n][j])
        v.push_back(j);
    }


    // FORMULA WE CALCULATED = Range - 2 s1
    int mini = INT_MAX;
    for(int i=0;i<v.size();i++)
    {
        mini = min(mini, range-2*v[i]);
    }


    return mini;
}


int main()
{
    int arr[] = {1,2,7};
    int n = sizeof(arr)/sizeof(int);
    cout<<min_subset_diff(arr,n);



    return 0;

}