#include "iostream"
using namespace std;

// 1 2 3 4 5 5
// 1 2 3 4 6 5


bool sorted_or_not(int * a,int n)
{
    if(n==0 || n==1)
    return true;

   if(a[0]<=a[1] and sorted_or_not(a+1,n-1))
   {
       return true;
   }
   else
   {
       return false;
   }
   


}

int main()
{
    int a[] = {1,2,4,7,6};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<sorted_or_not(a,n);

}
