# 1. C++ 시작

## 1-2 첫 C++ 프로그램 분석하기

```c++
#include <iostream>

int main(){
	std::cout << "Hello, World!!" << std::endl;
	return 0;
}
```

### namespace(이름 공간)

먼저 ```cout``` 앞에 붙은 ```std``` 는 c++ 표준 라이브러리의 모든 함수, 객체 등이 정의된 **이름 공간** 이다.

> 표준 라이브러리, 객체는 추후 개념이 나오며 지금은 iostream이 c++에서 제공하는 출력을 위한 표준 라이브러리 정도로 생각하면 된다.

이러한 이름 공간은 어떤 정의된 객체에 대해 어디 소속인지 지정해주는 역할을 한다. 
이는 코드의 규모가 커지면서 중복된 이름을 가진 함수들이 많아졌고 이에 중복된 이름의 함수들을 구분하기 위해 생기게 되었다.

예를 들어 두 개의 헤더에 같은 이름이 있다고 가정하자

```c++
// header1.h 의 내용
namespace header1 {
int foo();
void bar();
}
```

```c++
// header2.h 의 내용
namespace header2 {
int foo();
void bar();
}
```

먼저 자기 자신이 포함되어 있는 이름 공간 안에서는 굳이 이름 공간을 명시하지 않아도 된다.

```c++
#include "header1.h"

namespace header1 {
int func() {
  foo();  // 알아서 header1::foo() 가 실행된다.
}
}  // namespace header1
```

또한 header2의 이름 공간을 알려주면 header1의 이름 공간 안에서도 호출이 가능하다.

```c++
#include "header1.h"
#include "header2.h"

namespace header1 {
int func() {
foo();           // 알아서 header1::foo() 가 실행된다.
header2::foo();  // header2::foo() 가 실행된다.
}
}  // namespace header1
```

허나 이름 공간을 알려주지 않는다면 우리는 명시적으로 이름 공간을 지정해야 한다.

```c++
#include "header1.h"
#include "header2.h"

int func() {
	header1::foo(); // header1 이란 이름 공간에 있는 foo() 함수 호출
}
```

이름 공간을 파일 시작점에 선언하여 함수를 실행할 때마다 선언하지 않게 할 수도 있다.

```c++
#include "header1.h"
#include "header2.h"

using header1::foo;
int main() {
  foo();  // header1 에 있는 함수를 호출
}
```

```c++
#include "header1.h"
#include "header2.h"

using namespace header1;
int main() {
foo();  // header1 에 있는 함수를 호출
bar();  // header1 에 있는 함수를 호출
}
```

첫 번째는 하나의 함수만 지정하는 것이고 두 번째는 이름 공간 자체를 명시하는 것이다.

> ## 주의 사항
> 허나 `using namespace std;` 와 같이 이름 공간 자체를 사용하겠다는 선언은 권장되지 않는다.
> 왜냐하면, `std` 안에 있는 함수와 겹치는 함수를 만들면 오류가 발생하기 때문인데 `std` 안에는 너무나 많은 함수가 있어서 다 확인이 불가하기 떄문이다.
> 
> 그렇기에 `std::` 를 직접 붙이는 것을 권장한다.

### 이름 없는 이름 공간

c++에선 이름이 없는 이름 공간을 설정할 수 있다. 이 경우는 `static` 키워드를 사용한 효과를 낸다.

```c++
#include <iostream>

namespace {
// 이 함수는 이 파일 안에서만 사용할 수 있습니다.
// 이는 마치 static int OnlyInThisFile() 과 동일합니다.
int OnlyInThisFile() {}

// 이 변수 역시 static int x 와 동일합니다.
int only_in_this_file = 0;
}  // namespace

int main() {
  OnlyInThisFile();
  only_in_this_file = 3;
}
```

위 함수에서 선언한 `OnlyInThisFile` 함수나 `only_in_this_file` 변수는 해당 파일에서만 접근이 가능하다.

## 1-3 C++과 C의 공통점

- 변수 정의
- 배열과 포인터 정의
- 반복문과 조건문
