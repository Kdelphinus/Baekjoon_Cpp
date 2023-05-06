# 5. Overloading

## 5-1 내가 만든 연산자 - 연산자 오버로딩

c언어에서 `+, -, ==, []` 와 같은 기본 연산자들을 기본적으로 정의되어 있는 데이터 타입( `int, float` 등) 이외의 타입에서 사용하는 것은 불가하다.
하지만 c++에서는 사용자 정의 연산자를 사용할 수 있다. 정확히 `::` (범위 지정), `.` (멤버 지정) `.*` (멤버 포인터로 멤버 지정)을 제외한 모든 연산자를 사용할 수 있다.

대표적으로 다음과 같다.

- `+, -, *` 와 같은 산술 연산
- `+=. -=` 와 같은 축약형 연산자
- `>=, ==` 와 같은 비교 연산자
- `&&, ||` 와 같은 논리 연산자
- `->` 나 `*` 와 같은 멤버 선택 연산자(여기서 `*` 는 역참조 연산자)
- `++, --` 증감 연산자
- `[]` (배열 연산자)와 심지어 `()` (함수 호출 연산자)까지

이때, 이러한 기본 연산자들을 직접 사용자가 정의하는 것을 **"연산자를 오버로딩 한다"** 라고 부른다.

### MyString의 '==' 연산자 오버로딩

일단 연산자 오버로딩을 사용하기 위해서는, 다음과 같이 오버로딩을 원하는 연산자 함수를 제작하면 된다.

```c++
(리턴 타입) operator(연산자) (연산자가 받는 인자)
```

> 참고로 위 방법 외에는 함수 이름으로 연산자를 절대 넣을 수 없다.

예를 들어서 `==` 을 오버로딩하고 싶다면, `==` 연산자는 그 결과값이 언제나 `bool` 이고, 인자로는 `==` 로 비교하는 것 하나만 받게 된다.
따라서 다음과 같이 함수를 정의하면 된다.

```c++
bool operator==(MyString& str);
```

이제 우리가 `str1 == str2` 라는 명령을 한다면 이는 `str1.operator==(str2)` 로 내부적으로 변환되서 처리된다.
그리고 그 결과값을 리턴한다. 이를 `compare` 함수를 이용해서 만들면 다음과 같다.

```c++
bool MyString::operator==(MyString& str) {
	return !compare(str); // str과 같으면 compare에서 0을 리턴한다.
}
```

### 복소수 (Complex number) 클래스 만들기

이번엔 복소수를 다루는 클래스를 만든다. 복소수는 실수부와 허수부가 존재하기에 두 개의 수를 가져야 한다.
따라서 기본적으로 복소수 클래스 `Complex` 는 다음고 같이 간단하게 만들 수 있다.

```c++
class Complex {
	private:
	    double real, img;
		
    public:
	    Complex(double real, double img) : real(real), img(img) {}
};
```

이때, 복소수는 실수의 사칙연산과 조금은 다르기에 클래스 차원에서 이를 구현해주어야 한다.
예를 들어 복소수의 덧셈과 곱셈, 나눗셈을 살펴보면 다음과 같다.

$$ z_1 + z_2 = (a_1 + ib_1) + (a_2 + ib_2) = (a_1 + a_2) + i(b_1 + b_2) $$

$$ z_1z_2 = (a_1 + ib_1)(a_2 + ib_2) = (a_1a_2 - b_1b_2) + i(a_1b_2 + a_2b_1) $$

$$ \frac{z_1}{z_2} = \frac{a_1 + ib_1}{a_2+ib_2} = \frac{(a_1+ib_1)(a_2-ib_2)}{{a_2^2}+{b_2^2}} = \frac{a_1a_2+b_1b_2+i(a_2b_1-a_1b_2)}{{a_2^2}+{b_2^2}} $$

만약 연산자의 오버로딩을 모른다고 가정하고 `Complex` 클래스를 구성하면 다음과 같을 것이다.

```c++
class Complex {
 private:
  double real, img;

 public:
  Complex(double real, double img) : real(real), img(img) {}

  Complex plus(const Complex& c);
  Complex minus(const Complex& c);
  Complex times(const Complex& c);
  Complex divide(const Complex& c);
};
```

이렇게 된다면 `int` 형 변수의 계산과 다르게 복소수의 계산은 다음과 같이 많이 복잡해진다.

```c++
a + b / c + d;                // int형 연산
a.plus(b.divide(c)).plus(d);  // Complex형 연산
```

이는 가독성도 안 좋고 쓰기도 복잡하다. 하지만 연산자 오버로딩을 이용한다면 int형 연산과 동일하게 적어도 컴파일러가 알아서 변환하기 때문에 속도 등 다른 면에 차이없이 가독성과 편리함을 얻을 수 있다.

이를 바탕으로 `Complex` 클래스를 만들면 다음과 같다.

```c++
#include <iostream>

class Complex {
 private:
  double real, img;

 public:
  Complex(double real, double img) : real(real), img(img) {}
  Complex(const Complex& c) { real = c.real, img = c.img; }

  Complex operator+(const Complex& c) const;
  Complex operator-(const Complex& c) const;
  Complex operator*(const Complex& c) const;
  Complex operator/(const Complex& c) const;

  void println() { std::cout << "( " << real << " , " << img << " ) " << std::endl; }
};

Complex Complex::operator+(const Complex& c) const {
  Complex temp(real + c.real, img + c.img);
  return temp;
}
Complex Complex::operator-(const Complex& c) const {
  Complex temp(real - c.real, img - c.img);
  return temp;
}
Complex Complex::operator*(const Complex& c) const {
  Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
  return temp;
}
Complex Complex::operator/(const Complex& c) const {
  Complex temp(
    (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
    (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
  return temp;
}

int main() {
  Complex a(1.0, 2.0);
  Complex b(3.0, -2.0);

  Complex c = a * b;

  c.println();
}
```

여기서 가장 자세히 보아야 할 곳이 바로 사칙연산 연산자 함수들의 리턴 타입이다.

```c++
Complex operator+(const Complex& c) const;
Complex operator-(const Complex& c) const;
Complex operator*(const Complex& c) const;
Complex operator/(const Complex& c) const;
```

