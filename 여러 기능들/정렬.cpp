#include <iostream>
#include <algorithm>
#include <vector>

bool desc(int a, int b) // ���������� ���� �Լ�
{
    return a > b;
}

bool compare(std::pair<int, std::string> a, std::pair<int, std::string> b) // ���Լ����� �����ϰ� ����� �Լ�
{
    return a.first < b.first;
}

int main()
{
    int arr[10] = {3, 1, 2, 5, 6, 8, 7, 9, 4, 10};

    std::sort(arr, arr + 10); // ��������, �迭�� ũ�⸦ �����ش�
    for (int i = 0; i < 10; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    std::sort(arr, arr + 10, desc); // ��������
    for (int i = 0; i < 10; i++)
        std::cout << arr[i] << " ";

    //-----------------------------------------------------------------------------------
    /* int�� �������� ���ĵǸ� int�� ������ �Էµ� ������ ���ĵȴ�. ��, string�� ���Ŀ� ������ ��ġ�� �ʴ´�
    stable_sort�� ����ϸ� ���� ũ���� ��, ���� ����(�Էµ� ����)�� �����ϵ��� ����� */
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
    stable_sort(age_name.begin(), age_name.end(), compare); // ũ�Ⱑ ���� ���Ҵ� ����� ��ġ�� �ٲ��� �ʵ��� �Ѵ�
    for (int i = 0; i < num; i++)
        std::cout << age_name[i].first << " " << age_name[i].second << '\n';
    return 0;
}