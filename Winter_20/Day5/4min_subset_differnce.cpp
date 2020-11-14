#include<iostream>
using namespace std;

int min_subset_diff(int * arr, int n)
{
    // first I need to find out the range
    int range =0;
    for(int i=0;i<n;i++)
        range+=arr[i];

    
    //to get the last row of subset sum
    int t[n+1][range+1];
    //step1 - initialization
}


int main()
{

}