위 4개의 연산자 함수들은 모두 `Complex&` 가 아닌 `Complex` 를 리턴하고 있다.
간혹가다, 아래와 같이 리턴 타입을 `Complex&` 로 잘못 생각하는 경우가 있다.

```c++
Complex& operator+(const Complex& c) {
  real += c.real;
  img += c.img;
  return *this;
}
```

물론 이렇게 설계했을 경우, `Complex` 를 리턴하는 연산자 함수처럼 값의 복사가 일어나지 않기 때문에 큰 속도 저하가 일어나지 않는다.
하지만 위와 같이 `operator+` 를 정의할 경우 다음과 같은 문장이 어떻게 처리되는지 확인해봐야 한다.

```c++
Complex a = b + c + b;
```

위 식은 `a = 2 * b + c` 와 동일하게 작동할 것으로 보인다.
하지만, 실제로 처리되는 것을 보자면 다음과 같은 과정을 거친다.

1. `(b.plus(c)).plus(b)`
2. `b.plus(c)` 로 인해 `b = b + c` 가 된다.
3. 따라서 위 값은 사실상 `(b + c) + (b + c)` 가 된다.

이렇게 레퍼런스를 사용하면 중간의 값이 바뀌어 원하는 결과가 나오지 않을 수 있다.
그래서 이러한 일을 방지하기 위해 사칙연산의 경우 반드시 값을 리턴해야 한다.

또한 함수 내부에서 읽기만 수행되고 값이 바뀌지 않는 인자들에 대해서는 `const` 키워드를 붙여주는 것이 바람직하다.
`operator+` 의 경우, `c` 의 값을 읽기만 하지 `c` 의 값에 어떠한 변화도 주지 않으므로 `const Complex&` 타입으로 인자를 받았다.

> 인자의 값이 함수 내부에서 바뀌지 않는다고 확신이 될 때, `const` 키워드를 붙여주는 것이 나중에 발생할 실수들을 줄여준다.

또한 이 버전의 `operator+` 들의 경우, 객체 내부의 값을 변경하지 않기 때문에 상수 함수로 선언하였다.

> 상수 변수와 마찬가지로 상수 함수로 선언할 수 있는 것들은 상수 함수로 선언하는 것이 좋다.

### 대입 연산자 함수

여러 연산자들을 봤지만 아직 `=` 연산자를 보지는 않았다.

```c++
Complex& operator=(const Complex& c);
```

기본적으로 대입 연산자 함수는, 기존의 사칙연산 연산자 함수와는 다르게 자기 자신을 가리키는 레퍼런스( `Complex&` )를 리턴한다.
왜냐하면 `a = b = c;` 와 같은 코드에서 `b = c;` 가 `b` 를 리턴해야 `a = b;` 가 성공적으로 수행될 수 있기 때문이다.
이때, 굳이 `Complex` 타입을 리턴하지 않고 `Complex&` 타입을 리턴하는 또다른 이유는, 대입 연산 이후에 불필요한 복사를 방지하기 위해서다.

이와 같은 사실을 바탕으로 `operator=` 함수를 완성시키면 다음과 같다.

```c++
Complex& Complex::operator=(const Complex& c)

{
  real = c.real;
  img = c.img;
  return *this;
}
```

여기서 재미난 점은 굳이 `operator=` 를 만들지 않아도 잘 작동한다.
왜냐하면 컴파일러 차원에서 디폴트 대입 연산자(default assignment operator)를 지원하기 때문인데, 이전에 디폴트 복사 생성자와 같다.

디폴트 대입 연산자 역시 디폴트 복사 연산자처럼 얕은 복사를 수행한다. 따라서 깊은 복사가 필요한 클래스의 경우 (예를 들어, 클래스 내부적으로 동적 할당되는 메모리를 관리해야 하는 포인터가 있다던지) 대입 연산자 함수를 꼭 만들어주어야 한다.

이제 아래 두 개의 상황의 차이를 명확히 인지할 수 있다.

```c++
// case 1
Some_Class a = b;

// case 2
Some_Class a;
a = b;
```

case 1의 경우, 아예 `a` 의 복사 생성자가 호출된다.
case 2의 경우, `a` 의 기본 생성자가 호출된 후, 대입 연산자 함수가 실행된다.

마찬가지 이유로 대입 사칙연산 함수들인, `+=, -=` 등을 구현할 수 있다.
`=` 과 마찬가지로 아래와 같이 `Complex&` 를 리턴하고 미리 만든 `operator+` 등을 이용해 처리하면 된다.

```c++
// class 내부에 선언
Complex& operator+=(const Complex& c);
Complex& operator-=(const Complex& c);
Complex& operator*=(const Complex& c);
Complex& operator/=(const Complex& c);

// class 외부에서 정의
Complex& Complex::operator+=(const Complex& c) {
(*this) = (*this) + c;
return *this;
}
Complex& Complex::operator-=(const Complex& c) {
(*this) = (*this) - c;
return *this;
}
Complex& Complex::operator*=(const Complex& c) {
(*this) = (*this) * c;
return *this;
}
Complex& Complex::operator/=(const Complex& c) {
(*this) = (*this) / c;
return *this;
}
```

이러한 대입 연산자는 객체 내부의 상태를 변경하기 때문에 상수 함수로 선언할 수 없다.

