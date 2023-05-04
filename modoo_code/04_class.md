# 4. Class

## 4-1 �� ������ ��ü�� �̷���� �ִ�.

### ��ü��?

> ��ü��, ������� ���� �ڷ��� �̷���� ����Ʈ���� ����̴�.

�� �� ��ü�� ���� ���迡�� �����ϴ� �͵��� ��Ÿ���� ���ؼ� **�߻�ȭ(abstraction)** ��� ������ �ʿ��ϴ�.
���� ���, �ڵ����� ��� '��ȭ�� �Ѵ�', '���ڸ� ������' ���� �۾��� '�ڵ����� �ϴ� ��'�̹Ƿ� �Լ��� �߻�ȭ��ų �� �ִ�.
���� �ڵ����� ���¸� ��Ÿ���� �͵鵵 �߻�ȭ��ų �� �ִ�.

�̿� ���� ��� ��ü�� �ڱ� ���� ������ ��Ÿ���� �������, �� �������� ������ ��� �۾��� �ϴ� �Լ���� �ѷ��� ���̶�� �� �� �ִ�.
�����, �̷��� ��ü�� ������ �Լ����� ���� **�ν��Ͻ� ����(instance variable)** �� **�ν��Ͻ� �޼ҵ�(instance method)** ��� �θ���.

�̷��� �������� �޼ҵ���� �ѷ��� ������ ǥ���� ������ �ܺο��� ��� ��ü�� �ν��Ͻ� ������ ���� �ٲ��� ���ϰ� ����, ��ü�� �ν��Ͻ� �Լ��� ���ؼ��� �ٲ� �� �ֱ� �����̴�.
�̷��� �ܺο��� ���� �ν��Ͻ� ������ ���� �ٲ� �� ���� �׻� �ν��Ͻ� �޼ҵ带 ���ؼ� ���������� �����ϴ� ���� **ĸ��ȭ(Encapsulation)** ��� �θ���.

ĸ��ȭ�� ������ �����ϰ� "��ü�� ���������� ��� �۵��ϴ��� ���� ����� �� �˰� �ȴ�." �� �ִ�.
���� �����̶�� ��ü�� ������ 100 �ø��ٸ� �ܼ��� ���ĸ� �þ�� ���� �ƴ϶� ������, �ູ�� ���� �����Ǿ� ����ȴ�.
�̶�, �̷��� ��Ŀ������ ���� ����� ������ ���̴�.

### Ŭ����

Ŭ������ ���� �̾߱��ϸ� ��ü�� ���赵��� �� �� �ִ�. �̷������� Ŭ������ �̿��ؼ� ������� ��ü�� �ν��Ͻ�(instance)��� �θ���.

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
    std::cout << "�� ������ food   : " << food << std::endl;
    std::cout << "�� ������ weight : " << weight << std::endl;
  }
};  // �����ݷ� ���� ����!

int main() {
  Animal animal;
  animal.set_animal(100, 50);
  animal.increase_food(30);

  animal.view_stat();
  return 0;
}
```

`Animal` �̶�� Ŭ������ Ŭ������ ���� ������� ������ ��ü ���赵��� �� �� �ִ�.
�̶�, `Animal` �ȿ��� `food` , `weight` �̶�� ������ `set_animal` , `increase_food` , `view_stat` �̶�� �Լ����� �ִ�.
�̵��� ���� ��� ����(member variable)�� ��� �Լ�(member function)��� �θ���.

�ν��Ͻ��� ������ ��ü������ �ν��Ͻ� ����, �ν��Ͻ� �Լ�, Ŭ�������� ��� ����, ��� �Լ���� ȣĪ�ϴ� ���̴�.
��� ������ ��� �Լ��� �������� �ʴ´�.

```c++
private:
    int food;
    int weight;
```

���� ��� �������� ������ ���� ���� ���������ڶ�� �ϴ� Ű���尡 �ִ�.
�� Ű����� �ܺο��� ����鿡 ������ �� �ִ��� �������� ��Ÿ����.

������ `private` Ű���尡 ���Ǿ����� �̴� ��ü ������ ��ȣ�ǰ� �ִ� �������� �ǹ��Ѵ�.
�̴� ��ü ���ο����� ����� �����ϰ� ��ü �ܺο��� ������ �Ұ��� ���� ��Ÿ����.

�̿� �ݴ�� ��ü �ܺο��� ���� ������ �������� `public` �̶� Ű����� ��Ÿ����.

���� Ű���带 �������� �ʾҴٸ� `private` ���� �����ȴ�.

## 4-2 Ŭ������ ����� ���� ���� ȯ���մϴ�. (�Լ��� �����ε�, ������)

### �Լ��� �����ε�(Overloading)

�����ε��� '����ȭ�� �ɸ��� �ϴ�' ��� �ǹ��̴�. �̴� C++���� ���� �̸��� ���� �Լ��� ���� �� ������ �� ������ �ǹ�����.
�׸��� �Լ����� �޴� ���ڵ��� ���� �����Ѵ�.

```c++
/* �Լ��� �����ε� */
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

