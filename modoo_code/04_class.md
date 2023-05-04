# 4. Class

## 4-1 이 세상은 객체로 이루어져 있다.

### 객체란?

> 객체란, 변수들과 참고 자료들로 이루어진 소프트웨어 덩어리이다.

이 때 객체가 현실 세계에서 존재하는 것들을 나타내기 위해선 **추상화(abstraction)** 라는 과정이 필요하다.
예를 들어, 핸드폰의 경우 '전화를 한다', '문자를 보낸다' 등의 작업을 '핸드폰이 하는 것'이므로 함수를 추상화시킬 수 있다.
또한 핸드폰의 상태를 나타내는 것들도 추상화시킬 수 있다.

이와 같이 어떠한 객체는 자기 만의 정보를 나타내는 변수들과, 이 변수들을 가지고 어떠한 작업을 하는 함수들로 둘러싼 것이라고 볼 수 있다.
참고로, 이러한 객체의 변수와 함수들은 보통 **인스턴스 변수(instance variable)** 와 **인스턴스 메소드(instance method)** 라고 부른다.

이렇게 변수들을 메소드들이 둘러싼 것으로 표현한 이유는 외부에서 어떠한 객체의 인스턴스 변수의 값을 바꾸지 못하고 오직, 객체의 인스턴스 함수를 통해서만 바꿀 수 있기 때문이다.
이렇게 외부에서 직접 인스턴스 변수의 값을 바꿀 수 없고 항상 인스턴스 메소드를 통해서 간접적으로 조절하는 것을 **캡슐화(Encapsulation)** 라고 부른다.

캡슐화의 장점은 간단하게 "객체가 내부적으로 어떻게 작동하는지 몰라도 사용할 줄 알게 된다." 에 있다.
만약 동물이라는 객체의 음식을 100 늘린다면 단순히 음식만 늘어나는 것이 아니라 몸무게, 행복도 등이 연관되어 변경된다.
이때, 이러한 매커니즘을 몰라도 사용이 가능한 것이다.

### 클래스

클래스는 쉽게 이야기하면 객체의 설계도라고 할 수 있다. 이런식으로 클래스를 이용해서 만들어진 객체를 인스턴스(instance)라고 부른다.

```c++
#include <iostream>

class Animal {
 private:
  int food;
  int weight;

 public:
  void set_animal(int _food, int _weight) {
    food = _food;
    weight = _weight;
  }
  void increase_food(int inc) {
    food += inc;
    weight += (inc / 3);
  }
  void view_stat() {
    std::cout << "이 동물의 food   : " << food << std::endl;
    std::cout << "이 동물의 weight : " << weight << std::endl;
  }
};  // 세미콜론 잊지 말자!

int main() {
  Animal animal;
  animal.set_animal(100, 50);
  animal.increase_food(30);

  animal.view_stat();
  return 0;
}
```

`Animal` 이라는 클래스는 클래스를 통해 만들어질 임의의 객체 설계도라고 볼 수 있다.
이때, `Animal` 안에는 `food` , `weight` 이라는 변수와 `set_animal` , `increase_food` , `view_stat` 이라는 함수들이 있다.
이들을 각각 멤버 변수(member variable)와 멤버 함수(member function)라고 부른다.

인스턴스로 생성된 객체에서는 인스턴스 변수, 인스턴스 함수, 클래스에선 멤버 변수, 멤버 함수라고 호칭하는 것이다.
멤버 변수와 멤버 함수는 실재하진 않는다.

```c++
private:
    int food;
    int weight;
```

먼저 멤버 변수들을 정의한 곳을 보면 접근지시자라고 하는 키워드가 있다.
이 키워드는 외부에서 멤버들에 접근할 수 있는지 없는지를 나타낸다.

위에선 `private` 키워드가 사용되었으며 이는 객체 내에서 보호되고 있는 변수임을 의미한다.
이는 객체 내부에서만 사용이 가능하고 객체 외부에선 접근이 불가한 것을 나타낸다.

이와 반대로 객체 외부에서 접근 가능한 변수들은 `public` 이란 키워드로 나타낸다.

만약 키워드를 설정하지 않았다면 `private` 으로 설정된다.

## 4-2 클래스의 세계로 오신 것을 환영합니다. (함수의 오버로딩, 생성자)

### 함수의 오버로딩(Overloading)

오버로딩은 '과부화가 걸리게 하다' 라는 의미이다. 이는 C++에선 같은 이름을 가진 함수가 여러 개 존재할 수 있음을 의미힌다.
그리고 함수들은 받는 인자들을 통해 구분한다.

```c++
/* 함수의 오버로딩 */
#include <iostream>

void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "char : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

int main() {
  int a = 1;
  char b = 'c';
  double c = 3.2f;

  print(a);
  print(b);
  print(c);

  return 0;
}
```

