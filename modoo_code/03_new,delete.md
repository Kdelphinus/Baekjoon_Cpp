# 3. new, delete

C++������ ���� ���� �޸𸮴� ����ڰ� ������ �����ؾ� �Ѵ�.
C�� `malloc` �� `free` �� ���� ����� ���� ������ C++ �������� `new` �� `delete` �� �����Ѵ�.

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
# ���� ���
10
```

�������� ���� `new` �� ��� ����� ������ ����.

```c++
T* pointer = new T;
```

�̸� ���� �Ҵ��ϰ� `new` �� ���� �Ҵ��� ������ `delete` �� ���� �����Ѵ�.

���� ���� ������ `delete` �� �����Ϸ� �Ѵٸ� `Heap` �� �ƴ� ������ �����Ϸ� �Ѵٰ� ��� �޼����� ����.

### new�� �迭 �Ҵ��ϱ�

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
# ���� ���
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

���� ���� ���� ũ�Ⱑ 2 �̻��� �迭�� �Ҵ��� ���� `[]` �� ���ؼ� �迭�� ũ�⸦ �־��ָ� �ȴ�.

```c++
T* pointer = new T[size];
```

```c++
int a = 4;
{
  std::cout << "�ܺ��� ���� 1" << a << std::endl;
  int a = 3;
  std::cout << "������ ���� " << a << std::endl;
}

std::cout << "�ܺ��� ���� 2" << a << std::endl;
```

���⼭ C++�� �� �Լ� ��ܿ��� ������ �������� �ʾƵ� ���� �� ���� �ִ�.
�̶�, ������ ���� ����� �������� ã�� �ȴ�.

���� �ڵ带 ���÷� ���� �켱 `�ܺ��� ���� 1` �� ����� ������ �ϳ��̹Ƿ� 4�� ����Ѵ�.
`������ ����` �� ����� a�� �� ���ε� ���� ����� ������ ������ 3�� ����ϰ� �ȴ�.
���������� `�ܺ��� ���� 2` �� 4�� ��µǴµ� �̴� ������ ����� ��ġ�� �߰�ȣ�� ���� ��, �Ҹ�Ǳ� �����̴�.
��, 3�� ���� ���� a�� �߰�ȣ�� �����鼭 �Ҹ�ȴ�.

���� �̷��� ���� �������� ���� ���� ���� ������ �ٸ� �������� ���� ���� ���� ����.

���� ���� ������ for�� �ȿ��� ����� i���� �����ϰ� �����ȴ�. ��, for���� ������ i�� �Ҹ�ȴ�.

���������� `delete` �� `new` �� ���������� `[]` �� ǥ�����ָ� �ȴ�.