c++�� ���ڰ� �ٸ��� ���� ������ �ϴ� ���� ���� ���� �Լ����� ���� �� ������ �˾Ƽ� ������ ���ڵ��� ã�ư���.

���� ��Ȯ�� ��ġ�ϴ� ���ڸ� ���� �Լ��� ���ٸ� '�ڽŰ� ���� ������ �Լ�'�� ã�� �ȴ�.

���� ������ ������ ����.

1. �ڽŰ� Ÿ���� ��Ȯ�� ��ġ�ϴ� �Լ��� ã�´�.
2. ��Ȯ�� ��ġ�ϴ� Ÿ���� ���� ��, �Ʒ��� ���� ����ȯ�� ���ؼ� ��ġ�ϴ� �Լ��� ã�ƺ���.
    - `char`, `unsigned char`, `short`�� `int`�� ��ȯ�ȴ�.
    - `unsigned short`�� `int`�� ũ�⿡ ���� `int`�� `unsigned int`�� ��ȯ�ȴ�.
    - `float`�� `double`�� ��ȯ�ȴ�.
    - `enum`�� `int`�� ��ȯ�ȴ�.
3. 2���� ��ȯ�� �Ұ��ϸ� �� �� �������� ����ȯ�� ���� �Լ��� ã�ƺ���.
    - ������ ���� Ÿ���� �ٸ� ���� Ÿ������ ��ȯ�ȴ�.
    - `enum`�� ������ ���� Ÿ������ ��ȯ�ȴ�.
    - `0`�� ������ Ÿ���̳� ����Ÿ������ ��ȯ�ȴ�.
    - �����ʹ� `void` �����ͷ� ��ȯ�ȴ�.
4. ���� ���ǵ� Ÿ�� ��ȯ���� ��ġ�ϴ� ���� ã�´�.
5. �� ��� �ܰ迡�� �����ϸ� ��ȣ�ϴ�(ambiguous)�� ������ ������ �߻��Ѵ�.

```c++
// ��ȣ�� �����ε�
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

���� ���� ���� �ڵ尡 �ִٸ� `c`�� 3�ܰ迡 ���ؼ� `char`�� `int`�� �� �� �ִ�.
�׷��⿡ � `print` �Լ��� ����ؾ� ���� ���� ������ �߻��Ѵ�.

```c++
#include<iostream>

class Date {
  int year_;
  int month_;  // 1 ���� 12 ����.
  int day_;    // 1 ���� 31 ����.

 public:
  void SetDate(int year, int month, int date);
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);

  // �ش� ���� �� �� ���� ���Ѵ�.
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
    return 29;  // ����
  } else {
    return 28;
  }
}

