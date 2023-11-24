

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> network;

    while (!network.empty()) {
        cout << ' ' << network.front();
        network.pop();
    }
}