c++은 인자가 다르며 같은 동작을 하는 여러 개의 동명 함수들을 만들 수 있으며 알아서 적합한 인자들을 찾아간다.

만약 정확히 일치하는 인자를 가진 함수가 없다면 '자신과 가장 근접한 함수'를 찾게 된다.

상세한 과정은 다음과 같다.

1. 자신과 타입이 정확히 일치하는 함수를 찾는다.
2. 정확히 일치하는 타입이 없을 때, 아래와 같은 형변환을 통해서 일치하는 함수를 찾아본다.
    - `char`, `unsigned char`, `short`는 `int`로 변환된다.
    - `unsigned short`는 `int`의 크기에 따라 `int`나 `unsigned int`로 변환된다.
    - `float`은 `double`로 변환된다.
    - `enum`은 `int`로 변환된다.
3. 2번의 변환도 불가하면 좀 더 포괄적인 형변환을 통해 함수를 찾아본다.
    - 임의의 숫자 타입은 다른 숫자 타입으로 변환된다.
    - `enum`도 임이의 숫자 타입으로 변환된다.
    - `0`은 포인터 타입이나 숫자타입으로 변환된다.
    - 포인터는 `void` 포인터로 변환된다.
4. 유저 정의된 타입 변환으로 일치하는 것을 찾는다.
5. 이 모든 단계에서 실패하면 모호하다(ambiguous)는 이유로 오류를 발생한다.

```c++
// 모호한 오버로딩
#include <iostream>

void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "double : " << x << std::endl; }

int main() {
  int a = 1;
  char b = 'c';
  double c = 3.2f;

  print(a);
  print(b);
  print(c);

  return 0;
}
```

만약 위와 같은 코드가 있다면 `c`는 3단계에 의해서 `char`나 `int`가 될 수 있다.
그렇기에 어떤 `print` 함수를 사용해야 할지 몰라서 오류를 발생한다.

```c++
#include<iostream>

class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void SetDate(int year, int month, int date);
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);

  // 해당 월의 총 일 수를 구한다.
  int GetCurrentMonthTotalDays(int year, int month);

  void ShowDate();
};

void Date::SetDate(int year, int month, int day) {
  year_ = year;
  month_ = month;
  day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month) {
  static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month != 2) {
    return month_day[month - 1];
  } else if (year % 4 == 0 && year % 100 != 0) {
    return 29;  // 윤년
  } else {
    return 28;
  }
}

void Date::AddDay(int inc) {
  while (true) {
    // 현재 달의 총 일 수
    int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

    // 같은 달 안에 들어온다면;
    if (day_ + inc <= current_month_total_days) {
      day_ += inc;
      return;
    } else {
      // 다음달로 넘어가야 한다.
      inc -= (current_month_total_days - day_ + 1);
      day_ = 1;
      AddMonth(1);
    }
  }
}

void Date::AddMonth(int inc) {
  AddYear((inc + month_ - 1) / 12);
  month_ = month_ + inc % 12;
  month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}

int main() {
  Date day;
  day.SetDate(2011, 3, 1);
  day.ShowDate();

  day.AddDay(30);
  day.ShowDate();

  day.AddDay(2000);
  day.ShowDate();

  day.SetDate(2012, 1, 31);  // 윤년
  day.AddDay(29);
  day.ShowDate();

  day.SetDate(2012, 8, 4);
  day.AddDay(2500);
  day.ShowDate();
  return 0;
}
```

위 코드를 보면 클래스 내부에 함수의 정의만 나와 있고, 함수의 몸통은 class밖에 있다.

여기서 밖에 정의된 함수를 보면 `Data::ShowDate()` 식으로 namespace가 선언된 것을 볼 수 있는데
`Data` 클래스 내부에 선언된 함수임을 알려준다.
보통은 클래스 내부엔 함수를 선언만 하고 클래스 외부에서 함수를 정의하는데 이는 클래스의 가독성을 높이기 위함이다.

그리고 `SetDate` 함수가 클래스 값들을 초기화해줌을 알 수 있는데 초기화를 해주지 않으면 이상한 값이 나온다.
그래서 이러한 상황을 방지하기 위해 생성자(constructor)라는 장치가 존재한다.

### 생성자(Constructor)

```c++
#include <iostream>

class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void SetDate(int year, int month, int date);
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);

  // 해당 월의 총 일 수를 구한다.
  int GetCurrentMonthTotalDays(int year, int month);

  void ShowDate();

  Date(int year, int month, int day) {
    year_ = year;
    month_ = month;
    day_ = day;
  }
};

// 생략

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}
int main() {
  Date day(2011, 3, 1);
  day.ShowDate();

  day.AddYear(10);
  day.ShowDate();

  return 0;
}
```

생성자는 기본적으로 "객체 생성 시, 자동으로 호출되는 함수"라고 볼 수 있다.
이때 자동으로 호출되면서 객체를 초기화해주는 역할을 담당한다.

