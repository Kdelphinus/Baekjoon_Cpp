#include <iostream>
#include <vector> // 자동으로 메모리가 할당되는 배열, 약간 스택과도 비슷
#include <algorithm>
#include <numeric> // accumulate를(벡터 내 원소들의 합) 불러오기 위해

using namespace std;

// 벡터 선언은 vector<[data type]> [변수이름];
//vector<int> v;       // 비어있는 vector v를 생성
//vector<int> v(5);    // 기본값(0)으로 초기화 된 원소 5개를 가지는 vector v를 생성
//vector<int> v(5, 2); // 2로 초기화 된 원소 5개를 가지는 vector v를 생성
//vector<int> v2(v);   // v를 복사하여 생성한 vector v2

int main()
{
    //int idx = 0, n = 5, start = 0, end = 7;
    //vector<int> v;
    //vector<int>::iterator iter = v.begin();

    // 멤버 함수
    //v.assign(5, 2); // 5개의 원소의 값을 2로 할당
    //v.at(idx);      // idx번째 원소를 참조, v[idx]보단 느리지만 범위를 점검
    //v[idx];         // idx번째 원소를 참조, 범위 점검을 하지 않아 빠름
    //v.front();      // 첫 번째 원소
    //v.back();       // 마지막 원소
    //v.clear();      // 모든 원소 제거, 원소만 제거하고 메모리는 남아있음, size만 줄어들고 capacity는 그대로
    //v.push_back(7); // 마지막 원소 뒤에 원소 7을 삽입
    //v.pop_back();   // 마지막 원소 제거
    //v.begin();      // 첫번째 원소를 가리킨다, iterator와 사용
    //v.end();        // 마지막의 다음을 가리킨다, iterator와 사용
    //v.rbegin();     // reverse begin(거꾸로 뒤집어 처음), iterator와 사용
    //v.rend();       // reverse end(거꾸로 뒤집어 마지막의 다음), iterator와 사용
    //v.reserve(n);   // n개의 원소를 저장할 위치를 예약(미리 동적할당)
    //v.resize(n);    // 크기를 n으로 변경, 더 커졌을 경우 0으로 초기화
    //v.resize(n, 3); // 크기를 n으로 변경, 더 커졌을 경우 3으로 초기화
    //v.size();       // 원소의 개수를 리턴
    //v.capacity();   // 할당된 공간의 크기를 리턴
    //v2.swap(v);     // v와 v2의 capacity를 바꿈(모든 걸 바꿈)
    // vector<int>().swap(v); // 프로그램이 끝나기 전 할당된 메모리를 제거하고 싶을 때 사용
    //v.insert(2, 3, 4); // 2번째 위치에 3개의 4값을 삽입(뒤에 있는 값들은 뒤로 밀림)
    //v.insert(2, 3);      // 2번째 위치에 3의 값을 삽입, 삽입한 곳의 iterator를 반환
    //v.erase(iter);       // iter가 가리키는 원소 제거, size만 줄어듬
    //v.erase(start, end); // start ~ end - 1번째까지 삭제
    //v.empty(); // vector가 비어있으면 true, size가 0인 것을 의미(capacity가 0이란 의미는 아님)

    // capacity는 할당된 메모리 공간, size는 채워진 원소 개수

    // vector 멤버 형식
    // iterator: 반복자 형식
    // reverse iterator: 역 반복자 형식
    // value_type: 원소의 형식
    // size_type: 원소의 개수의 형식

    /* 2차원 벡터 생성 후, 초기화(둘 중 하나를 사용하면 됨)*/
    //int n, m;
    //vector<vector<int>> arr(n, vector<int>(m, 0)); // n x m 사이즈의 int형 벡터 arr을 0으로 초기화

    //// n x m 사이즈의 int형 벡터 arr을 0으로 초기화
    //vector<vector<int>> arr;
    //arr.assign(n, vector<int>(m, 0));

    // -------------------------------------------------------------------------------------------------------

    /* vector 안에 들어있는지 확인하는 함수 */
    vector<string> word;
    string str = "test";
    string str2 = "test";
    string str3 = "exam";

    word.push_back(str);

    if (find(word.begin(), word.end(), str2) == word.end()) // 존재하지 않으면 마지막 값을 반환
        cout << "not exist\n";
    else
        cout << "exist\n";

    if (find(word.begin(), word.end(), str3) == word.end())
        cout << "not exist\n";
    else
        cout << "exist\n";

    // exist
    // not exist

    // ----------------------------------------------------------------------------------------------------------------

    /* 서로 다른 타입의 이중 배열 만들 때 */
    pair<int, string> tmp;         // 정수와 문자열을 받을 tmp
    vector<pair<int, string>> arr; // tmp를 저장할 vector

    tmp.first = 6;       // first로 첫 변수에 저장
    tmp.second = "나이"; // second로 두번째 변수에 저장
    arr.push_back(tmp);
    cout << arr[0].first << " " << arr[0].second << '\n'; // 출력도 first, second 이용

    // ----------------------------------------------------------------------------------------------------------------

    /* unique 함수 */
    vector<int> v(7);
    v[0] = 1;
    v[1] = 2;
    v[2] = 2;
    v[3] = 3;
    v[4] = 4;
    v[5] = 4;
    v[6] = 5;
    // v는 [1, 2, 2, 3, 4, 4, 5] 순서로 값을 저장한 vector이다

    unique(v.begin(), v.end()); // 연속으로 중복된 값만 제거, 그렇기에 먼저 정렬을 필수적으로 해야함
    // [1, 2, 3, 4, 5, 4, 5] 중복값을 제거한 5가지 수를 먼저 저장하고 남은 부분은 원본유지
    // 원본이 유지된 원소들의 첫번째 주소값을 반환

    v.erase(unique(v.begin(), v.end()), v.end()); // 중복되지 않은 값들만 남음

    // ----------------------------------------------------------------------------------------------------------------

    /* lower_bound */
    lower_bound(v.begin(), v.end(), 2); // v에서 2와 같거나 큰 것 중 첫번째 주소값 반환
    upper_bound(v.begin(), v.end(), 2); // v에서 2보다 큰 수 중 첫번째 주소값 반환

    // ----------------------------------------------------------------------------------------------------------------

    /* 벡터 원소들의 합과 곱, numeric 헤더 파일 필요 */
    vector<int> num{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = accumulate(num.begin(), num.end(), 0);                        // 55, 모든 원소들의 합
    int product = accumulate(num.begin(), num.end(), 1, multiplies<int>()); // 3628800, 모든 원소들의 곱

    cout << sum << " " << product << '\n';

    // ----------------------------------------------------------------------------------------------------------------

    /* 벡터 원소 중, 최대값과 최소값, algorithm 헤더 파일 필요 */
    // max_element는 최대값을 가리키는 반복자를 반환하기에 *연산자를 이용하여 최대값을 구할 수 있다
    vector<int> num2{1, 2, 3, 15, 20, -5, 4, 5, 6, 7, 8, 9, 10};

    cout << *max_element(num2.begin(), num2.end()) << " ";                // 20, 최대값
    cout << max_element(num2.begin(), num2.end()) - num2.begin() << '\n'; // 4, 최대값의 인덱스

    cout << *min_element(num2.begin(), num2.end()) << " ";                // -5, 최소값
    cout << min_element(num2.begin(), num2.end()) - num2.begin() << '\n'; // 5, 최소값의 인덱스

    // ----------------------------------------------------------------------------------------------------------------

    /* 벡터 원소를 바로 출력 */
    vector<int> v = {1, 2, 3, 4, 5, 6};
    for (auto x : v)
        cout << x << " ";

    return 0;
}
