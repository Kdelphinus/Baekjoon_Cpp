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
    vector<int> v(num); // 0의 값을 가진 칸을 num개 가진 벡터 생성
    for (int i = 0; i < num; i++)
        cin >> v[i];

    vector<int> cv(v);                                // v벡터를 복사하여 cv로 저장
    sort(cv.begin(), cv.end());                       // 정렬하여
    cv.erase(unique(cv.begin(), cv.end()), cv.end()); // 중복값 제거

    for (int i = 0; i < num; i++)
        cout << lower_bound(cv.begin(), cv.end(), v[i]) - cv.begin() << " "; // lower_bound는 cv에서 v[i]의 주소를 반환하는 함수

    return 0;
}