void Date::AddDay(int inc) {
  while (true) {
    // ���� ���� �� �� ��
    int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

    // ���� �� �ȿ� ���´ٸ�;
    if (day_ + inc <= current_month_total_days) {
      day_ += inc;
      return;
    } else {
      // �����޷� �Ѿ�� �Ѵ�.
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
  std::cout << "������ " << year_ << " �� " << month_ << " �� " << day_
            << " �� �Դϴ� " << std::endl;
}

int main() {
  Date day;
  day.SetDate(2011, 3, 1);
  day.ShowDate();

  day.AddDay(30);
  day.ShowDate();

  day.AddDay(2000);
  day.ShowDate();

  day.SetDate(2012, 1, 31);  // ����
  day.AddDay(29);
  day.ShowDate();

  day.SetDate(2012, 8, 4);
  day.AddDay(2500);
  day.ShowDate();
  return 0;
}
```

�� �ڵ带 ���� Ŭ���� ���ο� �Լ��� ���Ǹ� ���� �ְ�, �Լ��� ������ class�ۿ� �ִ�.

���⼭ �ۿ� ���ǵ� �Լ��� ���� `Data::ShowDate()` ������ namespace�� ����� ���� �� �� �ִµ�
`Data` Ŭ���� ���ο� ����� �Լ����� �˷��ش�.
������ Ŭ���� ���ο� �Լ��� ���� �ϰ� Ŭ���� �ܺο��� �Լ��� �����ϴµ� �̴� Ŭ������ �������� ���̱� �����̴�.

�׸��� `SetDate` �Լ��� Ŭ���� ������ �ʱ�ȭ������ �� �� �ִµ� �ʱ�ȭ�� ������ ������ �̻��� ���� ���´�.
�׷��� �̷��� ��Ȳ�� �����ϱ� ���� ������(constructor)��� ��ġ�� �����Ѵ�.

### ������(Constructor)

```c++
#include <iostream>

class Date {
  int year_;
  int month_;  // 1 ���� 12 ����.
  int day_;    // 1 ���� 31 ����.

 public:
  void SetDate(int year, int month, int date);
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);

  // �ش� ���� �� �� ���� ���Ѵ�.
  int GetCurrentMonthTotalDays(int year, int month);

  void ShowDate();

  Date(int year, int month, int day) {
    year_ = year;
    month_ = month;
    day_ = day;
  }
};

// ����

void Date::AddYear(int inc) { year_ += inc; }

void Date::ShowDate() {
  std::cout << "������ " << year_ << " �� " << month_ << " �� " << day_
            << " �� �Դϴ� " << std::endl;
}
int main() {
  Date day(2011, 3, 1);
  day.ShowDate();

  day.AddYear(10);
  day.ShowDate();

  return 0;
}
```

�����ڴ� �⺻������ "��ü ���� ��, �ڵ����� ȣ��Ǵ� �Լ�"��� �� �� �ִ�.
�̶� �ڵ����� ȣ��Ǹ鼭 ��ü�� �ʱ�ȭ���ִ� ������ ����Ѵ�.

�������� ���Ǵ� ������ ����.

```c++
// ��ü�� �ʱ�ȭ�ϴ� ������ �ϱ� ������ ���ϰ��� ����.
/* Ŭ���� �̸� */ (/* ���� */) {}
```

�� �ڵ忡���� �Ʒ��� ���� `Date` �� �����ڸ� �����ߴ�.

```c++
Date(int year, int month, int day)
```

�̷��� ���ǵ� �����ڴ� ��ü�� ������ ��, ���ڸ� �޾� �����ڸ� ȣ���Ͽ� ��ü�� �����Ѵ�.

�����ϴ� ����� �Ͻ��� ���(implicit)�� ����� ���(explicit)�� �ִµ� ����� �� �ִ� �Ͻ��� ����� �� ��ȣ�ϴ� �� �ϴ�.

```c++
Date day(2011, 3, 1);        // �Ͻ��� ���(implicit)
Date day = Date(2021, 3, 1); // ����� ���(explicit)
```

### Default constructor

���� ó��ó�� �����ڸ� �������� �ʰ� `Date day;` ��� �����ص� �����ڴ� ȣ��ȴ�.
�̶�, ȣ��Ǵ� �����ڰ� �ٷ� ����Ʈ �������ε�, ����Ʈ �����ڴ� ���ڸ� �ϳ��� ������ �ʴ� �����ڷ� Ŭ�������� ����ڰ� ��� �����ڵ� ��������� �������� �ʾ��� ��� �����Ϸ��� �ڵ����� �߰����ִ� �������̴�.

> ����ڰ� �����ڸ� �߰��� ���� �����Ϸ��� �ڵ����� ����Ʈ �����ڸ� �������� ����

���� �Ʒ��� ���� ����ڰ� ���� ����Ʈ �����ڸ� ������ �� �ִ�.

```c++
// ����Ʈ ������ �����غ���
#include <iostream>

class Date {
  int year_;
  int month_;  // 1 ���� 12 ����.
  int day_;    // 1 ���� 31 ����.

 public:
  void ShowDate();

  Date() {
    year_ = 2012;
    month_ = 7;
    day_ = 12;
  }
};

void Date::ShowDate() {
  std::cout << "������ " << year_ << " �� " << month_ << " �� " << day_
            << " �� �Դϴ� " << std::endl;
}

int main() {
  Date day = Date();
  Date day2;

  day.ShowDate();
  day2.ShowDate();

  return 0;
}
```

�̸� �����ϴ� ���� �ռ� ���Ҵ� �� ���� ����� ����� �� �ִ�.

```c++
Date day = Date();
Date day2;
```

�㳪 �̶�

```c++
Date day3();
```

�� �����ϸ� �� �ȴ�. �̴� ���ϰ��� `Date` �̰� ���ڰ� ���� �Լ� `day3` �� ������ ������ �ν��ϱ� �����̴�.

C++11 �������� ����Ʈ �����ڸ� ����ϰ� ���� ��� �����ڸ� �������� �ʴ� ����ۿ� ������.
�̴� ����� ���忡�� �����ڰ� �������� ���Ǹ� �ؾ�����, �Ϻη� �������� �ʾҴ��� ȥ���� �����״�.

�׷��� C++11������ ��������� ����Ʈ �����ڸ� ����ϵ��� ����� �� �ְ� �Ǿ���.

```c++
class Test {
	public:
	    Test() = default; // ����Ʈ �����ڸ� �����ض�
};
```

### ������ �����ε�

������ ���� �Լ��̱⿡ �����ε��� �����ϴ�. �̴� �� �ش� Ŭ������ ��ü�� �������� ������� ������ �� �ִٴ� �ǹ̴�.

```c++
#include <iostream>

class Date {
  int year_;
  int month_;  // 1 ���� 12 ����.
  int day_;    // 1 ���� 31 ����.

 public:
  void ShowDate();

  Date() {
    std::cout << "�⺻ ������ ȣ��!" << std::endl;
    year_ = 2012;
    month_ = 7;
    day_ = 12;
  }

  Date(int year, int month, int day) {
    std::cout << "���� 3 ���� ������ ȣ��!" << std::endl;
    year_ = year;
    month_ = month;
    day_ = day;
  }
};

void Date::ShowDate() {
  std::cout << "������ " << year_ << " �� " << month_ << " �� " << day_
            << " �� �Դϴ� " << std::endl;
}
int main() {
  Date day = Date();
  Date day2(2012, 10, 31);

  day.ShowDate();
  day2.ShowDate();

  return 0;
}
```

���� ���ڿ� ���� �׿� �˸´� �����ڸ� ȣ���ϰ� �ȴ�.

## 4-3 ��Ÿũ����Ʈ�� ������(1) - ���� ������, �Ҹ���

��Ÿũ����Ʈ�� �⺻ ���� �� �ϳ��� ������ �ڵ�󿡼� �����Ѵٸ� ������ ���� ������ �� �ִ�.

```c++
#include <iostream>

class Marine {
  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  int damage;            // ���ݷ�
  bool is_dead;

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����

  int attack();                       // �������� �����Ѵ�.
  void be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);            // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
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

  std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}