```c++
include <iostream>

class Complex {
 private:
  double real, img;

 public:
  Complex(double real, double img) : real(real), img(img) {}
  Complex(const Complex& c) { real = c.real, img = c.img; }

  Complex operator+(const Complex& c) const;
  Complex operator-(const Complex& c) const;
  Complex operator*(const Complex& c) const;
  Complex operator/(const Complex& c) const;

  Complex& operator+=(const Complex& c);
  Complex& operator-=(const Complex& c);
  Complex& operator*=(const Complex& c);
  Complex& operator/=(const Complex& c);

  void println() {
    std::cout << "( " << real << " , " << img << " ) " << std::endl;
  }
};

Complex Complex::operator+(const Complex& c) const {
  Complex temp(real + c.real, img + c.img);
  return temp;
}
Complex Complex::operator-(const Complex& c) const {
  Complex temp(real - c.real, img - c.img);
  return temp;
}
Complex Complex::operator*(const Complex& c) const {
  Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
  return temp;
}
Complex Complex::operator/(const Complex& c) const {
  Complex temp(
      (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
      (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
  return temp;
}
Complex& Complex::operator+=(const Complex& c) {
  (*this) = (*this) + c;
  return *this;
}
Complex& Complex::operator-=(const Complex& c) {
  (*this) = (*this) - c;
  return *this;
}
Complex& Complex::operator*=(const Complex& c) {
  (*this) = (*this) * c;
  return *this;
}
Complex& Complex::operator/=(const Complex& c) {
  (*this) = (*this) / c;
  return *this;
}
int main() {
  Complex a(1.0, 2.0);
  Complex b(3.0, -2.0);
  a += b;
  a.println();
  b.println();
}
```

전체 소스를 보면 다음과 같다.

참고로 연산자 오버로딩을 사용하게 된다면 `a += b` 와 `a = a + b` 가 같다고 보장되지 않음을 명심해야 한다.
컴파일러는 `operator+` 와 `operator=` 을 정의해놓았다고 해서 `a += b` 를 자동으로 `a = a + b` 로 바꿔주지 않는다.
반드시 `operator+=` 을 따로 만들어야지 `+=` 을 사용할 수 있다.

이는 `++` 을 `+= 1` 로 바꿔주지 않는 것과 같은 의미다.
즉, 연산자 오버로딩을 하게 된다면 내가 생각하는 모든 연산자들에 대해 개별적인 정의가 필요하다.

### 문자열로 `Complex` 수와 덧셈하기

이번에는 `operator+` 를 개량해서, 문자열로도 덧셈을 할 수 있도록 만들 것이다.

```c++
y = z + "3+i2";
```

위와 같은 코드도 성공적으로 수행되게 한다는 의미다.
여기서, 우리는 문자열로 복소수를 어떻게 표현할 지 모종의 약속이 필요한데, 여기서는 다음과 같은 꼴로 표현하도록 정의한다.

```c++
(부호) (실수부) (부호) i (허수부)
```

또한 실수부나 허수부의 값이 0이라면 굳이 안써줘도 된다. 예를 들어 "3" 이나 "-5i" 와 같이 표현할 수 있다.
참고로 우리의 실수부와 허수부는 `double` 변수이기에 소수점 아래 부분도 받을 수 있도록 만들어야 한다.
이를 바탕으로 `operator+` 함수를 만들어보자.

```c++
Complex Complex::operator+(const char* str) {
  // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
  // 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
  // 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

  int begin = 0, end = strlen(str);
  double str_img = 0.0, str_real = 0.0;

  // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
  if (pos_i == -1) {
    str_real = get_number(str, begin, end - 1);

    Complex temp(str_real, str_img);
    return (*this) + temp;
  }

  // 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
  str_real = get_number(str, begin, pos_i - 1);
  str_img = get_number(str, pos_i + 1, end - 1);

  if (pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0;

  Complex temp(str_real, str_img);
  return (*this) + temp;
}
```

일단 문자열을 덧셈의 피연산자로 사용하게 되므로, `operator+` 의 인자는 `Complex&` 가 아니라 `const char *` 가 된다.
여기선 문자열 복소수를 분석하기 위해 가장 중요한 i의 위치를 먼저 찾는다.

참고로 여기서 사용하는 `get_number` 함수는 특정 문자열에서 수 부분을 `double` 로 변환하는 함수다.
물론 C언어 표준 라이브러리인 `stdlib.h` 에서 `atof` 라는 함수가 동일한 동작을 하지만 여기선 직접 만들어 보았다.
또한 이 `get_number` 함수의 경우, 내부적으로만 사용되기에 `private` 으로 설정되었다.

```c++
// 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
str_real = get_number(str, begin, pos_i - 1);
str_img = get_number(str, pos_i + 1, end - 1);

if (pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0;
```

i를 기준으로 문자열을 살펴보면 `str_real` 은 `get_number` 함수를 이용해서 정확히 실수 값을 얻을 수 있다.
왜냐하면 문자 이후의 값들은 `get_number` 함수에 의해 알아서 무시되기 때문이다.
하지만 `str_img` 의 경우, i의 부호가 잘리기 때문에 부호 처리를 해주어야 한다.

```c++
double Complex::get_number(const char *str, int from, int to) const {
  bool minus = false;
  if (from > to) return 0;

  if (str[from] == '-') minus = true;
  if (str[from] == '-' || str[from] == '+') from++;

  double num = 0.0;
  double decimal = 1.0;

  bool integer_part = true;
  for (int i = from; i <= to; i++) {
    if (isdigit(str[i]) && integer_part) {
      num *= 10.0;
      num += (str[i] - '0');
    } else if (str[i] == '.')
      integer_part = false;
    else if (isdigit(str[i]) && !integer_part) {
      decimal /= 10.0;
      num += ((str[i] - '0') * decimal);
    } else
      break;  // 그 이외의 이상한 문자들이 올 경우
  }

  if (minus) num *= -1.0;

  return num;
}
```

여기서 주목할 점은 소수점 처리인데 정수에 경우 10을 곱하는 반면, 소수점 아래의 수는 10을 나누는 것을 확인할 수 있다.

그런데 다른 사칙연산 등, 모든 연산자들에 대해 이 기능을 지원하려면 각각의 코드를 반복적으로 적어야 한다.
이렇게 불편한 작업을 막기 위해 아예 `const char *` 로 오버로딩되는 `Complex` 생성자를 추가하는 것도 좋은 방법이다.

그렇게 되면 길고 복잡했던 `operator+ (const char * str)` 부분을 다음과 같이 간단하게 줄일 수 있기 때문디ㅏ.

```c++
Complex Complex::operator+(const char* str) const {
  Complex temp(str);
  return (*this) + temp;
}
```

그렇다면 `Complex(const char *)` 를 만들어본다면 아래와 같다.

