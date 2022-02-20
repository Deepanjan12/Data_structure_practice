#include<iostream>
#include<vector>
using namespace std;
int binary_search(int x,vector<int>arr)
{
    int low = 0 ,high=arr.size()-1;
    int mid=(low+high)/2;
    if(low<=high)
    {
        if(arr[mid]==x)
        {
            return mid;
        }
        else if(arr[mid]>x)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
     return mid;
}

int main(){
    vector<int> arr;
    int n;
    cout<<"Enter the limit of the array: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int var;
        cin>>var;
        arr.push_back(var);
    }
    cout<<"Enter the element to be searched: ";
    int x,pos;
    cin>>x;
    pos= binary_search( x, arr);
    cout<<"The position of the element is "<<pos+1;
    return 0;
}