생성자의 정의는 다음과 같다.

```c++
// 객체를 초기화하는 역할을 하기 때문에 리턴값은 없다.
/* 클래스 이름 */ (/* 인자 */) {}
```

위 코드에서는 아래와 같이 `Date` 의 생성자를 정의했다.

```c++
Date(int year, int month, int day)
```

이렇게 정의된 생성자는 객체를 생성할 때, 인자를 받아 생성자를 호출하여 객체를 생성한다.

선언하는 방법은 암시적 방법(implicit)과 명시적 방법(explicit)이 있는데 축약할 수 있는 암시적 방법을 더 선호하는 듯 하다.

```c++
Date day(2011, 3, 1);        // 암시적 방법(implicit)
Date day = Date(2021, 3, 1); // 명시적 방법(explicit)
```

### Default constructor

만약 처음처럼 생성자를 정의하지 않고 `Date day;` 라고 선언해도 생성자는 호출된다.
이때, 호출되는 생성자가 바로 디폴트 생성자인데, 디폴트 생성자는 인자를 하나도 가지지 않는 생성자로 클래스에서 사용자가 어떠한 생성자도 명시적으로 정의하지 않았을 경우 컴파일러가 자동으로 추가해주는 생성자이다.

> 사용자가 생성자를 추가한 순간 컴파일러는 자동으로 디폴트 생성자를 삽입하지 않음

또한 아래와 같이 사용자가 직접 디폴트 생성자를 정의할 수 있다.

```c++
// 디폴트 생성자 정의해보기
#include <iostream>

class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void ShowDate();

  Date() {
    year_ = 2012;
    month_ = 7;
    day_ = 12;
  }
};

void Date::ShowDate() {
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}

int main() {
  Date day = Date();
  Date day2;

  day.ShowDate();
  day2.ShowDate();

  return 0;
}
```

이를 정의하는 것은 앞서 보았던 두 개의 방법을 사용할 수 있다.

```c++
Date day = Date();
Date day2;
```

허나 이때

```c++
Date day3();
```

로 선언하면 안 된다. 이는 리턴값이 `Date` 이고 인자가 없는 함수 `day3` 을 정의한 것으로 인식하기 때문이다.

C++11 이전에는 디폴트 생성자를 사용하고 싶을 경우 생성자를 정의하지 않는 방법밖에 없었다.
이는 사용자 입장에서 개발자가 생성자의 정의를 잊었는지, 일부러 생성하지 않았는지 혼란을 일으켰다.

그래서 C++11에서는 명시적으로 디폴트 생성자를 사용하도록 명시할 수 있게 되었다.

```c++
class Test {
	public:
	    Test() = default; // 디폴트 생성자를 정의해라
};
```

### 생성자 오버로딩

생성자 역시 함수이기에 오버로딩이 가능하다. 이는 곧 해당 클래스의 객체를 여러가지 방식으로 생성할 수 있다는 의미다.

```c++
#include <iostream>

class Date {
  int year_;
  int month_;  // 1 부터 12 까지.
  int day_;    // 1 부터 31 까지.

 public:
  void ShowDate();

  Date() {
    std::cout << "기본 생성자 호출!" << std::endl;
    year_ = 2012;
    month_ = 7;
    day_ = 12;
  }

  Date(int year, int month, int day) {
    std::cout << "인자 3 개인 생성자 호출!" << std::endl;
    year_ = year;
    month_ = month;
    day_ = day;
  }
};

void Date::ShowDate() {
  std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_
            << " 일 입니다 " << std::endl;
}
int main() {
  Date day = Date();
  Date day2(2012, 10, 31);

  day.ShowDate();
  day2.ShowDate();

  return 0;
}
```

들어온 인자에 따라서 그에 알맞는 생성자를 호출하게 된다.

## 4-3 스타크래프트를 만들자(1) - 복사 생성자, 소멸자

스타크래프트의 기본 유닛 중 하나인 마린을 코드상에서 구현한다면 다음과 같이 구현할 수 있다.

```c++
#include <iostream>

class Marine {
  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  int damage;            // 공격력
  bool is_dead;

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성

  int attack();                       // 데미지를 리턴한다.
  void be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
};
Marine::Marine() {
  hp = 50;
  coord_x = coord_y = 0;
  damage = 5;
  is_dead = false;
}
Marine::Marine(int x, int y) {
  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
}
void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() {
  Marine marine1(2, 3);
  Marine marine2(3, 5);

  marine1.show_status();
  marine2.show_status();

  std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}
```

먼저 마린을 구현한 클래스를 살펴보면 다음과 같다.

```c++
class Marine {
  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  int damage;            // 공격력
  bool is_dead;

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성

  int attack();                       // 데미지를 리턴한다.
  void be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
};
```

