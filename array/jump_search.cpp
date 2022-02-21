//for sorted array this kind of jum search is used
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int jump_search(int x,int n, vector<int> arr)
{
    int block_size=sqrt(n);
    int low=0,high=block_size-1;
    while(low<=high && x>=arr[low] && x <=arr[high])
    {
        if(low==high)
        {
            if(arr[low]==x)
                return low;
            else
                return -1;
        }
        int pos = low + (((double)(high-low)/(arr[high]-arr[low]))*(x-arr[low]));
        if(arr[pos]==x)
        {
            return pos;
        }
        if(arr[pos]<x)
        {
            return pos + 1;
        }
        else
        {
            return pos - 1;
        }
return -1;
    }
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