```

���� ������ ������ Ŭ������ ���캸�� ������ ����.

```c++
class Marine {
  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  int damage;            // ���ݷ�
  bool is_dead;

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����

  int attack();                       // �������� �����Ѵ�.
  void be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);            // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
};
```

���캸�� ü��, ��ġ, ���ݷ�, ���� ���δ� private���� Ŭ���� ���ο��� �����ϰ� ����, �̵� ���� public���� Ŭ���� �ܺο��� ��� �����ϵ��� �������.

�׸��� ������ �� ��, ���� ������ �����ϴ��� ����ϴ� �Լ��鸸 ���ǵǾ� �ִ�.

���� ������ ������ �ʹ��� ������ Ŭ�������� �迭�� �����Ͽ� ���ϰ� �ڵ带 �ۼ��� �� �ִ�.

```c++
/* int main �� ���� ������ ���� */
int main() {
  Marine* marines[100];

  marines[0] = new Marine(2, 3);
  marines[1] = new Marine(3, 5);

  marines[0]->show_status();
  marines[1]->show_status();

  std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;

  marines[0]->be_attacked(marines[1]->attack());

  marines[0]->show_status();
  marines[1]->show_status();

  delete marines[0];
  delete marines[1];
}
```

�̶�, `new`�� `malloc`�� ���̰� �巯���µ� `new`�� ��ü�� �������� �����ϸ鼭 ���ÿ� �����ڵ� ȣ�����شٴ� Ư¡�� �ִ�.

### �Ҹ���(Destructor)

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

���� �� �ڵ�ó�� ���ο� �Ű������� �̸��� ����ٸ� ������ ������ ������ �Ҵ��� �ؾ��Ѵ�.
�㳪 �츮�� ���� `delete`�� ���� �ʴ� �̻� �Ҵ�� ���� �ڵ����� ���������� �ʴ´�.

�׷��� C++�� ��ü�� ������ �� �ڵ����� ȣ���ߴ� ������ó��, ��ü�� �Ҹ��� �� �ڵ����� ȣ��Ǵ� �Ҹ��ڰ� �ִ�.

```c++
#include <string.h>
#include <iostream>

class Marine {
  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  int damage;            // ���ݷ�
  bool is_dead;
  char* name;  // ���� �̸�

 public:
  Marine();                                       // �⺻ ������
  Marine(int x, int y, const char* marine_name);  // �̸����� ����
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����
  ~Marine();

  int attack();                       // �������� �����Ѵ�.
  void be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);            // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
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
  std::cout << name << " �� �Ҹ��� ȣ�� ! " << std::endl;
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

  std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;

  marines[0]->be_attacked(marines[1]->attack());

  marines[0]->show_status();
  marines[1]->show_status();

  delete marines[0];
  delete marines[1];
}
```

�Ҹ��ڴ� �� �ڵ�� ���� `~(Ŭ���� �̸�)` ���� �����ϸ� �ȴ�.
�̶�, �����ڿ��� ���̴� �Ҹ��ڴ� ���ڸ� �ƹ��͵� ������ �ʴ´�. �ٽ� ���� �Ҹ��ڴ� �����ε��� ���� �ʴ´�.

�Ҹ����� �ڵ带 ���캸�� ������ ����.

```c++
Marine::~Marine() {
  std::cout << name << " �� �Ҹ��� ȣ�� ! " << std::endl;
  if (name != NULL) {
    delete[] name;
  }
}
```

`name`�� `NULL`�� �ƴ� ��, �����ϴ� ���� �� �� �ִ�. �̶�, `name` ��ü�� `char`�� �迭�� �Ҵ�Ǿ��� ������
`delete [] name` ���� �����ϴ� ���� �� �� �ִ�.


```c++
// �Ҹ��� ȣ�� Ȯ���ϱ�
#include <string.h>
#include <iostream>

class Test {
  char c;

