using namespace std;

bool solution(int x)
{
    int copy_x = x;
    int tmp = 0;

    while (copy_x > 0)
    {
        tmp += copy_x % 10;
        copy_x /= 10;
    }

    if (x % tmp == 0)
        return true;
    return false;
}