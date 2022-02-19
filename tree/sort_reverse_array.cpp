#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the limit: ";
    cin>>n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int var;
        cin>>var;
        arr.push_back(var);
    }
    //arr.pop_back();
    cout<<"\nSorting the array";
    cout << "\n";
    sort(arr.begin(),arr.end(),greater<int>());

    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    reverse(arr.begin(), arr.end());
    cout << "\nReversing the array";
    cout << "\n";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
 return 0;
}