 public:
  Test(char _c) {
    c = _c;
    std::cout << "������ ȣ�� " << c << std::endl;
  }
  ~Test() { std::cout << "�Ҹ��� ȣ�� " << c << std::endl; }
};
void simple_function() { Test b('b'); }
int main() {
  Test a('a');
  simple_function();
}
```

�� �Լ��� �����ϸ� ������ ���� ����� ���´�.

```shell
������ ȣ�� a
������ ȣ�� b
�Ҹ��� ȣ�� b
�Ҹ��� ȣ�� a
```

�̶�, b�� ���� �Ҹ��ڸ� ȣ���Ѵ�. �ֳ��ϸ� `Test b`�� ���������̱� ������ `simple_function` �Լ��� �����鼭 �Ҹ�Ǳ� �����̴�.

�Ҹ��ڴ� �⺻������ ��ü�� �������� �Ҵ���� �޸𸮸� �����ϴ� ���� �Ѵ�. �� �ܿ��� ������ ���̿��� lock �� ���� Ǫ�� ���� � �����Ѵ�.

�Ҹ��� ���� ����Ʈ �Ҹ��ڰ� �ִ�. ���� ����Ʈ �Ҹ��� ���ο��� �ƹ��� �۾��� ���� �ʴ´�. �׷��⿡ �Ҹ��ڰ� �ʿ���� Ŭ������� ���� �Ҹ��ڸ� �� �ʿ�� ����.

### ���� ������

���� ������ ��ü�� ���� �� �����ؾ� �Ѵٸ� ������ �����ڷ� ������ ���� ������ �� ���� ������ �������� ���� ������ ���� �ִ�.

```c++
// ����ĳ��
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
  std::cout << "���� ������ ȣ�� !" << std::endl;
  hp = pc.hp;
  shield = pc.shield;
  coord_x = pc.coord_x;
  coord_y = pc.coord_y;
  damage = pc.damage;
}
Photon_Cannon::Photon_Cannon(int x, int y) {
  std::cout << "������ ȣ�� !" << std::endl;
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

���� ���� �����ں��� ���캸�� ������ ����.

```c++
Photon_Cannon(const Photon_Cannon& pc);
```

�̴� � Ŭ���� `T`�� ���� �����ڸ� ���� ��, `T(const T& a);`�� �������� ������ ���� �����ش�.
�̶�, `a` �� `const` �̹Ƿ� ���� ������ ���ο��� `a` �� �����͸� ������ �� ����, ���� ���Ӱ� �ʱ�ȭ�Ǵ� �ν��Ͻ� �����鿡�� ���縸 �� �� �ִ�.

�߿��� ���� �Լ� ���ο��� ���� ������ ���� ��ȭ��ų ���� ���ٸ� �� `const` �� �ٿ��ִ� ���� ����. �̴� ���߿� �߻��� �Ǽ����� ȿ�������� �����ش�.

���� �����ڸ� ����ϴ� ����� �� ������ �ִ�.

```c++
Photon_Cannon pc1(3, 3);
Photon_Cannon pc2(pc1);
Photon_Cannon pc3 = pc2;
```

�̶�, ���� �� �����ϴ� ������ �ڿ����� ���� �����ڸ� �ҷ��´�. �㳪 �Ϲ����� ������ ���� �����ڸ� ȣ������ �ʴ´�.

��, 

```c++
Photon_Cannon pc3 = pc2;
```

��

```c++
Photon_Cannon pc3;
pc3 = pc2;
```

�� ������ �ٸ� ������ �Ѵ�. ���� �����ڴ� ���� �����ÿ��� ȣ��ȴٴ� ���� ����ؾ� �Ѵ�.

����Ʈ ���� ������ ���� �����ϴµ� ����Ʈ ������, ����Ʈ �Ҹ��ڿ� �ٸ��� ������ ���縦 ���ش�.
��Ȯ���� �����Ǵ� ���ҵ��� �� �״�� 1 �� 1 �������� �������ش�. �׷��⿡ �̷��� ����� ����Ʈ ���� �����ڸ� �̿��ؼ� ���� ó���� �� �ִ�.

### ����Ʈ ���� �������� �Ѱ�

���� Photon_Cannon ��� ������ �̸��� �־ �Ҵ��ؾ� �Ѵٰ� ��������.
�׷��ٸ� ����Ʈ ���� �����ڸ� �̿��� ������� ����� ��ü�� �̸��� ���� ��ü�� �̸��� �����͸� ���� �ȴ�.
��, �ϳ��� �̸��� �� ��ü�� ����Ű�� �ִ� ���̴�. ���� ��������� ������ ������ �ʴ´�. ������ �Ҹ��ڰ� ����Ǹ� ���߿� �Ҹ�Ǵ� ��ü���� ������ �߻��Ѵ�.

�׷��⿡ �̷��� �Ҵ�� �͵��� ��� ������ �ִٸ� ���� �����ڿ��� �Ҵ�� �޸𸮵� ����ǵ��� �������־�� �Ѵ�.

�̷��� ���� �Ҵ��ؼ� ������ �����ϴ� ���� ���� ����(deep copy)��� �ϰ� ���� �����͸� ����Ű�� �ϴ� ���� ���� ����(shallow copy)��� �Ѵ�.

## 4-4 ��Ÿũ����Ʈ�� ������(2) - const, static

### �������� �ʱ�ȭ ����Ʈ(initializer list)

```c++
#include <iostream>

class Marine {
  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  int damage;            // ���ݷ�
  bool is_dead;

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����

  int attack();                       // �������� �����Ѵ�.
  void be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);            // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
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

�� �Լ��� �ٸ� ���� �����ڰ� �Ʒ��� ���� �ٲ� �͹ۿ� ����.

```c++
Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}
```

�� �ڵ��� ������ ���� �������� ���۰� �����ϴ�. �̷��� ������ �̸� �ڿ� ��� ������ ���� ���� �ʱ�ȭ ����Ʈ(initializer list)��� �θ���, ������ ȣ��� ���ÿ� ��� �������� �ʱ�ȭ���ش�.

�̷��� �ʱ�ȭ ����Ʈ�� ����ϴ� ���� ������ �����ڿ� ������ ������ �ϴ� ��ó�� ���δ�.
������ �ణ�� ���̰� �ִµ�, �ʱ�ȭ ����Ʈ�� ������ �ʱ�ȭ�� ���ÿ� �ϰ� �����ڸ� ����ϴ� ����� ���� ��, �ʱ�ȭ�� �����Ѵ�.

�̴� ��ġ

```c++
int a = 10;
```

��

```c++
int a;
a = 10;
```

�� ���̷� �� �� �ִ�. �׷��⿡ �ʱ�ȭ ����Ʈ�� �۾����� �����̳��� �ٿ��ִ� ȿ���� �ִ�.
���� ���۷����� ����� ���� �ݵ�� ������ �ʱ�ȭ�� ���ÿ� �ؾ��ϴ� �͵鿡���� ����� �� �ִ�.

�׷��⿡ Ŭ���� ���ο��� ���۷��� ������ ����� �ְ� �ʹٸ� �̵��� �����ڿ��� ������ �ʱ�ȭ ����Ʈ�� ����ؼ� �ʱ�ȭ �����־�߸� �Ѵ�.

```c++
#include <iostream>

