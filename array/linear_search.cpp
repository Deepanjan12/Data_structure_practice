#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int linear_search(int x,vector<int>arr)
{
    int pos=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==x)
        {
            pos=i;
            break;
        }
    }
    return pos;
}

int main(){
    int n;
    cout<<"Enter the limit of the array: ";
    cin>>n;
    vector<int> arr;
    cout<<"Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        int var;
        cin>>var;
        arr.push_back(var);
    }
    cout<<"The Element want to find:";
    int x;
    cin>>x;
    int pos=linear_search(x,arr);
    if(pos==-1)
    {
        cout<<"Element not found";
    }
    else
    {
        cout<<"The position of the element is "<<pos+1;
    }
    return 0;
}