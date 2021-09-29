/**
 * @file 10. coordinate compression.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-30 17:36:12
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int num;
    cin >> num;
    vector<int> v(num); // 0�� ���� ���� ĭ�� num�� ���� ���� ����
    for (int i = 0; i < num; i++)
        cin >> v[i];

    vector<int> cv(v);                                // v���͸� �����Ͽ� cv�� ����
    sort(cv.begin(), cv.end());                       // �����Ͽ�
    cv.erase(unique(cv.begin(), cv.end()), cv.end()); // �ߺ��� ����

    for (int i = 0; i < num; i++)
        cout << lower_bound(cv.begin(), cv.end(), v[i]) - cv.begin() << " "; // lower_bound�� cv���� v[i]�� �ּҸ� ��ȯ�ϴ� �Լ�

    return 0;
}