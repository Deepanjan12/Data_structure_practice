#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int>bus;
    bus.push(30);
    bus.push(40);
    bus.push(56);
    // cout<<bus.top();
    // cout<<"\n"<<bus.size();
    // cout<<"\n"<<bus.empty();
    // bus.pop();
    // cout<<"\n"<<bus.top();
    // bus.pop();
    // cout << "\n"<< bus.top();
    // bus.pop();
    // cout << "\n"<< bus.top();
    // bus.pop();
    // cout << "\n" << bus.top();
    while(!bus.empty())
    {
        cout<<"\n"<<bus.front();
        bus.pop();
    }
    return 0;
}