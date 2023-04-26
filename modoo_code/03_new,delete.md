# 3. new, delete

C++에서도 역시 힙의 메모리는 사용자가 스스로 제어해야 한다.
C의 `malloc` 과 `free` 를 직접 사용할 수도 있지만 C++ 차원에서 `new` 와 `delete` 를 지원한다.

```c++
#include <iostream>

int main() {
  int* p = new int;
  *p = 10;

  std::cout << *p << std::endl;

  delete p;
  return 0;
}
```

```shell
# 실행 결과
10
```

위에서와 같이 `new` 의 사용 방법은 다음과 같다.

```c++
T* pointer = new T;
```

이를 통해 할당하고 `new` 를 통해 할당한 공간은 `delete` 를 통해 해제한다.

만약 지역 변수를 `delete` 로 제거하려 한다면 `Heap` 이 아닌 공간을 해제하려 한다고 경고 메세지를 띄운다.

### new로 배열 할당하기

```c++
#include <iostream>

int main() {
  int arr_size;
  std::cout << "array size : ";
  std::cin >> arr_size;
  int *list = new int[arr_size];
  for (int i = 0; i < arr_size; i++) {
    std::cin >> list[i];
  }
  for (int i = 0; i < arr_size; i++) {
    std::cout << i << "th element of list : " << list[i] << std::endl;
  }
  delete[] list;
  return 0;
}
```

```shell
# 실행 결과
array size : 5
1
4
2
6
8
0th element of list : 1
1th element of list : 4
2th element of list : 2
3th element of list : 6
4th element of list : 8
```

먼저 위와 같이 크기가 2 이상인 배열을 할당할 때는 `[]` 를 통해서 배열의 크기를 넣어주면 된다.

```c++
T* pointer = new T[size];
```

```c++
int a = 4;
{
  std::cout << "외부의 변수 1" << a << std::endl;
  int a = 3;
  std::cout << "내부의 변수 " << a << std::endl;
}

std::cout << "외부의 변수 2" << a << std::endl;
```

여기서 C++은 꼭 함수 상단에서 변수를 선언하지 않아도 됨을 알 수도 있다.
이때, 변수는 가장 가까운 범위부터 찾게 된다.

위의 코드를 예시로 보면 우선 `외부의 변수 1` 은 선언된 변수가 하나이므로 4를 출력한다.
`내부의 변수` 는 선언된 a가 두 개인데 가장 가까운 범위의 변수인 3을 출력하게 된다.
마지막으로 `외부의 변수 2` 는 4가 출력되는데 이는 변수는 선언된 위치의 중괄호가 끝날 때, 소멸되기 때문이다.
즉, 3을 가진 변수 a는 중괄호가 끝나면서 소멸된다.

물론 이렇게 같은 변수명을 짓는 것은 좋지 않으며 다른 변수명을 짓는 것이 가장 좋다.

위와 같은 동작은 for문 안에서 선언된 i에도 동일하게 적욛된다. 즉, for문이 끝나면 i는 소멸된다.

마지막으로 `delete` 는 `new` 와 마찬가지로 `[]` 을 표시해주면 된다.
