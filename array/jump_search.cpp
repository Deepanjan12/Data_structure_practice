//for sorted array this kind of jum search is used
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int jump_search(int x,int n, vector<int> arr)
{
    int step = sqrt(n);
    int prev = 0;
    while(arr[min(step,n)-1]<x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }
    while(arr[prev]<x)
    {
        prev++;
        if(prev == min(step,n))
            return -1;
    }
    if(arr[prev]==x)
    {
        return prev;
    }
return -1;
}


int main()
{
    int n,x;
    vector<int> arr;
    cout<<"Enter the limit of the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        int var;
        cin >> var;
        arr.push_back(var);
    }
    cout<<"Enter the element to search: ";
    cin>>x;
    int index= jump_search(x,n,arr);
    if(index==-1)
        cout<<"\nNumber "<<x<<"is not found";
    else
        cout<<"\nNumber "<<x<<" is at index "<<index+1;


    return 0;
}
// Output: