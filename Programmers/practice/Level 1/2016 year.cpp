#include <string>
#include <vector>
using namespace std;

int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

string solution(int a, int b)
{
    int days = b;
    while (a > 1)
    {
        a--;
        days += month[a - 1];
    }
    return day[days % 7];
}