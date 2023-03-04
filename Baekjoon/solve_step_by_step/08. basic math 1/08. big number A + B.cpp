/**
 * @file 08. big number A + B.cpp
 * @author Kdelphinus (delphinus@khu.ac.kr)
 * @brief 
 * @date 2021-07-24 15:15:56
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <string>

char result[10002];

int main()
{
    int tmp, len_a, len_b, len_r, idx = 0, flag = 0;
    std::string a, b; // 숫자가 크기에 문자열로 받는다
    std::cin >> a >> b;

    len_a = a.length() - 1;
    len_b = b.length() - 1;

    while (0 <= len_a && 0 <= len_b) // 둘 중 하나의 수라도 모든 자릿수를 더했다면 종료
    {
        tmp = (a[len_a] - '0') + (b[len_b] - '0'); // 같은 자릿수의 수를 더한다

        if (flag) // 만약 전의 자릿수에서 올라온 것이 있다면 더한다
            tmp++;

        if (tmp >= 10) // 자릿수의 합이 10을 넘어가면 다음 자릿수로 1을 올리고 나머지만 취한다
        {
            flag = 1;
            tmp %= 10;
        }
        else if (flag == 1) // 자릿수의 합이 10을 넘지 않는데 flag가 1이라면 0으로 바꿔준다
            flag = 0;

        result[idx] = tmp + '0'; // 자릿수의 합을 문자열로 저장한다
        idx++;                   // result 인덱스 이동
        len_a--;                 // 다음 자릿수로 이동
        len_b--;                 // 다음 자릿수로 이동
    }

    if (0 <= len_a) // 만약 a가 아직 남았다면
    {
        while (flag) // 자릿수 올림받을 것이 있다면
        {
            if (len_a >= 0)                   // 아직 a가 남았다면
                tmp = (a[len_a--] - '0') + 1; // 남은 것과 올라온 것을 더하고
            else                              // a도 모두 더했다면
                tmp = 1;                      // 올라온 것만 다음 자리에 더한다
            if (tmp >= 10)                    // tmp가 10이 넘는다면 다음 자리에 수를 올리고
                tmp %= 10;
            else // 아니라면 flag를 0으로 바꾼다
                flag = 0;
            result[idx++] = tmp + '0'; // 더한 자릿수를 저장
        }
        for (int i = len_a; i >= 0; i--) // 남은 a를 모두 저장한다
            result[idx++] = a[i];
    }
    else if (0 <= len_b) // 만약 b가 남았다면 a와 같은 방식으로 남은 것을 저장
    {
        while (flag)
        {
            if (len_b >= 0)
                tmp = (b[len_b--] - '0') + 1;
            else
                tmp = 1;
            if (tmp >= 10)
                tmp %= 10;
            else
                flag = 0;
            result[idx++] = tmp + '0';
        }
        for (int i = len_b; i >= 0; i--)
            result[idx++] = b[len_b];
    }
    else if (flag) // 만약 둘 다 모두 더했지만 올라온 수가 있다면 다음 자리에 1을 추가
        result[idx++] = '1';

    for (int i = idx - 1; i > -1; i--) // 거꾸로 출력
    {
        std::cout << result[i];
    }

    return 0;
}