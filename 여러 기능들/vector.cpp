#include <iostream>
#include <vector> // �ڵ����� �޸𸮰� �Ҵ�Ǵ� �迭, �ణ ���ð��� ���
#include <algorithm>
#include <numeric> // accumulate��(���� �� ���ҵ��� ��) �ҷ����� ����

using namespace std;

// ���� ������ vector<[data type]> [�����̸�];
//vector<int> v;       // ����ִ� vector v�� ����
//vector<int> v(5);    // �⺻��(0)���� �ʱ�ȭ �� ���� 5���� ������ vector v�� ����
//vector<int> v(5, 2); // 2�� �ʱ�ȭ �� ���� 5���� ������ vector v�� ����
//vector<int> v2(v);   // v�� �����Ͽ� ������ vector v2

int main()
{
    //int idx = 0, n = 5, start = 0, end = 7;
    //vector<int> v;
    //vector<int>::iterator iter = v.begin();

    // ��� �Լ�
    //v.assign(5, 2); // 5���� ������ ���� 2�� �Ҵ�
    //v.at(idx);      // idx��° ���Ҹ� ����, v[idx]���� �������� ������ ����
    //v[idx];         // idx��° ���Ҹ� ����, ���� ������ ���� �ʾ� ����
    //v.front();      // ù ��° ����
    //v.back();       // ������ ����
    //v.clear();      // ��� ���� ����, ���Ҹ� �����ϰ� �޸𸮴� ��������, size�� �پ��� capacity�� �״��
    //v.push_back(7); // ������ ���� �ڿ� ���� 7�� ����
    //v.pop_back();   // ������ ���� ����
    //v.begin();      // ù��° ���Ҹ� ����Ų��, iterator�� ���
    //v.end();        // �������� ������ ����Ų��, iterator�� ���
    //v.rbegin();     // reverse begin(�Ųٷ� ������ ó��), iterator�� ���
    //v.rend();       // reverse end(�Ųٷ� ������ �������� ����), iterator�� ���
    //v.reserve(n);   // n���� ���Ҹ� ������ ��ġ�� ����(�̸� �����Ҵ�)
    //v.resize(n);    // ũ�⸦ n���� ����, �� Ŀ���� ��� 0���� �ʱ�ȭ
    //v.resize(n, 3); // ũ�⸦ n���� ����, �� Ŀ���� ��� 3���� �ʱ�ȭ
    //v.size();       // ������ ������ ����
    //v.capacity();   // �Ҵ�� ������ ũ�⸦ ����
    //v2.swap(v);     // v�� v2�� capacity�� �ٲ�(��� �� �ٲ�)
    // vector<int>().swap(v); // ���α׷��� ������ �� �Ҵ�� �޸𸮸� �����ϰ� ���� �� ���
    //v.insert(2, 3, 4); // 2��° ��ġ�� 3���� 4���� ����(�ڿ� �ִ� ������ �ڷ� �и�)
    //v.insert(2, 3);      // 2��° ��ġ�� 3�� ���� ����, ������ ���� iterator�� ��ȯ
    //v.erase(iter);       // iter�� ����Ű�� ���� ����, size�� �پ��
    //v.erase(start, end); // start ~ end - 1��°���� ����
    //v.empty(); // vector�� ��������� true, size�� 0�� ���� �ǹ�(capacity�� 0�̶� �ǹ̴� �ƴ�)

    // capacity�� �Ҵ�� �޸� ����, size�� ä���� ���� ����

    // vector ��� ����
    // iterator: �ݺ��� ����
    // reverse iterator: �� �ݺ��� ����
    // value_type: ������ ����
    // size_type: ������ ������ ����

    /* 2���� ���� ���� ��, �ʱ�ȭ(�� �� �ϳ��� ����ϸ� ��)*/
    //int n, m;
    //vector<vector<int>> arr(n, vector<int>(m, 0)); // n x m �������� int�� ���� arr�� 0���� �ʱ�ȭ

    //// n x m �������� int�� ���� arr�� 0���� �ʱ�ȭ
    //vector<vector<int>> arr;
    //arr.assign(n, vector<int>(m, 0));

    // -------------------------------------------------------------------------------------------------------

    /* vector �ȿ� ����ִ��� Ȯ���ϴ� �Լ� */
    vector<string> word;
    string str = "test";
    string str2 = "test";
    string str3 = "exam";

    word.push_back(str);

    if (find(word.begin(), word.end(), str2) == word.end()) // �������� ������ ������ ���� ��ȯ
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

    /* ���� �ٸ� Ÿ���� ���� �迭 ���� �� */
    pair<int, string> tmp;         // ������ ���ڿ��� ���� tmp
    vector<pair<int, string>> arr; // tmp�� ������ vector

    tmp.first = 6;       // first�� ù ������ ����
    tmp.second = "����"; // second�� �ι�° ������ ����
    arr.push_back(tmp);
    cout << arr[0].first << " " << arr[0].second << '\n'; // ��µ� first, second �̿�

    // ----------------------------------------------------------------------------------------------------------------

    /* unique �Լ� */
    vector<int> v(7);
    v[0] = 1;
    v[1] = 2;
    v[2] = 2;
    v[3] = 3;
    v[4] = 4;
    v[5] = 4;
    v[6] = 5;
    // v�� [1, 2, 2, 3, 4, 4, 5] ������ ���� ������ vector�̴�

    unique(v.begin(), v.end()); // �������� �ߺ��� ���� ����, �׷��⿡ ���� ������ �ʼ������� �ؾ���
    // [1, 2, 3, 4, 5, 4, 5] �ߺ����� ������ 5���� ���� ���� �����ϰ� ���� �κ��� ��������
    // ������ ������ ���ҵ��� ù��° �ּҰ��� ��ȯ

    v.erase(unique(v.begin(), v.end()), v.end()); // �ߺ����� ���� ���鸸 ����

    // ----------------------------------------------------------------------------------------------------------------

    /* lower_bound */
    lower_bound(v.begin(), v.end(), 2); // v���� 2�� ���ų� ū �� �� ù��° �ּҰ� ��ȯ
    upper_bound(v.begin(), v.end(), 2); // v���� 2���� ū �� �� ù��° �ּҰ� ��ȯ

    // ----------------------------------------------------------------------------------------------------------------

    /* ���� ���ҵ��� �հ� ��, numeric ��� ���� �ʿ� */
    vector<int> num{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = accumulate(num.begin(), num.end(), 0);                        // 55, ��� ���ҵ��� ��
    int product = accumulate(num.begin(), num.end(), 1, multiplies<int>()); // 3628800, ��� ���ҵ��� ��

    cout << sum << " " << product << '\n';

    // ----------------------------------------------------------------------------------------------------------------

    /* ���� ���� ��, �ִ밪�� �ּҰ�, algorithm ��� ���� �ʿ� */
    // max_element�� �ִ밪�� ����Ű�� �ݺ��ڸ� ��ȯ�ϱ⿡ *�����ڸ� �̿��Ͽ� �ִ밪�� ���� �� �ִ�
    vector<int> num2{1, 2, 3, 15, 20, -5, 4, 5, 6, 7, 8, 9, 10};

    cout << *max_element(num2.begin(), num2.end()) << " ";                // 20, �ִ밪
    cout << max_element(num2.begin(), num2.end()) - num2.begin() << '\n'; // 4, �ִ밪�� �ε���

    cout << *min_element(num2.begin(), num2.end()) << " ";                // -5, �ּҰ�
    cout << min_element(num2.begin(), num2.end()) - num2.begin() << '\n'; // 5, �ּҰ��� �ε���

    // ----------------------------------------------------------------------------------------------------------------

    /* ���� ���Ҹ� �ٷ� ��� */
    vector<int> v = {1, 2, 3, 4, 5, 6};
    for (auto x : v)
        cout << x << " ";

    return 0;
}