```c++
Complex::Complex(const char* str) {
  // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
  // 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
  // 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

  int begin = 0, end = strlen(str);
  img = 0.0;
  real = 0.0;

  // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
  if (pos_i == -1) {
    real = get_number(str, begin, end - 1);
    return;
  }

  // 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
  real = get_number(str, begin, pos_i - 1);
  img = get_number(str, pos_i + 1, end - 1);

  if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
```

이를 통해 다른 연산들도 간단하게 구현할 수 있다.

```c++
#include <cstring>
#include <iostream>

class Complex {
 private:
  double real, img;

  double get_number(const char* str, int from, int to) const;

 public:
  Complex(double real, double img) : real(real), img(img) {}
  Complex(const Complex& c) { real = c.real, img = c.img; }
  Complex(const char* str);

  Complex operator+(const Complex& c) const;
  Complex operator-(const Complex& c) const;
  Complex operator*(const Complex& c) const;
  Complex operator/(const Complex& c) const;

  Complex operator+(const char* str) const;
  Complex operator-(const char* str) const;
  Complex operator*(const char* str) const;
  Complex operator/(const char* str) const;

  Complex& operator+=(const Complex& c);
  Complex& operator-=(const Complex& c);
  Complex& operator*=(const Complex& c);
  Complex& operator/=(const Complex& c);

  Complex& operator=(const Complex& c);

  void println() {
    std::cout << "( " << real << " , " << img << " ) " << std::endl;
  }
};
Complex::Complex(const char* str) {
  // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
  // 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
  // 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

  int begin = 0, end = strlen(str);
  img = 0.0;
  real = 0.0;

  // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
  if (pos_i == -1) {
    real = get_number(str, begin, end - 1);
    return;
  }

  // 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
  real = get_number(str, begin, pos_i - 1);
  img = get_number(str, pos_i + 1, end - 1);

  if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) const {
  bool minus = false;
  if (from > to) return 0;

  if (str[from] == '-') minus = true;
  if (str[from] == '-' || str[from] == '+') from++;

  double num = 0.0;
  double decimal = 1.0;

  bool integer_part = true;
  for (int i = from; i <= to; i++) {
    if (isdigit(str[i]) && integer_part) {
      num *= 10.0;
      num += (str[i] - '0');
    } else if (str[i] == '.')
      integer_part = false;
    else if (isdigit(str[i]) && !integer_part) {
      decimal /= 10.0;
      num += ((str[i] - '0') * decimal);
    } else
      break;  // 그 이외의 이상한 문자들이 올 경우
  }

  if (minus) num *= -1.0;

  return num;
}
Complex Complex::operator+(const Complex& c) const {
  Complex temp(real + c.real, img + c.img);
  return temp;
}
Complex Complex::operator-(const Complex& c) const {
  Complex temp(real - c.real, img - c.img);
  return temp;
}
Complex Complex::operator*(const Complex& c) const {
  Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
  return temp;
}
Complex Complex::operator/(const Complex& c) const {
  Complex temp(
      (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
      (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
  return temp;
}
Complex Complex::operator+(const char* str) const {
  Complex temp(str);
  return (*this) + temp;
}
Complex Complex::operator-(const char* str) const {
  Complex temp(str);
  return (*this) - temp;
}
Complex Complex::operator*(const char* str) const {
  Complex temp(str);
  return (*this) * temp;
}
Complex Complex::operator/(const char* str) const {
  Complex temp(str);
  return (*this) / temp;
}
Complex& Complex::operator+=(const Complex& c) {
  (*this) = (*this) + c;
  return *this;
}
Complex& Complex::operator-=(const Complex& c) {
  (*this) = (*this) - c;
  return *this;
}
Complex& Complex::operator*=(const Complex& c) {
  (*this) = (*this) * c;
  return *this;
}
Complex& Complex::operator/=(const Complex& c) {
  (*this) = (*this) / c;
  return *this;
}
Complex& Complex::operator=(const Complex& c) {
  real = c.real;
  img = c.img;
  return *this;
}

int main() {
  Complex a(0, 0);
  a = a + "-1.1 + i3.923";
  a.println();
  a = a - "1.2 -i1.823";
  a.println();
  a = a * "2.3+i22";
  a.println();
  a = a / "-12+i55";
  a.println();
}
```

한 가지 재밌는 것은, `Complex(const char *str)` 생성자만 남겨두고 `operator+(const char *str)` 계열들을 모두 지우고 컴파일해도 잘 동작하는 것을 확인할 수 있다.
다시 말해, `const char *str` 을 인자로 받는 `operator` 함수들을 모두 지워도 잘 동작한다는 것이다.

이는 앞서 봤던 컴파일러의 동작 때문에 가능하다. 만약 아래와 같은 코드가 있다고 하자.

```c++
a = a + "-1.1 + i3.923";
```

컴파일러는 위 코드를 아래와 같이 바꾼다.

```c++
a = a.operator("-1.1 + i3.923");
```

하지만 현재 코드에선 `operator+(cont char *str)` 이 없고 `operator+(const Complex& c)` 밖에 없기에 직접 오버로딩이 되진 않는다.
그렇지만 컴파일러는 다음 순위로 오버로딩이 될 수 있는 함수들이 있는지 확인하고 `const char *` 에서 `Complex` 를 생성할 수 있는 생성자가 있음을 확인한다.
그래서 컴파일러는 아래와 같은 동작을 통해 프로그램을 제대로 작동시킨다.

```c++
a = a.operator+(Complex("-1.1 + i3.923"));
```

여기서 한 가지 짚고 가야할 것은 만일 우리가 `operator+` 함수의 인자로 `const Complex& c` 가 아니라 `Complex& c` 를 받도록 헀다면 위와 같은 변환은 일어나지 않는다.
왜냐하면 `-1.1 + i3.923` 자체가 문자열 리터럴이므로, 이를 바탕으로 생성된 객체 역시 상수여야 하기 때문이다.
그렇기에 여러모로 함수 인자의 값이 변형되지 않는다는 확신이 든다면 무조건 `const` 인자를 받도록 하는 것이 좋다.

이렇게 문자열 역시 복소수 덧셈을 수행할 수 있도록 만들었다.

