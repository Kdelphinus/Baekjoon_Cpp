#include <iostream>
#include <algorithm>
#include <vector>

bool desc(int a, int b) // 내림차순을 위한 함수
{
    return a > b;
}

bool compare(std::pair<int, std::string> a, std::pair<int, std::string> b) // 가입순으로 정렬하게 만드는 함수
{
    return a.first < b.first;
}

int main()
{
    int arr[10] = {3, 1, 2, 5, 6, 8, 7, 9, 4, 10};

    std::sort(arr, arr + 10); // 오름차순, 배열의 크기를 더해준다
    for (int i = 0; i < 10; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    std::sort(arr, arr + 10, desc); // 내림차순
    for (int i = 0; i < 10; i++)
        std::cout << arr[i] << " ";

    //-----------------------------------------------------------------------------------
    /* int를 기준으로 정렬되며 int가 같으면 입력된 순으로 정렬된다. 즉, string은 정렬에 영향을 끼치지 않는다
    stable_sort를 사용하면 같은 크기일 때, 원래 순서(입력된 순서)를 유지하도록 만든다 */
    int num;
    std::cin >> num;
    std::pair<int, std::string> tmp;
    std::vector<std::pair<int, std::string>> age_name;
    for (int i = 0; i < num; i++)
    {
        std::cin >> tmp.first >> tmp.second;
        age_name.push_back(tmp);
    }
    std::cout << '\n';
    stable_sort(age_name.begin(), age_name.end(), compare); // 크기가 같은 원소는 상대적 위치가 바뀌지 않도록 한다
    for (int i = 0; i < num; i++)
        std::cout << age_name[i].first << " " << age_name[i].second << '\n';
    return 0;
}