#include <iostream>

using namespace std;

int partition_sort(int A[],int l, int r)
{
    int p=A[l];
    int i=l;
    int j=r+1;
    do
    {
        do
        {
            i++;
        }while(i<=r&&A[i]<p);

        do
        {
            j--;
        }while(j>l&&A[j]>p);
        swap(A[i],A[j]);
    }while(i<j);
      swap(A[i],A[j]);
      swap(A[l],A[j]);
    return j;

}

void quick_sort(int A[],int l, int r)
{
    if(l<r)
    {
        int s=partition_sort(A,l,r);
        quick_sort(A,l,s-1);
        quick_sort(A,s+1,r);
    }
}

int main()
{
    int A[20];
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;
    cout<<"Enter elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<<"Given array "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" "<<endl;
    }
    quick_sort(A,0,n-1);
    cout<<"sorted array "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" "<<endl;
    }
    return 0;
}