```c++
a = "-1.1 + i3.923" + a;
```

```c++
a = a + "-1.1 + i3.923";
```

위 두 코드는 동일한 동작을 하지만 예상했듯이 위 코드는 제대로 컴파일되지 않는다.
왜냐하면 `"-1.1 + i3.923" + a` 의 경우, `a.operator+("-1.1+i3.923")` 과 같은 변환이 불가하기 때문이다.
이를 해결하는 방법은 이후 챕터에서 나온다.

## 5-2 입출력, 첨자, 타입변환, 증감 연산자 오버로딩

### friend 키워드

`friend` 키워드는 클래스 내부에서 다른 클래스나 함수들을 friend로 정의할 수 있다.
`friend` 로 정의된 클래스나 함수들은 원래 클래스의 `private` 으로 정의된 변수나 함수들에 접근할 수 있다.

아래의 예시를 살펴보자.

```c++
class A {
 private:
  void private_func() {}
  int private_num;

  // B 는 A 의 친구!
  friend class B;

  // func 은 A 의 친구!
  friend void func();
};

class B {
 public:
  void b() {
    A a;

    // 비록 private 함수의 필드들이지만 친구이기 때문에 접근 가능하다.
    a.private_func();
    a.private_num = 2;
  }
};

void func() {
  A a;

  // 비록 private 함수의 필드들이지만 위와 마찬가지로 친구이기 때문에 접근
  // 가능하다.
  a.private_func();
  a.private_num = 2;
}

int main() {}

```

위의 코드는 `B` 와 `void func` 을 `A` 의 친구라고 선언하고 있다. 이렇게 친구라고 선언하게 되면, `B` 와 `func` 안에서는 `A` 의 모든 `private` 멤버 함수들과 멤버 변수들에 대한 접근 권한을 부여하게 된다.
여기서 이 친구 관계가 짝사랑과 같음을 유의해야 한다. 즉, 위의 경우 `B` 는 `A` 의 모든 `private` 들을 볼 수 있지만, `B` 안에서 `A` 를 `friend` 로 지정하지 않는 이상, `A` 는 `B` 의 `private` 개체들에 접근할 수 없다.

### 이항 연산자

지난 챕터에서 `a = "-1.1 + i3.923" + a` 가 컴파일되지 않음을 확인했다.
만약 위와 같은 코드를 사용할 수 없다면 연산자 오버로딩을 하는 명분이 사라진다.
하지만 다행스럽게도, 컴파일러는 이항 연산자(피연산자를 두 개 취하는 연산자들, `+, -, *, /, ->, = 등` )를 다음과 같은 두 개의 방식으로 해석한다.

어떤 임의의 연산자 `@` 에 대해서 `a@b` 는

> 물론 c++에서 @ 연산자는 없다.

```c++
*a.operator@(b);
*operator@(a, b);
```

컴파일러가 둘 중 가능한 방법을 택해서 처리한다. `a.operator@(b)` 에서 `operator@` 는 `a` 의 클래스의 멤버 함수로써 사용되는 것이고,
`operator@(a, b)` 에서의 `operator@` 는 클래스 외부에 정의되어 있는 일반적인 함수를 의미하게 된다.
이제 이를 처리하기 위해 함수를 정의해보자.

> 참고로 이러한 경우는 일부 연산자들에 대해서는 해당되지 않는다. 대표적으로 [] 연산자(첨자), -> 연산자(멤버 접근),
> = 연산자(대입), () 함수 호출 연산자들의 경우 멤버 함수로만 존재할 수 있다. 즉, 따로 멤버 함수가 아닌 전역 변수로 뺄 수 없다는 의미이다.
> 따라서 이들 함수를 오버로딩 할 때는 주의가 필요하다.

```c++
Complex operator+(const Complex& a, const Complex& b) {
  // ...
}
```

우리의 또 다른 `operator+` 는 두 개의 `const Complex&` 타입의 인자 `a,b` 를 받게 된다.
앞에서 이야기했듯이 컴파일러는 타입이 정확히 일치하지 않는 경우, 가장 가깝고 가능한 오버로딩 되는 함수를 찾게 되고,
우리에겐 `Complex(const char *)` 타입의 생성자가 있기에 문자열도 연산에 사용 가능하다.

허나 클래스의 멤버 변수인 `real` 과 `img` 가 `private` 이므로 이를 해결하기 위해 `friend` 키워드를 사용해야 한다.

```c++
#include <iostream>
#include <cstring>

class Complex {
 private:
  double real, img;

  double get_number(const char* str, int from, int to) const;

 public:
  Complex(double real, double img) : real(real), img(img) {}
  Complex(const Complex& c) { real = c.real, img = c.img; }
  Complex(const char* str);

  Complex operator+(const Complex& c) const;
  Complex& operator=(const Complex& c);

  // 나머지 연산자 함수들은 생략 :)

  void println() {
    std::cout << "( " << real << " , " << img << " ) " << std::endl;
  }

  // 이제 이 함수는 Complex 의 private 멤버 변수들에 접근할 수 있습니다.
  friend Complex operator+(const Complex& a, const Complex& b);
};

Complex operator+(const Complex& a, const Complex& b) {
  Complex temp(a.real + b.real, a.img + b.img);
  return temp;
}

Complex::Complex(const char* str) {
  // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
  // 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
  // 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

  int begin = 0, end = strlen(str);
  img = 0.0;
  real = 0.0;

  // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
  if (pos_i == -1) {
    real = get_number(str, begin, end - 1);
    return;
  }

  // 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
  real = get_number(str, begin, pos_i - 1);
  img = get_number(str, pos_i + 1, end - 1);

  if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) const {
  bool minus = false;
  if (from > to) return 0;

  if (str[from] == '-') minus = true;
  if (str[from] == '-' || str[from] == '+') from++;

  double num = 0.0;
  double decimal = 1.0;

  bool integer_part = true;
  for (int i = from; i <= to; i++) {
    if (isdigit(str[i]) && integer_part) {
      num *= 10.0;
      num += (str[i] - '0');
    } else if (str[i] == '.')
      integer_part = false;
    else if (isdigit(str[i]) && !integer_part) {
      decimal /= 10.0;
      num += ((str[i] - '0') * decimal);
    } else
      break;  // 그 이외의 이상한 문자들이 올 경우
  }

  if (minus) num *= -1.0;

  return num;
}

Complex Complex::operator+(const Complex& c) const {
  Complex temp(real + c.real, img + c.img);
  return temp;
}

Complex& Complex::operator=(const Complex& c) {
  real = c.real;
  img = c.img;
  return *this;
}

int main() {
  Complex a(0, 0);
  a = "-1.1 + i3.923" + a;
  a.println();
}
```

