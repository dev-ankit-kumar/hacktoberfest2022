// cycle sort-count number of element less than a number then swap the number on the counted position
#include<bits/stdc++.h>
using namespace std;
void cycle_sort(int  a[],int n)
{
    for(int cs=0;cs<n-1;cs++)
    {
        int item=a[cs];
       int pos=cs;
        for(int i=cs+1;i<n;i++)
        if(a[i]<item)
        pos++;
        swap(item,a[pos]);
        while(pos!=cs)
        {
            pos=cs;
            for(int i=cs+1;i<n;i++)
             if(a[i]<item)
             pos++;
             swap(item,a[pos]);
        }
    }
}
int main()
{
   int n,t;
   cin>> n;
   int a[n];
   for(int i=0;i<n;i++)
   {
     cin>>a[i];
   }
   cycle_sort(a,n);
   for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
   return 0;
}