살펴보면 체력, 위치, 공격력, 죽음 여부는 private으로 클래스 내부에서 관리하고 공격, 이동 등은 public으로 클래스 외부에서 사용 가능하도록 만들었다.

그리고 공격을 할 때, 누가 누구를 공격하는지 출력하는 함수들만 정의되어 있다.

만약 생성된 마린이 너무나 많으면 클래스들의 배열을 정의하여 편하게 코드를 작성할 수 있다.

```c++
/* int main 전 까지 내용은 동일 */
int main() {
  Marine* marines[100];

  marines[0] = new Marine(2, 3);
  marines[1] = new Marine(3, 5);

  marines[0]->show_status();
  marines[1]->show_status();

  std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;

  marines[0]->be_attacked(marines[1]->attack());

  marines[0]->show_status();
  marines[1]->show_status();

  delete marines[0];
  delete marines[1];
}
```

이때, `new`와 `malloc`의 차이가 드러나는데 `new`는 객체를 동적으로 생성하면서 동시에 생성자도 호출해준다는 특징이 있다.

### 소멸자(Destructor)

```c++
Marine::Marine(int x, int y, const char* marine_name) {
  name = new char[strlen(marine_name) + 1];
  strcpy(name, marine_name);
  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
}
```

만약 위 코드처럼 새로운 매개변수인 이름이 생겼다면 마린이 생성될 때마다 할당을 해야한다.
허나 우리가 직접 `delete`를 하지 않는 이상 할당된 것이 자동으로 해제되지는 않는다.

그래서 C++은 객체가 생성할 때 자동으로 호출했던 생성자처럼, 객체가 소멸할 때 자동으로 호출되는 소멸자가 있다.

```c++
#include <string.h>
#include <iostream>

class Marine {
  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  int damage;            // 공격력
  bool is_dead;
  char* name;  // 마린 이름

 public:
  Marine();                                       // 기본 생성자
  Marine(int x, int y, const char* marine_name);  // 이름까지 지정
  Marine(int x, int y);  // x, y 좌표에 마린 생성
  ~Marine();

  int attack();                       // 데미지를 리턴한다.
  void be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
};
Marine::Marine() {
  hp = 50;
  coord_x = coord_y = 0;
  damage = 5;
  is_dead = false;
  name = NULL;
}
Marine::Marine(int x, int y, const char* marine_name) {
  name = new char[strlen(marine_name) + 1];
  strcpy(name, marine_name);

  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
}
Marine::Marine(int x, int y) {
  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
  name = NULL;
}
void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
  std::cout << " *** Marine : " << name << " ***" << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}
Marine::~Marine() {
  std::cout << name << " 의 소멸자 호출 ! " << std::endl;
  if (name != NULL) {
    delete[] name;
  }
}
int main() {
  Marine* marines[100];

  marines[0] = new Marine(2, 3, "Marine 2");
  marines[1] = new Marine(1, 5, "Marine 1");

  marines[0]->show_status();
  marines[1]->show_status();

  std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;

  marines[0]->be_attacked(marines[1]->attack());

  marines[0]->show_status();
  marines[1]->show_status();

  delete marines[0];
  delete marines[1];
}
```

소멸자는 위 코드와 같이 `~(클래스 이름)` 으로 선언하면 된다.
이때, 생성자와의 차이는 소멸자는 인자를 아무것도 가지지 않는다. 다시 말해 소멸자는 오버로딩이 되지 않는다.

소멸자의 코드를 살펴보면 다음과 같다.

```c++
Marine::~Marine() {
  std::cout << name << " 의 소멸자 호출 ! " << std::endl;
  if (name != NULL) {
    delete[] name;
  }
}
```

`name`이 `NULL`이 아닐 때, 삭제하는 것을 볼 수 있다. 이때, `name` 자체가 `char`의 배열로 할당되었기 때문에
`delete [] name` 으로 해제하는 것을 볼 수 있다.


```c++
// 소멸자 호출 확인하기
#include <string.h>
#include <iostream>

class Test {
  char c;

 public:
  Test(char _c) {
    c = _c;
    std::cout << "생성자 호출 " << c << std::endl;
  }
  ~Test() { std::cout << "소멸자 호출 " << c << std::endl; }
};
void simple_function() { Test b('b'); }
int main() {
  Test a('a');
  simple_function();
}
```

위 함수를 실행하면 다음과 같은 결과가 나온다.

```shell
생성자 호출 a
생성자 호출 b
소멸자 호출 b
소멸자 호출 a
```

이때, b가 먼저 소멸자를 호출한다. 왜냐하면 `Test b`는 지역변수이기 때문에 `simple_function` 함수가 끝나면서 소멸되기 때문이다.

소멸자는 기본적으로 객체가 동적으로 할당받은 메모리를 해제하는 일을 한다. 그 외에도 쓰레드 사이에서 lock 된 것을 푸는 역할 등도 수행한다.