class Marine {
  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  bool is_dead;

  const int default_damage;  // �⺻ ���ݷ�

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����

  int attack();                       // �������� �����Ѵ�.
  void be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);            // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
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

  std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}
```

�� �ڵ带 ���� ���� Ŭ������ ���ݷ��� �Ǽ��� ���ϴ� ���� ���� ���ؼ� ��� ����� �����ؼ� ������Ų ���� �� �� �ִ�.
���� �̸� ���� �ʱ�ȭ ����Ʈ�� ����Ѵ�.

�̷��� ó���� �ٸ� �����ڰ� �Ǽ��� ������ ������ ���ݷ��� �ٲٷ� �� ��, ������ �߻����� ����� ������ �ٿ��ش�.

```c++
#include <iostream>

class Marine {
  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  bool is_dead;

  const int default_damage;  // �⺻ ���ݷ�

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����
  Marine(int x, int y, int default_damage);

  int attack();                       // �������� �����Ѵ�.
  void be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);            // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
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

  std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}
```

���� ���� ���ݷ��� ���� �ްų� ���� �ʰ� �⺻ ���ݷ��� ����ϵ��� �����ڸ� ������ �� �ִ�.
���⼭�� ���������� �� �� ������ ���ݷ��� �ٲ��� �ʵ��� ��� ó���� ���� �� �� �ִ�.

### ������ �� 'Marine' �� ����(static ����)

���� �� ������ ������ ������ ���Ϸ� �Ѵٸ� �迭�� �����ϰų� ������ ����ؼ� ������ ������ ���ִ� ����� ���� ��������.
�㳪 �迭�� �����Ǿ��ְ�(vector�� �켱 ���) ������ ���ڷ� �Ѱ��ְų� ���������� ������ �Ѵ�.

> ������ ���� ������ ������Ʈ�� �Ը� Ŀ������ �������� �Ǽ��� ���ļ� ������ �� Ȯ���� ���⿡ �� �ʿ��� ��츦 �����ϰ� ������� �ʴ´�.

�̷��� ������ c++�� `static` ��� ������ ���� �ذ��Ѵ�.

c���� `static` ������ ���α׷��� ����� ��, �Ҹ�Ǵ� ��ó�� � Ŭ������ `static` ��� ������ ��� ��� ������ó�� ��ü�� �Ҹ�� �� �Ҹ�Ǵ� ���� �ƴ�, ���α׷��� ����� �� �Ҹ�Ǵ� ���̴�.
���� �� `static` ��� ������ ���, Ŭ������ ��� ��ü���� �����ϴ� �����ν� �� ��ü���� ���� �������� �ʴ´�. 

```c++
// static ��� ������ ���

#include <iostream>

class Marine {
  static int total_marine_num;

  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  bool is_dead;

  const int default_damage;  // �⺻ ���ݷ�

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����
  Marine(int x, int y, int default_damage);

  int attack();                       // �������� �����Ѵ�.
  void be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);            // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.

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
  std::cout << " ���� �� ���� �� : " << total_marine_num << std::endl;
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

  std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}
�Է�

