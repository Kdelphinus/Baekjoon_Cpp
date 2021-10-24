#include <iostream>
using namespace std;

/* 첫 번째 예 */
int *MultiplyArrayByTwo(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] *= 2;
    }
    return arr;
}

int main()
{
    constexpr int size = 10;
    int c_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int *ptr = MultiplyArrayByTwo(c_array, size);

    cout << "array = [ ";
    for (int i = 0; i < size; ++i)
    {
        cout << ptr[i] << ", ";
    }
    cout << "]" << endl;

    return EXIT_SUCCESS;
}

// --------------------------------------------------------------------------------

/* 두 번째 예 */
int *function()
{
    int *a = (int *)malloc(sizeof(int) * 30);
    a[0] = 10;
    a[1] = 20;
    return a;
}

int main(void)
{
    int *b;
    b = function();
    printf("%d %d", b[0], b[1]);
}