위와 같은 방법으로 만들 수 있지만 아직 모든 것이 해결된 것은 아니다.

아래와 같은 main()을 실행시키면 컴파일 오류가 발생한다.

```c++
int main() {
  Complex a(0, 0);
  a = "-1.1 + i3.923" + a;

  a = a + a;
  a.println();
}
```

이는 앞서 컴파일러가 `a + a` 를 해석하는 두 가지 방법인

```c++
a.operator+(a);
operator+(a, a);

```

가 모두 가능하기 때문에 어떤 방법을 골라야 할지 모르겠다는 오류가 생긴다.
따라서 이를 해결하기 위해서는 두 함수 중, 하나를 없애야 한다.

통상적으로 자기 자신을 리턴하지 않는 이항 연산자들, 예를 들어 `+, -, *, /` 들은 모두 외부함수로 선언하는 것이 원칙이다.
반대로 자기 자신을 리턴하는 이항 연산자들, 예를 들어 `+=, -=` 과 같은 연산자들은 모두 멤버 함수로 선언하는 것이 원칙이다.

이것에 맞춰서 코드를 수정하면 다음과 같다.

```c++
#include <cstring>
#include <iostream>

class Complex {
 private:
  double real, img;

  double get_number(const char* str, int from, int to) const;

 public:
  Complex(double real, double img) : real(real), img(img) {}
  Complex(const Complex& c) { real = c.real, img = c.img; }
  Complex(const char* str);

  Complex& operator=(const Complex& c);

  // 나머지 연산자 함수들은 생략 :)

  void println() {
    std::cout << "( " << real << " , " << img << " ) " << std::endl;
  }

  friend Complex operator+(const Complex& a, const Complex& b);
};

Complex operator+(const Complex& a, const Complex& b) {
  Complex temp(a.real + b.real, a.img + b.img);
  return temp;
}

Complex::Complex(const char* str) {
  // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
  // 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
  // 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

  int begin = 0, end = strlen(str);
  img = 0.0;
  real = 0.0;

  // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
  if (pos_i == -1) {
    real = get_number(str, begin, end - 1);
    return;
  }

  // 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
  real = get_number(str, begin, pos_i - 1);
  img = get_number(str, pos_i + 1, end - 1);

  if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) const {
  bool minus = false;
  if (from > to) return 0;

  if (str[from] == '-') minus = true;
  if (str[from] == '-' || str[from] == '+') from++;

  double num = 0.0;
  double decimal = 1.0;

  bool integer_part = true;
  for (int i = from; i <= to; i++) {
    if (isdigit(str[i]) && integer_part) {
      num *= 10.0;
      num += (str[i] - '0');
    } else if (str[i] == '.')
      integer_part = false;
    else if (isdigit(str[i]) && !integer_part) {
      decimal /= 10.0;
      num += ((str[i] - '0') * decimal);
    } else
      break;  // 그 이외의 이상한 문자들이 올 경우
  }

  if (minus) num *= -1.0;

  return num;
}

Complex& Complex::operator=(const Complex& c) {
  real = c.real;
  img = c.img;
  return *this;
}

int main() {
  Complex a(0, 0);
  a = "-1.1 + i3.923" + a;
  a = a + a;

  Complex b(1, 2);
  b = a + b;

  b.println();
}
```

### 입출력 연산자 오버로딩 하기

```c++
std::cout << a;
```

위의 코드는 사실 `std::cout.operator<<(a)` 와 동일한 명령이다.
즉, 어떤 `std::cout` 이라는 객체에 멤버 함수 `operator<<` 가 정의되어 있어서 `a` 를 호출하는 것이다.
그런데 `std::cout` 이 `int, double` 이나 문자열까지 `operator<<` 하나로 출력할 수 있는 이유는 그 많은 수의 `operator<<` 함수들이 오버로딩되어 있다는 의미다.

실제로 우리가 쓰는 `iostream` 의 헤더파일을 살펴보면(실제로는 `ostream` 에 정의되어 있다. 다만 `iostream` 이 `ostream` 을 include하고 있다.)
`ostream` 클래스에

```c++
ostream& operator<<(bool val);
ostream& operator<<(short val);
ostream& operator<<(unsigned short val);
ostream& operator<<(int val);
ostream& operator<<(unsigned int val);
ostream& operator<<(long val);
ostream& operator<<(unsigned long val);
ostream& operator<<(float val);
ostream& operator<<(double val);
ostream& operator<<(long double val);
ostream& operator<<(void* val);
```

와 같이 많이 정의되어 있는 것을 볼 수 있다. 이 덕분에 우리는 타입에 관계없이 손쉽게 출력을 사용할 수 있다.

그렇다면 `Complex` 클래스에서 `ostream` 클래스의 연산자 `operator<<` 를 자유롭게 사용할 수 있다면 어떨까.
예를 들어

```c++
Complex c;
std::cout << c;
```

를 하게 되면

```c++
Complex c;
c.println();
```

을 한 것처럼 동작하게 말이다. 당연히 `ostream` 클래스에 `operator<<` 멤버 함수를 새롭게 추가하는 것은 불가능하다.
표준 헤더파일의 내용을 수정할 수는 없다.

따라서, 우리는 `ostream` 클래스에 `Complex` 객체를 오버로딩하는 `operator<<` 연산자 함수를 추가할 수는 없다.
하지만 클래스의 연산자 함수를 추가하는 방법으로, 멤버 함수를 사용하는 것 말고도 한 가지 더 있다.
바로 `ostream` 클래스 객체와 `Complex` 객체 두 개를 인자로 받는 전역 `operator<<` 함수를 정의하는 것이다.