```

�� �ڵ忡�� ���� 

```c++
static int total_marine_num;
```

�� ���� static ������ ���ǵ� ���� �� �� �ִ�. ��� ���� �� static �������� ���ǿ� ���ÿ� �ڵ����� 0���� �ʱ�ȭ������ Ŭ���� static ������ �Ʒ��� ���� ������� �ʱ�ȭ�ؾ� �Ѵ�.

```c++
int Marine::total_marine_num = 0;
```

�̶�, Ŭ���� ���ο��� �Ʒ��� ���� 

```c++
class Marine {
	static int total_marine_num = 0;
```

�ʱ�ȭ�� ���� �ʴ´�. �̴� ��� �������� ���� ������� �ʱ�ȭ��Ű�� ���ϴ� �Ͱ� ����.
���� ���� �ʱ�ȭ ����� ������ ���� ���� `const static` ������ ���� �����ϴ�.

��ü�� ������ ���� �Ҹ�� ��, ���� �����ڿ� �Ҹ��ڸ� ȣ���ϱ⿡ �ű� �ȿ� ���� ���ִ� ������ �߰��ϱ⸸ �ϸ� �ȴ�.

���� `static` �Լ��� ���� �� �ִµ� �� ���� static ������ ���������� Ŭ���� ��ü�� �� 1�� �����Ѵ�.
��, static�� �ƴ� ��� �Լ����� ���, ��ü�� ���������� �� ��� �Լ����� ȣ���� �� ������ static �Լ��� ���, ��ü�� ��� Ŭ���� ��ü���� ȣ���� �� �ִ�.

```c++
// static �Լ�
#include <iostream>

class Marine {
  static int total_marine_num;
  const static int i = 0;

  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  bool is_dead;

  const int default_damage;  // �⺻ ���ݷ�

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����
  Marine(int x, int y, int default_damage);

  int attack();                       // �������� �����Ѵ�.
  void be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);            // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
  static void show_total_marine();
  ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
  std::cout << "��ü ���� �� : " << total_marine_num << std::endl;
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
  std::cout << " ���� �� ���� �� : " << total_marine_num << std::endl;
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

  std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
  marine2.be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}
```

�� �ڵ忡�� ���� `show_total_marine` �Լ��� ȣ���� ��, ��ü�� ���� Ŭ���� ��ü�� ȣ���ϴ� ���� �� �� �ִ�.
�׷��⿡ static �Լ� ������ static �����ۿ� ����� �� ����.

### this

```c++
// �ڱ� �ڽ��� ����Ű�� ������ this
#include <iostream>

class Marine {
  static int total_marine_num;
  const static int i = 0;

  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  bool is_dead;

  const int default_damage;  // �⺻ ���ݷ�

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����
  Marine(int x, int y, int default_damage);

  int attack();                          // �������� �����Ѵ�.
  Marine& be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);               // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
  static void show_total_marine();
  ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
  std::cout << "��ü ���� �� : " << total_marine_num << std::endl;
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
  std::cout << " ���� �� ���� �� : " << total_marine_num << std::endl;
}

int main() {
  Marine marine1(2, 3, 5);
  marine1.show_status();

  Marine marine2(3, 5, 10);
  marine2.show_status();

  std::cout << std::endl << "���� 1 �� ���� 2 �� �� �� ����! " << std::endl;
  marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}
```

���� ��� �κ��� ���۷����� �����ϴ� �Լ��� this�̴�.

```c++
Marine& Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;

  return *this;
}
```

�ϴ� `this` �� �� ��� �Լ��� ȣ���ϴ� ��ü �ڽ��� ����Ų��. 
�׷��⿡ �� �ڵ�� �Ʒ� �ڵ�� ������ �ǹ̰� �ȴ�.

```c++
Marine& Marine::be_attacked(int damage_earn) {
  this->hp -= damage_earn;
  if (this->hp <= 0) this->is_dead = true;

  return *this;
}
```

### ���۷����� �����ϴ� �Լ�

```c++
// ���۷����� �����ϴ� �Լ�
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

  // �Ʒ��� ����
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

���� �� �� �� �Լ��� ���캸�� `access_x` �Լ��� ���۷�����, `get_x` �Լ��� ���� �����Ѵ�.
������ �̵��� ��� �۵��ϴ��� ���� ������ ����.

```c++
int& c = a.access_x();
c = 4;
a.show_x();
```

���⼭ c�� x�� ���۷����� �޴´�. �׷��⿡ `c = 4` �� �� `x = 4` �� �ǹ��Ѵ�.

�� ���� �ڵ�� ������ ����.

```c++
int d = a.access_x();
d = 3;
a.show_x();
```

���⼱ d�� int�̱� ������ x�� ���� �����Ͽ� d�� ����. �׷��⿡ a�� ������ ��ȭ�� ����.

�̾ �ּ��� �κ��� ���� ������ ����.

```c++
int& e = a.get_x();
e = 2;
a.show_x();
```

�� �ڵ�� ������ �߻��ϴµ� �� ������ ���۷����� �ƴ� Ÿ���� �����ϴ� ��쿣 ���� ���簡 �̷������ ������ �ӽð�ü(������ ������ �Ҹ�)�� �����ǰ�, �ӽð�ü�� ���۷����� ���� �� ���� �����̴�.

