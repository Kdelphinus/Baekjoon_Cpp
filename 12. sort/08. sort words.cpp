/**
 * @file 08. sort words.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-28 15:25:18
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comapare(string a, string b) // 길이순으로 정렬하기 위해
{
    if (a.length() == b.length()) // 길이가 같다면
        return a < b;             // 알파벳 순으로
    return a.length() < b.length();
}

int main()
{
    int num;
    vector<string> words;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        string str;
        cin >> str;
        if (find(words.begin(), words.end(), str) == words.end()) // 중복된 단어는 추가하지 않음
            words.push_back(str);
    }
    sort(words.begin(), words.end(), comapare); // compare을 빼면 알파벳 순으로 정렬

    for (int i = 0; i < words.size(); i++)
        cout << words[i] << "\n";

    return 0;
}