```c++
std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << "( " << c.real << " , " << c.img << " ) ";
  return os;
}
```

참고로 `operator<<` 에서 `ostream&` 타입을 리턴하는 이유는 `std::cout << "a의 값은 : " << a << " 이다." << std::endl;` 과 같은 문장을 처리하기 위해서다.
하지만 위 `operator<<` 의 경우 한 가지 문제가 있는데 바로 이 `operator<<` 에서 `c.real` 과 `c.img` 에 접근할 수 없다는 점이다.
왜냐하면 `real` 과 `img` 모두 `Complex` 클래스의 `private` 멤버 변수들이기 때문이다.

따라서 이를 해결하기 위해 세 가지 방법을 고려할 수 있다.

1. `real` 와 `img` 를 `public` 으로 바꾼다.
2. `Complex` 에 `print(std::ostream& os)` 와 같은 멤버 함수를 추가한 뒤, 이를 `operator<<` 에서 호출한다.
3. `operator<<` 를 `friend` 로 지정한다.

두 번째도 괜찮은 방법이지만 여기선 세 번째 방법을 사용해본다.

```c++
friend ostream& operator<<(ostream& os, const Complex& c);
```

위와 비슷한 방법으로 `Complex` 객체 `c` 에 대해서 `cin >> c;` 와 같은 작업을 할 수 있다.
다만, 이번에는 `cin` 은 `istream` 객체이고, `operator>>` 를 오버로딩해야 한다는 점이 다를 뿐이다.

```c++
#include <iostream>
#include <cstring>

class Complex {
 private:
  double real, img;

  double get_number(const char* str, int from, int to) const;

 public:
  Complex(double real, double img) : real(real), img(img) {}
  Complex(const Complex& c) { real = c.real, img = c.img; }
  Complex(const char* str);

  Complex& operator+=(const Complex& c);
  Complex& operator=(const Complex& c);

  // 나머지 연산자 함수들은 생략 :)

  friend std::ostream& operator<<(std::ostream& os, const Complex& c);
  friend Complex operator+(const Complex& a, const Complex& b);
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << "( " << c.real << " , " << c.img << " ) ";
  return os;
}

Complex operator+(const Complex& a, const Complex& b) {
  Complex temp(a.real + b.real, a.img + b.img);
  return temp;
}

Complex::Complex(const char* str) {
  // 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
  // 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
  // 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

  int begin = 0, end = strlen(str);
  img = 0.0;
  real = 0.0;

  // 먼저 가장 기준이 되는 'i' 의 위치를 찾는다.
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  // 만일 'i' 가 없다면 이 수는 실수 뿐이다.
  if (pos_i == -1) {
    real = get_number(str, begin, end - 1);
    return;
  }

  // 만일 'i' 가 있다면,  실수부와 허수부를 나누어서 처리하면 된다.
  real = get_number(str, begin, pos_i - 1);
  img = get_number(str, pos_i + 1, end - 1);

  if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
double Complex::get_number(const char* str, int from, int to) const {
  bool minus = false;
  if (from > to) return 0;

  if (str[from] == '-') minus = true;
  if (str[from] == '-' || str[from] == '+') from++;

  double num = 0.0;
  double decimal = 1.0;

  bool integer_part = true;
  for (int i = from; i <= to; i++) {
    if (isdigit(str[i]) && integer_part) {
      num *= 10.0;
      num += (str[i] - '0');
    } else if (str[i] == '.')
      integer_part = false;
    else if (isdigit(str[i]) && !integer_part) {
      decimal /= 10.0;
      num += ((str[i] - '0') * decimal);
    } else
      break;  // 그 이외의 이상한 문자들이 올 경우
  }

  if (minus) num *= -1.0;

  return num;
}

Complex& Complex::operator+=(const Complex& c) {
  (*this) = *this + c;
  return *this;
}

Complex& Complex::operator=(const Complex& c) {
  real = c.real;
  img = c.img;
  return *this;
}

int main() {
  Complex a(0, 0);
  a = "-1.1 + i3.923" + a;
  std::cout << "a 의 값은 : " << a << " 이다. " << std::endl;
}
```

> 구현 디테일을 최대한 숨기라는 원칙을 토대로 `friend` 키워드를 무분별하게 사용하는 것은 권장되지 않는다.
> `friend` 키워드는 이번 예시처럼 유용하게 사용할 수 있는 부분에서만 사용하는 것이 좋다.

### 첨자 연산자(operator[])

이번에는 배열에서 원소를 지정할 때 사용되는 첨자 연산자 `[]` 를 오버로딩하자.

> 첨자 연산자로 부르는 이유는 배열의 원소를 지정할 때 [] 안에 넣는 수를 첨자(subscript) 라고 부르기 때문이다.

`operator[]` 함수는 자명하게도 인자로 몇 번째 문자인지, `int` 형 변수를 인덱스로 받게 된다.
따라서 `operator[]` 는 다음과 같은 원형을 가진다.

```c++
char& operatorp[](const int index);
```

`index` 로 `[]` 안에 들어가는 값을 받게 된다. 그리고 `char&` 를 인자로 리턴하는 이유는

```c++
str[10] = 'c';
```

와 같은 명령을 수행하기 때문에, 그 원소의 레퍼런스를 리턴하게 되는 것이다.
실제로 `operator[]` 의 구현은 아래와 같이 매우 단순하다.

```c++
char& MyString::operator[](const int index) { return string_content[index]; }
```

위와 같이 `index` 번째의 `string_content` 를 리턴해서, `operator[]` 를 사용하는 사용자가 레퍼런스를 가질 수 있게 된다.

### int Wrapper 클래스 - 타입 변환 연산자

`Wrapper` 라는 것은 '포장지'라는 의미의 단어다. c++에서는 어떤 경우에 기본 자료형들을 객체로 다뤄야 할 때가 있다.
이럴 때, 기본 자료형들( `int, float` 등)을 클래스로 포장해서 각각의 자료형을 객체로 사용하는 것을 `Wrapper` 클래스를 이용한다는 뜻이다.

