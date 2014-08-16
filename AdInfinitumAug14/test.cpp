// Program to print all combination of size r in an array of size n
#include<stdio.h>
#define mod 100003

long long int sum;

void combinationUtil(int arr[],int n,int r,int index,int data[],int i);
 
// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(int arr[], int n, int r)
{
    // A temporary array to store all combination one by one
    int data[r];
 
    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, n, r, 0, data, 0);
}
 
/* arr[]  ---> Input Array
   n      ---> Size of input array
   r      ---> Size of a combination to be printed
   index  ---> Current index in data[]
   data[] ---> Temporary array to store current combination
   i      ---> index of current element in arr[]     */
void combinationUtil(int arr[], int n, int r, int index, int data[], int i)
{
    // Current cobination is ready, print it
    long long int pro = 1;
    if (index == r)
    {
        for (int j=0; j<r; j++)
            pro = (pro*data[j])%mod;
        sum = (sum + pro)%mod;
        return;
    }
 
    // When no more elements are there to put in data[]
    if (i >= n)
        return;
 
    // current is included, put next at next location
    data[index] = arr[i];
    combinationUtil(arr, n, r, index+1, data, i+1);
 
    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    combinationUtil(arr, n, r, index, data, i+1);
}
 
// Driver program to test above functions
int main()
{
    // int arr[] = {1, 1, 2};
    // int r = 2;
    // int n = sizeof(arr)/sizeof(arr[0]);
    // printCombination(arr, n, r);
    
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }

    int q;
    scanf("%d",&q);
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d",&x);
        sum = 0;
        printCombination(arr, n, x);
        printf("%lli\n",sum);
    }

    return 0;
}