소멸자 역시 디폴트 소멸자가 있다. 물론 디폴트 소멸자 내부에선 아무러 작업도 하지 않는다. 그렇기에 소멸자가 필요없는 클래스라면 굳이 소멸자를 쓸 필요는 없다.

### 복사 생성자

만약 동일한 객체를 여러 개 생성해야 한다면 일일히 생성자로 생성할 수도 있지만 한 개를 가지고 나머지를 복사 생성할 수도 있다.

```c++
// 포토캐논
#include <string.h>
#include <iostream>

class Photon_Cannon {
  int hp, shield;
  int coord_x, coord_y;
  int damage;

 public:
  Photon_Cannon(int x, int y);
  Photon_Cannon(const Photon_Cannon& pc);

  void show_status();
};
Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc) {
  std::cout << "복사 생성자 호출 !" << std::endl;
  hp = pc.hp;
  shield = pc.shield;
  coord_x = pc.coord_x;
  coord_y = pc.coord_y;
  damage = pc.damage;
}
Photon_Cannon::Photon_Cannon(int x, int y) {
  std::cout << "생성자 호출 !" << std::endl;
  hp = shield = 100;
  coord_x = x;
  coord_y = y;
  damage = 20;
}
void Photon_Cannon::show_status() {
  std::cout << "Photon Cannon " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}
int main() {
  Photon_Cannon pc1(3, 3);
  Photon_Cannon pc2(pc1);
  Photon_Cannon pc3 = pc2;

  pc1.show_status();
  pc2.show_status();
}
```

먼저 복사 생성자부터 살펴보면 다음과 같다.

```c++
Photon_Cannon(const Photon_Cannon& pc);
```

이는 어떤 클래스 `T`의 복사 생성자를 만들 때, `T(const T& a);`의 형식으로 만들어야 함을 보여준다.
이때, `a` 가 `const` 이므로 복사 생성자 내부에서 `a` 의 데이터를 변경할 순 없고, 오직 새롭게 초기화되는 인스턴스 변수들에게 복사만 할 수 있다.

중요한 점은 함수 내부에서 받은 인자의 값을 변화시킬 일이 없다면 꼭 `const` 를 붙여주는 것이 좋다. 이는 나중에 발생할 실수들을 효과적으로 막아준다.

복사 생성자를 사용하는 방법은 두 가지가 있다.

```c++
Photon_Cannon pc1(3, 3);
Photon_Cannon pc2(pc1);
Photon_Cannon pc3 = pc2;
```

이때, 생성 시 대입하는 연산은 자연스레 복사 생성자를 불러온다. 허나 일반적인 대입은 복사 생성자를 호출하지 않는다.

즉, 

```c++
Photon_Cannon pc3 = pc2;
```

와

```c++
Photon_Cannon pc3;
pc3 = pc2;
```

는 엄연히 다른 동작을 한다. 복사 생성자는 오직 생성시에만 호출된다는 것을 명심해야 한다.

디폴트 복사 생성자 역시 존재하는데 디폴트 생성자, 디폴트 소멸자와 다르게 실제로 복사를 해준다.
정확히는 대응되는 원소들을 말 그대로 1 대 1 대응으로 복사해준다. 그렇기에 이러한 복사는 디폴트 복사 생성자를 이용해서 쉽게 처리할 수 있다.

### 디폴트 복사 생성자의 한계

만약 Photon_Cannon 멤버 변수에 이름이 있어서 할당해야 한다고 가정하자.
그렇다면 디폴트 복사 생성자를 이용해 만들어진 복사된 객체의 이름은 원본 객체의 이름의 포인터를 갖게 된다.
즉, 하나의 이름을 두 객체가 가리키고 있는 것이다. 물론 여기까지는 문제가 생기지 않는다. 하지만 소멸자가 실행되면 나중에 소멸되는 객체에서 에러가 발생한다.

그렇기에 이렇게 할당된 것들이 멤버 변수로 있다면 복사 생성자에서 할당된 메모리도 복사되도록 정의해주어야 한다.

이렇게 새로 할당해서 내용을 복사하는 것을 깊은 복사(deep copy)라고 하고 같은 포인터를 가리키게 하는 것을 얕은 복사(shallow copy)라고 한다.

## 4-4 스타크래프트를 만들자(2) - const, static

### 생성자의 초기화 리스트(initializer list)

```c++
#include <iostream>

class Marine {
  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  int damage;            // 공격력
  bool is_dead;

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성

  int attack();                       // 데미지를 리턴한다.
  void be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
};

Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) {}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() {
  Marine marine1(2, 3);
  Marine marine2(3, 5);

  marine1.show_status();
  marine2.show_status();
}
```

위 함수가 다른 것은 생성자가 아래와 같이 바뀐 것밖에 없다.

