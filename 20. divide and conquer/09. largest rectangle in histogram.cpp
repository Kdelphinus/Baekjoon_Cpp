#include <iostream>
#include <vector>

using namespace std;

vector<long long> hist;

long long largest_rectangle(int start, int end)
{
    if (start == end)
        return hist[start];

    int mid = (start + end) / 2;
    int start_point = mid;
    int end_point = mid;
    long long height = hist[mid];
    long long ret = max(largest_rectangle(start, mid), largest_rectangle(mid + 1, end));

    while (start < start_point || end_point < end)
    {
        if (start < start_point && (end_point == end || hist[start_point - 1] < hist[end_point + 1]))
        {
            start_point--;
            height = min(height, hist[start_point]);
        }
        else
        {
            end_point++;
            height = min(height, hist[end_point]);
        }
        ret = max(ret, height * (end_point - start_point + 1));
    }

    return ret;
}

int main()
{
    int num, tmp;

    while (1)
    {
        cin >> num;

        if (num == 0)
            break;

        for (int i = 0; i < num; i++)
        {
            cin >> tmp;
            hist.push_back(tmp);
        }

        cout << largest_rectangle(0, num - 1) << "\n";

        hist.clear();
    }

    return 0;
}