즉, `int` 자료형을 감싸는 int Wrapper 클래스 `Int` 는 다음과 같이 구성할 수 있다.

```c++
class Int
{
  int data;
  // some other data

 public:
  Int(int data) : data(data) {}
  Int(const Int& i) : data(i.data) {}
};
```

위 `Int` 클래스에 `int` 형 자료형을 보관하는 `data` 라는 변수를 정의했다.
우리는 `Int` 객체가 `int` 의 `Wrapper` 클래스의 객체인 만큼, `int` 와 정확히 똑같이 작동하도록 만들고 싶다.
다시 말해, 아래와 같은 명령을 내려도 오류 없이 잘 실행되기를 원한다.

```c++
Int x = 3;      // Wrapper 객체
int a = x + 4;  // 그냥 평범한 int 형 변수 a
```

이를 잘 수행하기 위해서, `int` 변수에 사용되는 모든 연산자 함수들을 만들어줘도 되지만 이는 너무 비효율적이다.
왜냐하면 `int wrapper` 클래스 객체끼리 하는 것은 `int` 형 변수끼리 하는 일과 정확히 동일하기에 따로 만들 필요가 없다.

그렇다면, 그냥 이 `Wrapper` 클래스의 객체를 마치 `int` 형 변수라고 컴파일러가 생각하게 할 수 없을까.
이는 타입 변환 연산자를 통해 가능하다. 만일 컴파일러가 이 클래스의 객체를 `int` 형 변수로 변환할 수 있다면, 비록 `operator+` 등을 정의하지 않더라도 컴파일러가 가장 이 객체를 `int` 형 변수로 변환한 다음에 `+` 를 수행할 수 있기 때문이다.

타입 변환 연산자는 다음과 같이 정의한다.

```c++
operator (변환하고자 하는 타입) ()
```
 
예를 들어 우리의 `int Wrapper` 클래스의 경우, 다음과 같은 타입 변환 연산자를 정의할 수 있다.

```c++
operator int()
```

이때, 주의할 점은 생성자처럼 함수의 리턴 타입을 써주면 안 된다.이는 c++에서 변환 연산자를 정의하기 위한 규칙이라 볼 수 있다.
그렇기에 우리는 `int` 변환 연산자를 다음과 같이 간단하게 구성할 수 있다.

```c++
operator int() { return data; }
```

이렇게 된다면 `Wrapper` 클래스의 객체를 읽는 데에는 아무런 문제가 없다. 왜냐하면 컴파일러 입장에서 적절한 변환 연산자로 `operator int` 를 찾아서 `int` 로 변환해서 처리하기 때문이다.
대입에서도 다행이 디폴트 대입 연산자가 알아서 처리한다.

```c++
#include <iostream>

class Int {
  int data;
  // some other data

 public:
  Int(int data) : data(data) {}
  Int(const Int& i) : data(i.data) {}

  operator int() { return data; }
};
int main() {
  Int x = 3;
  int a = x + 4;

  x = a * 2 + x + 4;
  std::cout << x << std::endl;
}
```

위 코드를 실행해보면 `Int` 객체가 `int` 변수와 동일하게 동작함을 확인할 수 있다.

### 전위/후위 증감 연산자

마지막으로 살펴볼 연산자는 `++, --` 이다. 

먼저 c++에서는 전위 연산자와 후위 연산자를 구별하기 위해서 오버로딩을 다음과 같이 진행한다.

```c++
operator++();      // ++x;
operator--();      // --x;
operator++(int x); // x++;
operator--(int x); // x--;
```

사실 인자 `x` 는 아무 의미가 없다. 단지 전위인지 후위인지 구별하기 위해서 사용될 뿐이다.

한 가지 중요한 점은, 전위 증감 연산의 경우 **값이 바뀐 자신** 을 리턴해야 하고, 후위 증감 연산의 경우 **값이 바뀌기 이전의 객체** 를 리턴해야 한다.

아래의 예시는 전위/후위 연산자의 차이를 보여준다.

```c++
int x = 1;
func(++x); // func(2)와 동일

int x = 1;
func(x++); // func(1)을 실행하고 x에 1을 더함
```

따라서 이를 감안하면 아래와 같은 꼴이 나온다.

```c++
A& operator++() {
  // A ++ 을 수행한다.
  return *this;
}

A operator++(int) {
  A temp(A);
  // A++ 을 수행한다.
  return temp;
}
```

전위 연산자는 간단히 `++` 에 해당하는 연산을 수행한 후에 자기 자신을 반환한다.
하지만 후위 연산자는 `++` 를 하기 전에 객체를 반환해야 하므로, `temp` 객체를 만들어서 이전 상태를 기록한 후에, 
`++` 를 수행하고 `temp` 객체를 반환한다.

따라서 후위 증감 연산의 경우 추가적으로 복사 생성자를 호출하기 때문에 전위 증감 연산자보다 느리다.

### 정리

연산자 오버로딩에 대해 다루면서 몇 가지 중요한 포인트만 따로 정리하면 다음과 같다.

- 두 개의 동등한 객체 사이에서 이항 연산자는 멤버 함수가 아닌 외부 함수로 오버로딩하는 것이 좋다.
  - 예를 들어 `Complex` 의 `operator+(const Complex&, const Complex&) cont` 와 같이 말이다.
- 두 개의 객체 사이의 이항 연산자이지만 한 객체만 값이 바뀌는 등 동등하지 않은 이항 연산자는 멤버 함수로 오버로딩하는 것이 좋다.
  - 예를 들어 `operator+=` 는 이항 연산자이지만 `operator+=(const Complex&)` 가 낫다.
- 단항 연산자는 멤버 함수로 오버로딩하는 것이 좋다.
  - 예를 들어 `operator++` 의 경우 멤버 함수로 오버로딩한다.
- 일부 연산자들을 반드시 멤버 함수로만 오버로딩해야 한다.

## 5-3 연산자 오버로딩 프로젝트 - N차원 배열

### c++ 스타일의 캐스팅



### N차원 배열 만들기(추후 진행)