```c++
Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}
```

위 코드의 동작은 기존 생성자의 동작과 동일하다. 이렇게 생성자 이름 뒤에 멤버 변수를 쓰는 것을 초기화 리스트(initializer list)라고 부르며, 생성자 호출과 동시에 멤버 변수들을 초기화해준다.

이렇게 초기화 리스트를 사용하는 것은 기존의 생성자와 동일한 동작을 하는 것처럼 보인다.
하지만 약간의 차이가 있는데, 초기화 리스트는 생성과 초기화를 동시에 하고 생성자를 사용하는 방법은 생성 후, 초기화를 진행한다.

이는 마치

```c++
int a = 10;
```

과

```c++
int a;
a = 10;
```

의 차이로 볼 수 있다. 그렇기에 초기화 리스트는 작업량을 조금이나마 줄여주는 효과가 있다.
또한 레퍼런스와 상수와 같이 반드시 생성과 초기화를 동시에 해야하는 것들에서도 사용할 수 있다.

그렇기에 클래스 내부에서 레퍼런스 변수나 상수를 넣고 싶다면 이들을 생성자에서 무조건 초기화 리스트를 사용해서 초기화 시켜주어야만 한다.

```c++
#include <iostream>

class Marine {
  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  bool is_dead;

  const int default_damage;  // 기본 공격력

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성

  int attack();                       // 데미지를 리턴한다.
  void be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
};
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() {
  Marine marine1(2, 3);
  Marine marine2(3, 5);

  marine1.show_status();
  marine2.show_status();

  std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}
```

위 코드를 보면 마린 클래스의 공격력이 실수로 변하는 것을 막기 위해서 상수 멤버를 도입해서 고정시킨 것을 볼 수 있다.
따라서 이를 위해 초기화 리스트를 사용한다.

이러한 처리는 다른 개발자가 실수나 무지로 마린의 공격력을 바꾸려 할 때, 오류를 발생시켜 디버깅 과정을 줄여준다.

```c++
#include <iostream>

class Marine {
  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  bool is_dead;

  const int default_damage;  // 기본 공격력

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성
  Marine(int x, int y, int default_damage);

  int attack();                       // 데미지를 리턴한다.
  void be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
};
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() {
  Marine marine1(2, 3, 10);
  Marine marine2(3, 5, 10);

  marine1.show_status();
  marine2.show_status();

  std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}
```

위와 같이 공격력을 직접 받거나 받지 않고 기본 공격력을 사용하도록 생성자를 설정할 수 있다.
여기서도 마찬가지로 한 번 설정된 공격력은 바뀌지 않도록 상수 처리한 것을 볼 수 있다.

### 생성된 총 'Marine' 수 세기(static 변수)

만약 총 생성된 마린의 개수를 구하려 한다면 배열에 보관하거나 변수로 계속해서 마린의 개수를 세주는 방법이 먼저 떠오른다.
허나 배열은 고정되어있고(vector는 우선 논외) 변수는 인자로 넘겨주거나 전역변수로 만들어야 한다.

> 하지만 전역 변수는 프로젝트의 규모가 커질수록 개발자의 실수로 겹쳐서 오류가 날 확률이 높기에 꼭 필요한 경우를 제외하곤 사용하지 않는다.

이러한 문제를 c++은 `static` 멤버 변수를 통해 해결한다.

c에서 `static` 변수가 프로그램이 종료될 때, 소멸되는 것처럼 어떤 클래스의 `static` 멤버 변수의 경우 멤버 변수들처럼 객체가 소멸될 때 소멸되는 것이 아닌, 프로그램이 종료될 때 소멸되는 것이다.
또한 이 `static` 멤버 변수의 경우, 클래스의 모든 객체들이 공유하는 변수로써 각 객체별로 따로 존재하지 않는다. 

```c++
// static 멤버 변수의 사용

#include <iostream>

class Marine {
  static int total_marine_num;

  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  bool is_dead;

  const int default_damage;  // 기본 공격력

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성
  Marine(int x, int y, int default_damage);

  int attack();                       // 데미지를 리턴한다.
  void be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.

  ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;

Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {
  total_marine_num++;
}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine() {
  Marine marine3(10, 10, 4);
  marine3.show_status();
}
int main() {
  Marine marine1(2, 3, 5);
  marine1.show_status();

  Marine marine2(3, 5, 10);
  marine2.show_status();

  create_marine();

  std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}
입력

```

위 코드에서 먼저 

```c++
static int total_marine_num;
```

과 같이 static 변수가 정의된 것을 볼 수 있다. 모든 전역 및 static 변수들은 정의와 동시에 자동으로 0으로 초기화되지만 클래스 static 변수는 아래와 같은 방법으로 초기화해야 한다.

```c++
int Marine::total_marine_num = 0;
```

