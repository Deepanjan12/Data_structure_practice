#include<bits/stdc++.h>
using namespace std;

int main(){
    bool flag = false;
    vector<int> arr{25,36,91,88,54,12};
    vector<int> arr1{91,36,12,25,40,54,88};
    sort(arr.begin(),arr.end());
    sort(arr1.begin(),arr1.end());
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]!=arr1[i])
        {
            cout<<arr1[i];
            flag = true;
            break;
        }
    }
    if(flag==false)
    {
        cout<<arr1[arr1.size()-1];
    }
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr{25,36,91,88,54,12};
    vector<int> arr1{91,36,12,25,40,54,88};
    int x=arr1[arr1.size()-1];
    for(int i=0;i<arr.size();i++)
    {
        x=x^arr[i]^arr1[i];
    }
     cout<<x;

    return 0;
}*/