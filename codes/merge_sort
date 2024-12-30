#include<iostream>
using namespace std;

void Merge(int b[],int c[],int a[],int p,int q){
int i=0,j=0,k=0;
while(i<p&&j<q){
      if(b[i]<=c[j]){
        a[k]=b[i];
        i=i+1;
      }
      else{
        a[k]=c[j];
        j=j+1;
      }
      k=k+1;
}
if(i==p){
    while(j<q){
        a[k]=c[j];
        j++;
        k++;
    }
}
else{
    while(i<p){
    a[k]=b[i];
    i++;
    k++;
    }
}
}

void mergesort(int a[],int n){
if(n>1){
    int mid=n/2;
    int p=mid;
    int q=n-mid;
    int b[p],c[q];
    for(int i=0;i<p;i++){
        b[i]=a[i];
    }
    for(int i=0;i<q;i++){
        c[i]=a[p+i];
    }
    mergesort(b,p);
    mergesort(c,q);
    Merge(b,c,a,p,q);
}
}

int main(){
int n;
cout<<"Enter the number of elements:";
cin>>n;
int a[n];
cout<<"Enter the elements:";
for(int i=0;i<n;i++){
    cin>>a[i];
}
mergesort(a,n);
cout<<"Sorted array:";
for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
return 0;
}
