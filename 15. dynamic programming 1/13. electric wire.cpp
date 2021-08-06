#include <iostream>
#include <vector>

using namespace std;

int remove_wire(int num)
{
    pair<int, int> wire;
    vector<pair<int, int>> wires;
    for (int i = 0; i < num; i++)
    {
        cin >> wire.first >> wire.second;
        wires.push_back(wire);
    }
}

int main()
{
    int num;
    cin >> num;
    cout << remove_wire(num);
    return 0;
}