이때, 클래스 내부에서 아래와 같이 

```c++
class Marine {
	static int total_marine_num = 0;
```

초기화는 되지 않는다. 이는 멤버 변수들을 같은 방법으로 초기화시키지 못하는 것과 같다.
위와 같은 초기화 방법이 가능한 것은 오직 `const static` 변수일 때만 가능하다.

객체는 생성될 때와 소멸될 때, 각각 생성자와 소멸자를 호출하기에 거기 안에 수를 세주는 동작을 추가하기만 하면 된다.

또한 `static` 함수도 만들 수 있는데 이 역시 static 변수와 마찬가지로 클래스 전체에 딱 1개 존재한다.
즉, static이 아닌 멤버 함수들이 경우, 객체를 만들어야지만 각 멤버 함수들을 호출할 수 있지만 static 함수의 경우, 객체가 없어도 클래스 자체에서 호출할 수 있다.

```c++
// static 함수
#include <iostream>

class Marine {
  static int total_marine_num;
  const static int i = 0;

  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  bool is_dead;

  const int default_damage;  // 기본 공격력

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성
  Marine(int x, int y, int default_damage);

  int attack();                       // 데미지를 리턴한다.
  void be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);            // 새로운 위치

  void show_status();  // 상태를 보여준다.
  static void show_total_marine();
  ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
  std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {
  total_marine_num++;
}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return default_damage; }
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine() {
  Marine marine3(10, 10, 4);
  Marine::show_total_marine();
}
int main() {
  Marine marine1(2, 3, 5);
  Marine::show_total_marine();

  Marine marine2(3, 5, 10);
  Marine::show_total_marine();

  create_marine();

  std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}
```

위 코드에서 보면 `show_total_marine` 함수를 호출할 때, 객체가 없이 클래스 자체로 호출하는 것을 볼 수 있다.
그렇기에 static 함수 내에선 static 변수밖에 사용할 수 없다.

### this

```c++
// 자기 자신을 가리키는 포인터 this
#include <iostream>

class Marine {
  static int total_marine_num;
  const static int i = 0;

  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  bool is_dead;

  const int default_damage;  // 기본 공격력

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성
  Marine(int x, int y, int default_damage);

  int attack();                          // 데미지를 리턴한다.
  Marine& be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);               // 새로운 위치

  void show_status();  // 상태를 보여준다.
  static void show_total_marine();
  ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
  std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x),
      coord_y(y),
      hp(50),

      default_damage(5),
      is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {
  total_marine_num++;
}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return default_damage; }
Marine& Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;

  return *this;
}
void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

int main() {
  Marine marine1(2, 3, 5);
  marine1.show_status();

  Marine marine2(3, 5, 10);
  marine2.show_status();

  std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격! " << std::endl;
  marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}
```

눈에 띄는 부분은 레퍼런스를 리턴하는 함수와 this이다.

```c++
Marine& Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;

  return *this;
}
```

일단 `this` 는 이 멤버 함수를 호출하는 객체 자신을 가리킨다. 
그렇기에 위 코드는 아래 코드와 동일한 의미가 된다.

```c++
Marine& Marine::be_attacked(int damage_earn) {
  this->hp -= damage_earn;
  if (this->hp <= 0) this->is_dead = true;

  return *this;
}
```

### 레퍼런스를 리턴하는 함수

```c++
// 레퍼런스를 리턴하는 함수
#include <iostream>

class A {
  int x;

 public:
  A(int c) : x(c) {}

  int& access_x() { return x; }
  int get_x() { return x; }
  void show_x() { std::cout << x << std::endl; }
};

int main() {
  A a(5);
  a.show_x();

  int& c = a.access_x();
  c = 4;
  a.show_x();

  int d = a.access_x();
  d = 3;
  a.show_x();

  // 아래는 오류
  // int& e = a.get_x();
  // e = 2;
  // a.show_x();

  int f = a.get_x();
  f = 1;
  a.show_x();
}
```

```c++
int& access_x() { return x; }
int get_x() { return x; }
```

먼저 위 두 개 함수를 살펴보면 `access_x` 함수는 레퍼런스를, `get_x` 함수는 값을 리턴한다.
실제로 이들이 어떻게 작동하는지 보면 다음과 같다.

```c++
int& c = a.access_x();
c = 4;
a.show_x();
```

여기서 c는 x의 레퍼런스를 받는다. 그렇기에 `c = 4` 는 곧 `x = 4` 를 의미한다.

그 밑의 코드는 다음과 같다.

```c++
int d = a.access_x();
d = 3;
a.show_x();
```

여기선 d가 int이기 때문에 x의 값을 복사하여 d에 들어간다. 그렇기에 a의 값에는 변화가 없다.

이어서 주석된 부분을 보면 다음과 같다.

```c++
int& e = a.get_x();
e = 2;
a.show_x();
```