������ �ڵ带 ���캸�� int�� �޾� ����Ǿ��⿡ ���� ���� ������ ��ġ�� ���Ѵ�.

��մ� �κ��� ���۷����� �����ϴ� �Լ��� �� �Լ� �κ��� �����ϴ� ���� ������ ġȯ�ص� �ȴٴ� ���̴�.
�Ʒ��� ���� ���� ���� �� �����Ѵ�.

```c++
a.access_x() = 3;
```

�ֳ��ϸ� �� �ڵ�� �ᱹ

```c++
a.x = 3;
```

�� �����ϱ� �����̴�. ������ �����ߵ��� 

```c++
a.get_x() = 3;
```

�� ������ �����. �ֳ��ϸ� �ӽð�ü�� ���� �����ϴ� ��Ȳ�� �������� �����̴�.

�ٽ� �������� ���ư��� �ڵ带 ���� ������ ����.

```c++
Marine& Marine::be_attacked(int damage_earn) {
  this->hp -= damage_earn;
  if (this->hp <= 0) this->is_dead = true;

  return *this;
}

```

�� ���, `be_attacked` �Լ��� `Marine&` Ÿ���� �����ϰ� �Ǵµ�, �����δ� `*this` �� �����ϰ� �ִ�.
�ռ� ���ߵ��� this�� ���� �� �Լ��� ȣ���� ��ü�� ����Ų��. ���� *this�� ��ü �ڽ��� �ǹ��Ѵ�. 

```c++
marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());
```

���� �� �ڵ��, ���� `marine2.be_attacked(marine1.attack())` �� ����ǰ� ���ϵǴ� ���� `marine2` �̹Ƿ� �� ���� `marine2.be_attacked(marine1.attack())` �� ����ȴٰ� �� �� �ִ�.

���� `be_attacked` �Լ��� ���۷����� �������� �ʴ´ٸ� �� �ڵ�� �� ���� ����ȴ�.
�ֳ��ϸ� ù ������ ������ ���ϵǴ� ��ü�� �ӽð�ü�̱� �����̴�.

### const �Լ�

c++������ �������� ���� �ٲ��� �ʰ� �б⸸ �ϴ� ��� �Լ��� ��� �Լ��� ������ �� �ִ�.

```c++
// ��� ��� �Լ�
#include <iostream>

class Marine {
  static int total_marine_num;
  const static int i = 0;

  int hp;                // ���� ü��
  int coord_x, coord_y;  // ���� ��ġ
  bool is_dead;

  const int default_damage;  // �⺻ ���ݷ�

 public:
  Marine();              // �⺻ ������
  Marine(int x, int y);  // x, y ��ǥ�� ���� ����
  Marine(int x, int y, int default_damage);

  int attack() const;                    // �������� �����Ѵ�.
  Marine& be_attacked(int damage_earn);  // �Դ� ������
  void move(int x, int y);               // ���ο� ��ġ

  void show_status();  // ���¸� �����ش�.
  static void show_total_marine();
  ~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
  std::cout << "��ü ���� �� : " << total_marine_num << std::endl;
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
  std::cout << " ���� �� ���� �� : " << total_marine_num << std::endl;
}

int main() {
  Marine marine1(2, 3, 5);
  marine1.show_status();

  Marine marine2(3, 5, 10);
  marine2.show_status();

  std::cout << std::endl << "���� 1 �� ���� 2 �� �� �� ����! " << std::endl;
  marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

  marine1.show_status();
  marine2.show_status();
}
```

�� �ڵ�� `attack` �Լ��κи� �ٲ����. �ϴ� ��� �Լ��� �Ʒ��� ���� ���·� �����Ѵ�.

```c++
int attack() const;  // �������� �����Ѵ�.
```

�̴� ��, `(���� �Լ��� ����) const;` ��� �����ؾ� ���� �ǹ��Ѵ�.

���� ��� ��� �Լ��� �����Ѵٸ� �Ʒ��� ���� const Ű���带 �̿��� ������ �� �ִ�.

```c++
int Marine::attack() const { return default_damage; }
```

���� ���� ��� �Լ��� ���������ν�, �� �Լ��� �ٸ� ������ ���� �ٲ��� �ʴ� �Լ���� �ٸ� �����ڿ��� ��ý�ų �� �ִ�.

��� ���� ��� Ŭ������ ������ ��, ��� �������� ��� private�� �ְ�, �� �������� ���� �����ϴ� ������� get_x �Լ�ó�� �Լ��� public�� �־� ����ϴ� ��찡 ����.
�̷��� �ϸ� ������ �����ϴ� ���� �����鼭 ���� �����Ӱ� ���� �� �ְ� �ȴ�.

## 4-5 ���� ����� String Ŭ����

���߿� �� �� �غ���

- `assign`
- `insert`
- `erase`
- `find`
- `compare`

## 4-6 Ŭ������ explicit�� mutable Ű����




