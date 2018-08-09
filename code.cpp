#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int sumResult(int a[],int c)
{
    int i,sum=0;
    for(i=0;i<c;i++)
    {
        sum+=a[i];
    }
    return sum;
}

int main()
{
    int n,i,j,flag = 0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    quickSort(a, 0, n-1);
    for(i=n-1;i>=2;i--)
    {
        j=sumResult(a,i);
        if(a[i]<j)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
        cout<<i+1;
    else
        cout<<"0";
    return 0;
}