이 코드는 오류가 발생하는데 그 이유는 레퍼런스가 아닌 타입을 리턴하는 경우엔 값의 복사가 이루어지기 때문에 임시객체(문장이 끝나면 소멸)가 생성되고, 임시객체의 레퍼런스는 가질 수 없기 때문이다.

마지막 코드를 살펴보면 int를 받아 복사되었기에 원래 값에 영향을 끼치지 못한다.

재밌는 부분은 레퍼런스를 리턴하는 함수는 그 함수 부분을 리턴하는 원래 변수로 치환해도 된다는 것이다.
아래와 같은 예시 역시 잘 동작한다.

```c++
a.access_x() = 3;
```

왜냐하면 위 코드는 결국

```c++
a.x = 3;
```

과 동일하기 때문이다. 하지만 예상했듯이 

```c++
a.get_x() = 3;
```

은 오류가 생긴다. 왜냐하면 임시객체에 값을 대입하는 상황이 벌어지기 때문이다.

다시 마린으로 돌아가서 코드를 보면 다음과 같다.

```c++
Marine& Marine::be_attacked(int damage_earn) {
  this->hp -= damage_earn;
  if (this->hp <= 0) this->is_dead = true;

  return *this;
}

```

위 경우, `be_attacked` 함수는 `Marine&` 타입을 리턴하게 되는데, 실제로는 `*this` 를 리턴하고 있다.
앞서 말했듯이 this는 지금 이 함수를 호출한 객체를 가리킨다. 따라서 *this는 객체 자신을 의미한다. 

```c++
marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());
```

따라서 위 코드는, 먼저 `marine2.be_attacked(marine1.attack())` 이 실행되고 리턴되는 것이 `marine2` 이므로 한 번더 `marine2.be_attacked(marine1.attack())` 이 실행된다고 볼 수 있다.

만약 `be_attacked` 함수가 레퍼런스를 리턴하지 않는다면 위 코드는 한 번만 실행된다.
왜냐하면 첫 공격이 끝나고 리턴되는 객체가 임시객체이기 때문이다.

### const 함수

c++에서는 변수들의 값을 바꾸지 않고 읽기만 하는 상수 함수를 멤버 함수로 선언할 수 있다.

```c++
// 상수 멤버 함수
#include <iostream>

class Marine {
  static int total_marine_num;
  const static int i = 0;

  int hp;                // 마린 체력
  int coord_x, coord_y;  // 마린 위치
  bool is_dead;

  const int default_damage;  // 기본 공격력

 public:
  Marine();              // 기본 생성자
  Marine(int x, int y);  // x, y 좌표에 마린 생성
  Marine(int x, int y, int default_damage);

  int attack() const;                    // 데미지를 리턴한다.
  Marine& be_attacked(int damage_earn);  // 입는 데미지
  void move(int x, int y);               // 새로운 위치

  void show_status();  // 상태를 보여준다.
  static void show_total_marine();
  ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
  std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
}
Marine::Marine()
    : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y)
    : coord_x(x),
      coord_y(y),
      hp(50),

      default_damage(5),
      is_dead(false) {
  total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
    : coord_x(x),
      coord_y(y),
      hp(50),
      default_damage(default_damage),
      is_dead(false) {
  total_marine_num++;
}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() const { return default_damage; }
Marine& Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;

  return *this;
}
void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
  std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

int main() {
  Marine marine1(2, 3, 5);
  marine1.show_status();

  Marine marine2(3, 5, 10);
  marine2.show_status();

  std::cout << std::endl << "마린 1 이 마린 2 를 두 번 공격! " << std::endl;
  marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}
```

위 코드는 `attack` 함수부분만 바뀌었다. 일단 상수 함수는 아래와 같은 형태로 선언한다.

```c++
int attack() const;  // 데미지를 리턴한다.
```

이는 즉, `(기존 함수의 정의) const;` 라고 선언해야 함을 의미한다.

만약 상수 멤버 함수로 정의한다면 아래와 같이 const 키워드를 이용해 정의할 수 있다.

```c++
int Marine::attack() const { return default_damage; }
```

위와 같이 상수 함수를 선언함으로써, 이 함수가 다른 변수의 값을 바꾸지 않는 함수라고 다른 개발자에게 명시시킬 수 있다.

사실 많은 경우 클래스를 설계할 때, 멤버 변수들은 모두 private에 넣고, 이 변수들의 값에 접근하는 방법으로 get_x 함수처럼 함수를 public에 넣어 사용하는 경우가 많다.
이렇게 하면 변수에 접근하는 것은 막으면서 값은 자유롭게 구할 수 있게 된다.

## 4-5 내가 만드는 String 클래스

나중에 한 번 해보기

- `assign`
- `insert`
- `erase`
- `find`
- `compare`

## 4-6 클래스의 explicit과 mutable 키워드




