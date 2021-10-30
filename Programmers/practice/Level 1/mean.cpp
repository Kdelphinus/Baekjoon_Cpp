#include <vector>
#include <numeric>

using namespace std;

double solution(vector<int> arr)
{
    double sum = accumulate(arr.begin(), arr.end(), 0);
    double len = arr.size();
    return sum / len;
}