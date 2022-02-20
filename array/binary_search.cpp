#include<iostream>
#include<vector>
using namespace std;
int binary_search(int x,vector<int>arr)
{
    int first = 0;
  int last = arr.size() - 1;

  while (first <= last)
   {
   	int middle = (first+last)/2;

    if (arr[middle] < x)
      first = middle + 1;
    else if (arr[middle] == x) {
      printf("%d found at location %d.\n", x, middle+1);
      break;
    }
    else
      last = middle - 1;
  }
  if (first > last)
    printf("Not found! %d isn't present in the list.\n", x);

  return 0;
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
    binary_search(x,arr);

    return 0;
}