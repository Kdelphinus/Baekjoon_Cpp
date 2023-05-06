# 5. Overloading

## 5-1 ���� ���� ������ - ������ �����ε�

c���� `+, -, ==, []` �� ���� �⺻ �����ڵ��� �⺻������ ���ǵǾ� �ִ� ������ Ÿ��( `int, float` ��) �̿��� Ÿ�Կ��� ����ϴ� ���� �Ұ��ϴ�.
������ c++������ ����� ���� �����ڸ� ����� �� �ִ�. ��Ȯ�� `::` (���� ����), `.` (��� ����) `.*` (��� �����ͷ� ��� ����)�� ������ ��� �����ڸ� ����� �� �ִ�.

��ǥ������ ������ ����.

- `+, -, *` �� ���� ��� ����
- `+=. -=` �� ���� ����� ������
- `>=, ==` �� ���� �� ������
- `&&, ||` �� ���� �� ������
- `->` �� `*` �� ���� ��� ���� ������(���⼭ `*` �� ������ ������)
- `++, --` ���� ������
- `[]` (�迭 ������)�� ������ `()` (�Լ� ȣ�� ������)����

�̶�, �̷��� �⺻ �����ڵ��� ���� ����ڰ� �����ϴ� ���� **"�����ڸ� �����ε� �Ѵ�"** ��� �θ���.

### MyString�� '==' ������ �����ε�

�ϴ� ������ �����ε��� ����ϱ� ���ؼ���, ������ ���� �����ε��� ���ϴ� ������ �Լ��� �����ϸ� �ȴ�.

```c++
(���� Ÿ��) operator(������) (�����ڰ� �޴� ����)
```

> ����� �� ��� �ܿ��� �Լ� �̸����� �����ڸ� ���� ���� �� ����.

���� �� `==` �� �����ε��ϰ� �ʹٸ�, `==` �����ڴ� �� ������� ������ `bool` �̰�, ���ڷδ� `==` �� ���ϴ� �� �ϳ��� �ް� �ȴ�.
���� ������ ���� �Լ��� �����ϸ� �ȴ�.

```c++
bool operator==(MyString& str);
```

���� �츮�� `str1 == str2` ��� ����� �Ѵٸ� �̴� `str1.operator==(str2)` �� ���������� ��ȯ�Ǽ� ó���ȴ�.
�׸��� �� ������� �����Ѵ�. �̸� `compare` �Լ��� �̿��ؼ� ����� ������ ����.

```c++
bool MyString::operator==(MyString& str) {
	return !compare(str); // str�� ������ compare���� 0�� �����Ѵ�.
}
```

### ���Ҽ� (Complex number) Ŭ���� �����

�̹��� ���Ҽ��� �ٷ�� Ŭ������ �����. ���Ҽ��� �Ǽ��ο� ����ΰ� �����ϱ⿡ �� ���� ���� ������ �Ѵ�.
���� �⺻������ ���Ҽ� Ŭ���� `Complex` �� ������ ���� �����ϰ� ���� �� �ִ�.

```c++
class Complex {
	private:
	    double real, img;
		
    public:
	    Complex(double real, double img) : real(real), img(img) {}
};
```

�̶�, ���Ҽ��� �Ǽ��� ��Ģ����� ������ �ٸ��⿡ Ŭ���� �������� �̸� �������־�� �Ѵ�.
���� ��� ���Ҽ��� ������ ����, �������� ���캸�� ������ ����.

$$ z_1 + z_2 = (a_1 + ib_1) + (a_2 + ib_2) = (a_1 + a_2) + i(b_1 + b_2) $$

$$ z_1z_2 = (a_1 + ib_1)(a_2 + ib_2) = (a_1a_2 - b_1b_2) + i(a_1b_2 + a_2b_1) $$

$$ \frac{z_1}{z_2} = \frac{a_1 + ib_1}{a_2+ib_2} = \frac{(a_1+ib_1)(a_2-ib_2)}{{a_2^2}+{b_2^2}} = \frac{a_1a_2+b_1b_2+i(a_2b_1-a_1b_2)}{{a_2^2}+{b_2^2}} $$

���� �������� �����ε��� �𸥴ٰ� �����ϰ� `Complex` Ŭ������ �����ϸ� ������ ���� ���̴�.

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

�̷��� �ȴٸ� `int` �� ������ ���� �ٸ��� ���Ҽ��� ����� ������ ���� ���� ����������.

```c++
a + b / c + d;                // int�� ����
a.plus(b.divide(c)).plus(d);  // Complex�� ����
```

�̴� �������� �� ���� ���⵵ �����ϴ�. ������ ������ �����ε��� �̿��Ѵٸ� int�� ����� �����ϰ� ��� �����Ϸ��� �˾Ƽ� ��ȯ�ϱ� ������ �ӵ� �� �ٸ� �鿡 ���̾��� �������� ������ ���� �� �ִ�.

�̸� �������� `Complex` Ŭ������ ����� ������ ����.

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

���⼭ ���� �ڼ��� ���ƾ� �� ���� �ٷ� ��Ģ���� ������ �Լ����� ���� Ÿ���̴�.

```c++
Complex operator+(const Complex& c) const;
Complex operator-(const Complex& c) const;
Complex operator*(const Complex& c) const;
Complex operator/(const Complex& c) const;
```

�� 4���� ������ �Լ����� ��� `Complex&` �� �ƴ� `Complex` �� �����ϰ� �ִ�.
��Ȥ����, �Ʒ��� ���� ���� Ÿ���� `Complex&` �� �߸� �����ϴ� ��찡 �ִ�.

```c++
Complex& operator+(const Complex& c) {
  real += c.real;
  img += c.img;
  return *this;
}
```

���� �̷��� �������� ���, `Complex` �� �����ϴ� ������ �Լ�ó�� ���� ���簡 �Ͼ�� �ʱ� ������ ū �ӵ� ���ϰ� �Ͼ�� �ʴ´�.
������ ���� ���� `operator+` �� ������ ��� ������ ���� ������ ��� ó���Ǵ��� Ȯ���غ��� �Ѵ�.

```c++
Complex a = b + c + b;
```

�� ���� `a = 2 * b + c` �� �����ϰ� �۵��� ������ ���δ�.
������, ������ ó���Ǵ� ���� ���ڸ� ������ ���� ������ ��ģ��.

1. `(b.plus(c)).plus(b)`
2. `b.plus(c)` �� ���� `b = b + c` �� �ȴ�.
3. ���� �� ���� ��ǻ� `(b + c) + (b + c)` �� �ȴ�.

�̷��� ���۷����� ����ϸ� �߰��� ���� �ٲ�� ���ϴ� ����� ������ ���� �� �ִ�.
�׷��� �̷��� ���� �����ϱ� ���� ��Ģ������ ��� �ݵ�� ���� �����ؾ� �Ѵ�.

���� �Լ� ���ο��� �б⸸ ����ǰ� ���� �ٲ��� �ʴ� ���ڵ鿡 ���ؼ��� `const` Ű���带 �ٿ��ִ� ���� �ٶ����ϴ�.
`operator+` �� ���, `c` �� ���� �б⸸ ���� `c` �� ���� ��� ��ȭ�� ���� �����Ƿ� `const Complex&` Ÿ������ ���ڸ� �޾Ҵ�.

> ������ ���� �Լ� ���ο��� �ٲ��� �ʴ´ٰ� Ȯ���� �� ��, `const` Ű���带 �ٿ��ִ� ���� ���߿� �߻��� �Ǽ����� �ٿ��ش�.

���� �� ������ `operator+` ���� ���, ��ü ������ ���� �������� �ʱ� ������ ��� �Լ��� �����Ͽ���.

> ��� ������ ���������� ��� �Լ��� ������ �� �ִ� �͵��� ��� �Լ��� �����ϴ� ���� ����.

### ���� ������ �Լ�

���� �����ڵ��� ������ ���� `=` �����ڸ� ������ �ʾҴ�.

```c++
Complex& operator=(const Complex& c);
```

�⺻������ ���� ������ �Լ���, ������ ��Ģ���� ������ �Լ��ʹ� �ٸ��� �ڱ� �ڽ��� ����Ű�� ���۷���( `Complex&` )�� �����Ѵ�.
�ֳ��ϸ� `a = b = c;` �� ���� �ڵ忡�� `b = c;` �� `b` �� �����ؾ� `a = b;` �� ���������� ����� �� �ֱ� �����̴�.
�̶�, ���� `Complex` Ÿ���� �������� �ʰ� `Complex&` Ÿ���� �����ϴ� �Ǵٸ� ������, ���� ���� ���Ŀ� ���ʿ��� ���縦 �����ϱ� ���ؼ���.

�̿� ���� ����� �������� `operator=` �Լ��� �ϼ���Ű�� ������ ����.

```c++
Complex& Complex::operator=(const Complex& c)

{
  real = c.real;
  img = c.img;
  return *this;
}
```

���⼭ ��̳� ���� ���� `operator=` �� ������ �ʾƵ� �� �۵��Ѵ�.
�ֳ��ϸ� �����Ϸ� �������� ����Ʈ ���� ������(default assignment operator)�� �����ϱ� �����ε�, ������ ����Ʈ ���� �����ڿ� ����.

����Ʈ ���� ������ ���� ����Ʈ ���� ������ó�� ���� ���縦 �����Ѵ�. ���� ���� ���簡 �ʿ��� Ŭ������ ��� (���� ���, Ŭ���� ���������� ���� �Ҵ�Ǵ� �޸𸮸� �����ؾ� �ϴ� �����Ͱ� �ִٴ���) ���� ������ �Լ��� �� ������־�� �Ѵ�.

���� �Ʒ� �� ���� ��Ȳ�� ���̸� ��Ȯ�� ������ �� �ִ�.

```c++
// case 1
Some_Class a = b;

// case 2
Some_Class a;
a = b;
```

case 1�� ���, �ƿ� `a` �� ���� �����ڰ� ȣ��ȴ�.
case 2�� ���, `a` �� �⺻ �����ڰ� ȣ��� ��, ���� ������ �Լ��� ����ȴ�.

�������� ������ ���� ��Ģ���� �Լ�����, `+=, -=` ���� ������ �� �ִ�.
`=` �� ���������� �Ʒ��� ���� `Complex&` �� �����ϰ� �̸� ���� `operator+` ���� �̿��� ó���ϸ� �ȴ�.

```c++
// class ���ο� ����
Complex& operator+=(const Complex& c);
Complex& operator-=(const Complex& c);
Complex& operator*=(const Complex& c);
Complex& operator/=(const Complex& c);

// class �ܺο��� ����
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

�̷��� ���� �����ڴ� ��ü ������ ���¸� �����ϱ� ������ ��� �Լ��� ������ �� ����.

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

��ü �ҽ��� ���� ������ ����.

����� ������ �����ε��� ����ϰ� �ȴٸ� `a += b` �� `a = a + b` �� ���ٰ� ������� ������ ����ؾ� �Ѵ�.
�����Ϸ��� `operator+` �� `operator=` �� �����س��Ҵٰ� �ؼ� `a += b` �� �ڵ����� `a = a + b` �� �ٲ����� �ʴ´�.
�ݵ�� `operator+=` �� ���� �������� `+=` �� ����� �� �ִ�.

�̴� `++` �� `+= 1` �� �ٲ����� �ʴ� �Ͱ� ���� �ǹ̴�.
��, ������ �����ε��� �ϰ� �ȴٸ� ���� �����ϴ� ��� �����ڵ鿡 ���� �������� ���ǰ� �ʿ��ϴ�.

### ���ڿ��� `Complex` ���� �����ϱ�

�̹����� `operator+` �� �����ؼ�, ���ڿ��ε� ������ �� �� �ֵ��� ���� ���̴�.

```c++
y = z + "3+i2";
```

���� ���� �ڵ嵵 ���������� ����ǰ� �Ѵٴ� �ǹ̴�.
���⼭, �츮�� ���ڿ��� ���Ҽ��� ��� ǥ���� �� ������ ����� �ʿ��ѵ�, ���⼭�� ������ ���� �÷� ǥ���ϵ��� �����Ѵ�.

```c++
(��ȣ) (�Ǽ���) (��ȣ) i (�����)
```

���� �Ǽ��γ� ������� ���� 0�̶�� ���� �Ƚ��൵ �ȴ�. ���� ��� "3" �̳� "-5i" �� ���� ǥ���� �� �ִ�.
����� �츮�� �Ǽ��ο� ����δ� `double` �����̱⿡ �Ҽ��� �Ʒ� �κе� ���� �� �ֵ��� ������ �Ѵ�.
�̸� �������� `operator+` �Լ��� ������.

```c++
Complex Complex::operator+(const char* str) {
  // �Է� ���� ���ڿ��� �м��Ͽ� real �κа� img �κ��� ã�ƾ� �Ѵ�.
  // ���ڿ��� ���� ������ �����ϴ� "[��ȣ](�Ǽ���)(��ȣ)i(�����)"
  // �� �� �� ���� ��ȣ�� ���� �����մϴ�. (������ + �� ����)

  int begin = 0, end = strlen(str);
  double str_img = 0.0, str_real = 0.0;

  // ���� ���� ������ �Ǵ� 'i' �� ��ġ�� ã�´�.
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  // ���� 'i' �� ���ٸ� �� ���� �Ǽ� ���̴�.
  if (pos_i == -1) {
    str_real = get_number(str, begin, end - 1);

    Complex temp(str_real, str_img);
    return (*this) + temp;
  }

  // ���� 'i' �� �ִٸ�,  �Ǽ��ο� ����θ� ����� ó���ϸ� �ȴ�.
  str_real = get_number(str, begin, pos_i - 1);
  str_img = get_number(str, pos_i + 1, end - 1);

  if (pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0;

  Complex temp(str_real, str_img);
  return (*this) + temp;
}
```

�ϴ� ���ڿ��� ������ �ǿ����ڷ� ����ϰ� �ǹǷ�, `operator+` �� ���ڴ� `Complex&` �� �ƴ϶� `const char *` �� �ȴ�.
���⼱ ���ڿ� ���Ҽ��� �м��ϱ� ���� ���� �߿��� i�� ��ġ�� ���� ã�´�.

����� ���⼭ ����ϴ� `get_number` �Լ��� Ư�� ���ڿ����� �� �κ��� `double` �� ��ȯ�ϴ� �Լ���.
���� C��� ǥ�� ���̺귯���� `stdlib.h` ���� `atof` ��� �Լ��� ������ ������ ������ ���⼱ ���� ����� ���Ҵ�.
���� �� `get_number` �Լ��� ���, ���������θ� ���Ǳ⿡ `private` ���� �����Ǿ���.

```c++
// ���� 'i' �� �ִٸ�,  �Ǽ��ο� ����θ� ����� ó���ϸ� �ȴ�.
str_real = get_number(str, begin, pos_i - 1);
str_img = get_number(str, pos_i + 1, end - 1);

if (pos_i >= 1 && str[pos_i - 1] == '-') str_img *= -1.0;
```

i�� �������� ���ڿ��� ���캸�� `str_real` �� `get_number` �Լ��� �̿��ؼ� ��Ȯ�� �Ǽ� ���� ���� �� �ִ�.
�ֳ��ϸ� ���� ������ ������ `get_number` �Լ��� ���� �˾Ƽ� ���õǱ� �����̴�.
������ `str_img` �� ���, i�� ��ȣ�� �߸��� ������ ��ȣ ó���� ���־�� �Ѵ�.

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
      break;  // �� �̿��� �̻��� ���ڵ��� �� ���
  }

  if (minus) num *= -1.0;

  return num;
}
```

���⼭ �ָ��� ���� �Ҽ��� ó���ε� ������ ��� 10�� ���ϴ� �ݸ�, �Ҽ��� �Ʒ��� ���� 10�� ������ ���� Ȯ���� �� �ִ�.

�׷��� �ٸ� ��Ģ���� ��, ��� �����ڵ鿡 ���� �� ����� �����Ϸ��� ������ �ڵ带 �ݺ������� ����� �Ѵ�.
�̷��� ������ �۾��� ���� ���� �ƿ� `const char *` �� �����ε��Ǵ� `Complex` �����ڸ� �߰��ϴ� �͵� ���� ����̴�.

�׷��� �Ǹ� ��� �����ߴ� `operator+ (const char * str)` �κ��� ������ ���� �����ϰ� ���� �� �ֱ� ������.

```c++
Complex Complex::operator+(const char* str) const {
  Complex temp(str);
  return (*this) + temp;
}
```

�׷��ٸ� `Complex(const char *)` �� �����ٸ� �Ʒ��� ����.

```c++
Complex::Complex(const char* str) {
  // �Է� ���� ���ڿ��� �м��Ͽ� real �κа� img �κ��� ã�ƾ� �Ѵ�.
  // ���ڿ��� ���� ������ �����ϴ� "[��ȣ](�Ǽ���)(��ȣ)i(�����)"
  // �� �� �� ���� ��ȣ�� ���� �����մϴ�. (������ + �� ����)

  int begin = 0, end = strlen(str);
  img = 0.0;
  real = 0.0;

  // ���� ���� ������ �Ǵ� 'i' �� ��ġ�� ã�´�.
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  // ���� 'i' �� ���ٸ� �� ���� �Ǽ� ���̴�.
  if (pos_i == -1) {
    real = get_number(str, begin, end - 1);
    return;
  }

  // ���� 'i' �� �ִٸ�,  �Ǽ��ο� ����θ� ����� ó���ϸ� �ȴ�.
  real = get_number(str, begin, pos_i - 1);
  img = get_number(str, pos_i + 1, end - 1);

  if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}
```

�̸� ���� �ٸ� ����鵵 �����ϰ� ������ �� �ִ�.

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
  // �Է� ���� ���ڿ��� �м��Ͽ� real �κа� img �κ��� ã�ƾ� �Ѵ�.
  // ���ڿ��� ���� ������ �����ϴ� "[��ȣ](�Ǽ���)(��ȣ)i(�����)"
  // �� �� �� ���� ��ȣ�� ���� �����մϴ�. (������ + �� ����)

  int begin = 0, end = strlen(str);
  img = 0.0;
  real = 0.0;

  // ���� ���� ������ �Ǵ� 'i' �� ��ġ�� ã�´�.
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  // ���� 'i' �� ���ٸ� �� ���� �Ǽ� ���̴�.
  if (pos_i == -1) {
    real = get_number(str, begin, end - 1);
    return;
  }

  // ���� 'i' �� �ִٸ�,  �Ǽ��ο� ����θ� ����� ó���ϸ� �ȴ�.
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
      break;  // �� �̿��� �̻��� ���ڵ��� �� ���
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

�� ���� ��մ� ����, `Complex(const char *str)` �����ڸ� ���ܵΰ� `operator+(const char *str)` �迭���� ��� ����� �������ص� �� �����ϴ� ���� Ȯ���� �� �ִ�.
�ٽ� ����, `const char *str` �� ���ڷ� �޴� `operator` �Լ����� ��� ������ �� �����Ѵٴ� ���̴�.

�̴� �ռ� �ô� �����Ϸ��� ���� ������ �����ϴ�. ���� �Ʒ��� ���� �ڵ尡 �ִٰ� ����.

```c++
a = a + "-1.1 + i3.923";
```

�����Ϸ��� �� �ڵ带 �Ʒ��� ���� �ٲ۴�.

```c++
a = a.operator("-1.1 + i3.923");
```

������ ���� �ڵ忡�� `operator+(cont char *str)` �� ���� `operator+(const Complex& c)` �ۿ� ���⿡ ���� �����ε��� ���� �ʴ´�.
�׷����� �����Ϸ��� ���� ������ �����ε��� �� �� �ִ� �Լ����� �ִ��� Ȯ���ϰ� `const char *` ���� `Complex` �� ������ �� �ִ� �����ڰ� ������ Ȯ���Ѵ�.
�׷��� �����Ϸ��� �Ʒ��� ���� ������ ���� ���α׷��� ����� �۵���Ų��.

```c++
a = a.operator+(Complex("-1.1 + i3.923"));
```

���⼭ �� ���� ¤�� ������ ���� ���� �츮�� `operator+` �Լ��� ���ڷ� `const Complex& c` �� �ƴ϶� `Complex& c` �� �޵��� ���ٸ� ���� ���� ��ȯ�� �Ͼ�� �ʴ´�.
�ֳ��ϸ� `-1.1 + i3.923` ��ü�� ���ڿ� ���ͷ��̹Ƿ�, �̸� �������� ������ ��ü ���� ������� �ϱ� �����̴�.
�׷��⿡ ������� �Լ� ������ ���� �������� �ʴ´ٴ� Ȯ���� ��ٸ� ������ `const` ���ڸ� �޵��� �ϴ� ���� ����.

�̷��� ���ڿ� ���� ���Ҽ� ������ ������ �� �ֵ��� �������.

```c++
a = "-1.1 + i3.923" + a;
```

```c++
a = a + "-1.1 + i3.923";
```

�� �� �ڵ�� ������ ������ ������ �����ߵ��� �� �ڵ�� ����� �����ϵ��� �ʴ´�.
�ֳ��ϸ� `"-1.1 + i3.923" + a` �� ���, `a.operator+("-1.1+i3.923")` �� ���� ��ȯ�� �Ұ��ϱ� �����̴�.
�̸� �ذ��ϴ� ����� ���� é�Ϳ��� ���´�.

## 5-2 �����, ÷��, Ÿ�Ժ�ȯ, ���� ������ �����ε�

### friend Ű����

`friend` Ű����� Ŭ���� ���ο��� �ٸ� Ŭ������ �Լ����� friend�� ������ �� �ִ�.
`friend` �� ���ǵ� Ŭ������ �Լ����� ���� Ŭ������ `private` ���� ���ǵ� ������ �Լ��鿡 ������ �� �ִ�.

�Ʒ��� ���ø� ���캸��.

```c++
class A {
 private:
  void private_func() {}
  int private_num;

  // B �� A �� ģ��!
  friend class B;

  // func �� A �� ģ��!
  friend void func();
};

class B {
 public:
  void b() {
    A a;

    // ��� private �Լ��� �ʵ�������� ģ���̱� ������ ���� �����ϴ�.
    a.private_func();
    a.private_num = 2;
  }
};

void func() {
  A a;

  // ��� private �Լ��� �ʵ�������� ���� ���������� ģ���̱� ������ ����
  // �����ϴ�.
  a.private_func();
  a.private_num = 2;
}

int main() {}

```

���� �ڵ�� `B` �� `void func` �� `A` �� ģ����� �����ϰ� �ִ�. �̷��� ģ����� �����ϰ� �Ǹ�, `B` �� `func` �ȿ����� `A` �� ��� `private` ��� �Լ���� ��� �����鿡 ���� ���� ������ �ο��ϰ� �ȴ�.
���⼭ �� ģ�� ���谡 ¦����� ������ �����ؾ� �Ѵ�. ��, ���� ��� `B` �� `A` �� ��� `private` ���� �� �� ������, `B` �ȿ��� `A` �� `friend` �� �������� �ʴ� �̻�, `A` �� `B` �� `private` ��ü�鿡 ������ �� ����.

### ���� ������

���� é�Ϳ��� `a = "-1.1 + i3.923" + a` �� �����ϵ��� ������ Ȯ���ߴ�.
���� ���� ���� �ڵ带 ����� �� ���ٸ� ������ �����ε��� �ϴ� ����� �������.
������ ���ེ���Ե�, �����Ϸ��� ���� ������(�ǿ����ڸ� �� �� ���ϴ� �����ڵ�, `+, -, *, /, ->, = ��` )�� ������ ���� �� ���� ������� �ؼ��Ѵ�.

� ������ ������ `@` �� ���ؼ� `a@b` ��

> ���� c++���� @ �����ڴ� ����.

```c++
*a.operator@(b);
*operator@(a, b);
```

�����Ϸ��� �� �� ������ ����� ���ؼ� ó���Ѵ�. `a.operator@(b)` ���� `operator@` �� `a` �� Ŭ������ ��� �Լ��ν� ���Ǵ� ���̰�,
`operator@(a, b)` ������ `operator@` �� Ŭ���� �ܺο� ���ǵǾ� �ִ� �Ϲ����� �Լ��� �ǹ��ϰ� �ȴ�.
���� �̸� ó���ϱ� ���� �Լ��� �����غ���.

> ����� �̷��� ���� �Ϻ� �����ڵ鿡 ���ؼ��� �ش���� �ʴ´�. ��ǥ������ [] ������(÷��), -> ������(��� ����),
> = ������(����), () �Լ� ȣ�� �����ڵ��� ��� ��� �Լ��θ� ������ �� �ִ�. ��, ���� ��� �Լ��� �ƴ� ���� ������ �� �� ���ٴ� �ǹ��̴�.
> ���� �̵� �Լ��� �����ε� �� ���� ���ǰ� �ʿ��ϴ�.

```c++
Complex operator+(const Complex& a, const Complex& b) {
  // ...
}
```

�츮�� �� �ٸ� `operator+` �� �� ���� `const Complex&` Ÿ���� ���� `a,b` �� �ް� �ȴ�.
�տ��� �̾߱��ߵ��� �����Ϸ��� Ÿ���� ��Ȯ�� ��ġ���� �ʴ� ���, ���� ������ ������ �����ε� �Ǵ� �Լ��� ã�� �ǰ�,
�츮���� `Complex(const char *)` Ÿ���� �����ڰ� �ֱ⿡ ���ڿ��� ���꿡 ��� �����ϴ�.

�㳪 Ŭ������ ��� ������ `real` �� `img` �� `private` �̹Ƿ� �̸� �ذ��ϱ� ���� `friend` Ű���带 ����ؾ� �Ѵ�.

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

  // ������ ������ �Լ����� ���� :)

  void println() {
    std::cout << "( " << real << " , " << img << " ) " << std::endl;
  }

  // ���� �� �Լ��� Complex �� private ��� �����鿡 ������ �� �ֽ��ϴ�.
  friend Complex operator+(const Complex& a, const Complex& b);
};

Complex operator+(const Complex& a, const Complex& b) {
  Complex temp(a.real + b.real, a.img + b.img);
  return temp;
}

Complex::Complex(const char* str) {
  // �Է� ���� ���ڿ��� �м��Ͽ� real �κа� img �κ��� ã�ƾ� �Ѵ�.
  // ���ڿ��� ���� ������ �����ϴ� "[��ȣ](�Ǽ���)(��ȣ)i(�����)"
  // �� �� �� ���� ��ȣ�� ���� �����մϴ�. (������ + �� ����)

  int begin = 0, end = strlen(str);
  img = 0.0;
  real = 0.0;

  // ���� ���� ������ �Ǵ� 'i' �� ��ġ�� ã�´�.
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  // ���� 'i' �� ���ٸ� �� ���� �Ǽ� ���̴�.
  if (pos_i == -1) {
    real = get_number(str, begin, end - 1);
    return;
  }

  // ���� 'i' �� �ִٸ�,  �Ǽ��ο� ����θ� ����� ó���ϸ� �ȴ�.
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
      break;  // �� �̿��� �̻��� ���ڵ��� �� ���
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

���� ���� ������� ���� �� ������ ���� ��� ���� �ذ�� ���� �ƴϴ�.

�Ʒ��� ���� main()�� �����Ű�� ������ ������ �߻��Ѵ�.

```c++
int main() {
  Complex a(0, 0);
  a = "-1.1 + i3.923" + a;

  a = a + a;
  a.println();
}
```

�̴� �ռ� �����Ϸ��� `a + a` �� �ؼ��ϴ� �� ���� �����

```c++
a.operator+(a);
operator+(a, a);

```

�� ��� �����ϱ� ������ � ����� ���� ���� �𸣰ڴٴ� ������ �����.
���� �̸� �ذ��ϱ� ���ؼ��� �� �Լ� ��, �ϳ��� ���־� �Ѵ�.

��������� �ڱ� �ڽ��� �������� �ʴ� ���� �����ڵ�, ���� ��� `+, -, *, /` ���� ��� �ܺ��Լ��� �����ϴ� ���� ��Ģ�̴�.
�ݴ�� �ڱ� �ڽ��� �����ϴ� ���� �����ڵ�, ���� ��� `+=, -=` �� ���� �����ڵ��� ��� ��� �Լ��� �����ϴ� ���� ��Ģ�̴�.

�̰Ϳ� ���缭 �ڵ带 �����ϸ� ������ ����.

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

  // ������ ������ �Լ����� ���� :)

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
  // �Է� ���� ���ڿ��� �м��Ͽ� real �κа� img �κ��� ã�ƾ� �Ѵ�.
  // ���ڿ��� ���� ������ �����ϴ� "[��ȣ](�Ǽ���)(��ȣ)i(�����)"
  // �� �� �� ���� ��ȣ�� ���� �����մϴ�. (������ + �� ����)

  int begin = 0, end = strlen(str);
  img = 0.0;
  real = 0.0;

  // ���� ���� ������ �Ǵ� 'i' �� ��ġ�� ã�´�.
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  // ���� 'i' �� ���ٸ� �� ���� �Ǽ� ���̴�.
  if (pos_i == -1) {
    real = get_number(str, begin, end - 1);
    return;
  }

  // ���� 'i' �� �ִٸ�,  �Ǽ��ο� ����θ� ����� ó���ϸ� �ȴ�.
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
      break;  // �� �̿��� �̻��� ���ڵ��� �� ���
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

### ����� ������ �����ε� �ϱ�

```c++
std::cout << a;
```

���� �ڵ�� ��� `std::cout.operator<<(a)` �� ������ ����̴�.
��, � `std::cout` �̶�� ��ü�� ��� �Լ� `operator<<` �� ���ǵǾ� �־ `a` �� ȣ���ϴ� ���̴�.
�׷��� `std::cout` �� `int, double` �̳� ���ڿ����� `operator<<` �ϳ��� ����� �� �ִ� ������ �� ���� ���� `operator<<` �Լ����� �����ε��Ǿ� �ִٴ� �ǹ̴�.

������ �츮�� ���� `iostream` �� ��������� ���캸��(�����δ� `ostream` �� ���ǵǾ� �ִ�. �ٸ� `iostream` �� `ostream` �� include�ϰ� �ִ�.)
`ostream` Ŭ������

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

�� ���� ���� ���ǵǾ� �ִ� ���� �� �� �ִ�. �� ���п� �츮�� Ÿ�Կ� ������� �ս��� ����� ����� �� �ִ�.

�׷��ٸ� `Complex` Ŭ�������� `ostream` Ŭ������ ������ `operator<<` �� �����Ӱ� ����� �� �ִٸ� ���.
���� ���

```c++
Complex c;
std::cout << c;
```

�� �ϰ� �Ǹ�

```c++
Complex c;
c.println();
```

�� �� ��ó�� �����ϰ� ���̴�. �翬�� `ostream` Ŭ������ `operator<<` ��� �Լ��� ���Ӱ� �߰��ϴ� ���� �Ұ����ϴ�.
ǥ�� ��������� ������ ������ ���� ����.

����, �츮�� `ostream` Ŭ������ `Complex` ��ü�� �����ε��ϴ� `operator<<` ������ �Լ��� �߰��� ���� ����.
������ Ŭ������ ������ �Լ��� �߰��ϴ� �������, ��� �Լ��� ����ϴ� �� ���� �� ���� �� �ִ�.
�ٷ� `ostream` Ŭ���� ��ü�� `Complex` ��ü �� ���� ���ڷ� �޴� ���� `operator<<` �Լ��� �����ϴ� ���̴�.

```c++
std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << "( " << c.real << " , " << c.img << " ) ";
  return os;
}
```

����� `operator<<` ���� `ostream&` Ÿ���� �����ϴ� ������ `std::cout << "a�� ���� : " << a << " �̴�." << std::endl;` �� ���� ������ ó���ϱ� ���ؼ���.
������ �� `operator<<` �� ��� �� ���� ������ �ִµ� �ٷ� �� `operator<<` ���� `c.real` �� `c.img` �� ������ �� ���ٴ� ���̴�.
�ֳ��ϸ� `real` �� `img` ��� `Complex` Ŭ������ `private` ��� �������̱� �����̴�.

���� �̸� �ذ��ϱ� ���� �� ���� ����� ����� �� �ִ�.

1. `real` �� `img` �� `public` ���� �ٲ۴�.
2. `Complex` �� `print(std::ostream& os)` �� ���� ��� �Լ��� �߰��� ��, �̸� `operator<<` ���� ȣ���Ѵ�.
3. `operator<<` �� `friend` �� �����Ѵ�.

�� ��°�� ������ ��������� ���⼱ �� ��° ����� ����غ���.

```c++
friend ostream& operator<<(ostream& os, const Complex& c);
```

���� ����� ������� `Complex` ��ü `c` �� ���ؼ� `cin >> c;` �� ���� �۾��� �� �� �ִ�.
�ٸ�, �̹����� `cin` �� `istream` ��ü�̰�, `operator>>` �� �����ε��ؾ� �Ѵٴ� ���� �ٸ� ���̴�.

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

  // ������ ������ �Լ����� ���� :)

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
  // �Է� ���� ���ڿ��� �м��Ͽ� real �κа� img �κ��� ã�ƾ� �Ѵ�.
  // ���ڿ��� ���� ������ �����ϴ� "[��ȣ](�Ǽ���)(��ȣ)i(�����)"
  // �� �� �� ���� ��ȣ�� ���� �����մϴ�. (������ + �� ����)

  int begin = 0, end = strlen(str);
  img = 0.0;
  real = 0.0;

  // ���� ���� ������ �Ǵ� 'i' �� ��ġ�� ã�´�.
  int pos_i = -1;
  for (int i = 0; i != end; i++) {
    if (str[i] == 'i') {
      pos_i = i;
      break;
    }
  }

  // ���� 'i' �� ���ٸ� �� ���� �Ǽ� ���̴�.
  if (pos_i == -1) {
    real = get_number(str, begin, end - 1);
    return;
  }

  // ���� 'i' �� �ִٸ�,  �Ǽ��ο� ����θ� ����� ó���ϸ� �ȴ�.
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
      break;  // �� �̿��� �̻��� ���ڵ��� �� ���
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
  std::cout << "a �� ���� : " << a << " �̴�. " << std::endl;
}
```

> ���� �������� �ִ��� ������ ��Ģ�� ���� `friend` Ű���带 ���к��ϰ� ����ϴ� ���� ������� �ʴ´�.
> `friend` Ű����� �̹� ����ó�� �����ϰ� ����� �� �ִ� �κп����� ����ϴ� ���� ����.

### ÷�� ������(operator[])

�̹����� �迭���� ���Ҹ� ������ �� ���Ǵ� ÷�� ������ `[]` �� �����ε�����.

> ÷�� �����ڷ� �θ��� ������ �迭�� ���Ҹ� ������ �� [] �ȿ� �ִ� ���� ÷��(subscript) ��� �θ��� �����̴�.

`operator[]` �Լ��� �ڸ��ϰԵ� ���ڷ� �� ��° ��������, `int` �� ������ �ε����� �ް� �ȴ�.
���� `operator[]` �� ������ ���� ������ ������.

```c++
char& operatorp[](const int index);
```

`index` �� `[]` �ȿ� ���� ���� �ް� �ȴ�. �׸��� `char&` �� ���ڷ� �����ϴ� ������

```c++
str[10] = 'c';
```

�� ���� ����� �����ϱ� ������, �� ������ ���۷����� �����ϰ� �Ǵ� ���̴�.
������ `operator[]` �� ������ �Ʒ��� ���� �ſ� �ܼ��ϴ�.

```c++
char& MyString::operator[](const int index) { return string_content[index]; }
```

���� ���� `index` ��°�� `string_content` �� �����ؼ�, `operator[]` �� ����ϴ� ����ڰ� ���۷����� ���� �� �ְ� �ȴ�.

### int Wrapper Ŭ���� - Ÿ�� ��ȯ ������

`Wrapper` ��� ���� '������'��� �ǹ��� �ܾ��. c++������ � ��쿡 �⺻ �ڷ������� ��ü�� �ٷ�� �� ���� �ִ�.
�̷� ��, �⺻ �ڷ�����( `int, float` ��)�� Ŭ������ �����ؼ� ������ �ڷ����� ��ü�� ����ϴ� ���� `Wrapper` Ŭ������ �̿��Ѵٴ� ���̴�.

��, `int` �ڷ����� ���δ� int Wrapper Ŭ���� `Int` �� ������ ���� ������ �� �ִ�.

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

�� `Int` Ŭ������ `int` �� �ڷ����� �����ϴ� `data` ��� ������ �����ߴ�.
�츮�� `Int` ��ü�� `int` �� `Wrapper` Ŭ������ ��ü�� ��ŭ, `int` �� ��Ȯ�� �Ȱ��� �۵��ϵ��� ����� �ʹ�.
�ٽ� ����, �Ʒ��� ���� ����� ������ ���� ���� �� ����Ǳ⸦ ���Ѵ�.

```c++
Int x = 3;      // Wrapper ��ü
int a = x + 4;  // �׳� ����� int �� ���� a
```

�̸� �� �����ϱ� ���ؼ�, `int` ������ ���Ǵ� ��� ������ �Լ����� ������൵ ������ �̴� �ʹ� ��ȿ�����̴�.
�ֳ��ϸ� `int wrapper` Ŭ���� ��ü���� �ϴ� ���� `int` �� �������� �ϴ� �ϰ� ��Ȯ�� �����ϱ⿡ ���� ���� �ʿ䰡 ����.

�׷��ٸ�, �׳� �� `Wrapper` Ŭ������ ��ü�� ��ġ `int` �� ������� �����Ϸ��� �����ϰ� �� �� ������.
�̴� Ÿ�� ��ȯ �����ڸ� ���� �����ϴ�. ���� �����Ϸ��� �� Ŭ������ ��ü�� `int` �� ������ ��ȯ�� �� �ִٸ�, ��� `operator+` ���� �������� �ʴ��� �����Ϸ��� ���� �� ��ü�� `int` �� ������ ��ȯ�� ������ `+` �� ������ �� �ֱ� �����̴�.

Ÿ�� ��ȯ �����ڴ� ������ ���� �����Ѵ�.

```c++
operator (��ȯ�ϰ��� �ϴ� Ÿ��) ()
```
 
���� ��� �츮�� `int Wrapper` Ŭ������ ���, ������ ���� Ÿ�� ��ȯ �����ڸ� ������ �� �ִ�.

```c++
operator int()
```

�̶�, ������ ���� ������ó�� �Լ��� ���� Ÿ���� ���ָ� �� �ȴ�.�̴� c++���� ��ȯ �����ڸ� �����ϱ� ���� ��Ģ�̶� �� �� �ִ�.
�׷��⿡ �츮�� `int` ��ȯ �����ڸ� ������ ���� �����ϰ� ������ �� �ִ�.

```c++
operator int() { return data; }
```

�̷��� �ȴٸ� `Wrapper` Ŭ������ ��ü�� �д� ������ �ƹ��� ������ ����. �ֳ��ϸ� �����Ϸ� ���忡�� ������ ��ȯ �����ڷ� `operator int` �� ã�Ƽ� `int` �� ��ȯ�ؼ� ó���ϱ� �����̴�.
���Կ����� ������ ����Ʈ ���� �����ڰ� �˾Ƽ� ó���Ѵ�.

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

�� �ڵ带 �����غ��� `Int` ��ü�� `int` ������ �����ϰ� �������� Ȯ���� �� �ִ�.

### ����/���� ���� ������

���������� ���캼 �����ڴ� `++, --` �̴�. 

���� c++������ ���� �����ڿ� ���� �����ڸ� �����ϱ� ���ؼ� �����ε��� ������ ���� �����Ѵ�.

```c++
operator++();      // ++x;
operator--();      // --x;
operator++(int x); // x++;
operator--(int x); // x--;
```

��� ���� `x` �� �ƹ� �ǹ̰� ����. ���� �������� �������� �����ϱ� ���ؼ� ���� ���̴�.

�� ���� �߿��� ����, ���� ���� ������ ��� **���� �ٲ� �ڽ�** �� �����ؾ� �ϰ�, ���� ���� ������ ��� **���� �ٲ�� ������ ��ü** �� �����ؾ� �Ѵ�.

�Ʒ��� ���ô� ����/���� �������� ���̸� �����ش�.

```c++
int x = 1;
func(++x); // func(2)�� ����

int x = 1;
func(x++); // func(1)�� �����ϰ� x�� 1�� ����
```

���� �̸� �����ϸ� �Ʒ��� ���� ���� ���´�.

```c++
A& operator++() {
  // A ++ �� �����Ѵ�.
  return *this;
}

A operator++(int) {
  A temp(A);
  // A++ �� �����Ѵ�.
  return temp;
}
```

���� �����ڴ� ������ `++` �� �ش��ϴ� ������ ������ �Ŀ� �ڱ� �ڽ��� ��ȯ�Ѵ�.
������ ���� �����ڴ� `++` �� �ϱ� ���� ��ü�� ��ȯ�ؾ� �ϹǷ�, `temp` ��ü�� ���� ���� ���¸� ����� �Ŀ�, 
`++` �� �����ϰ� `temp` ��ü�� ��ȯ�Ѵ�.

���� ���� ���� ������ ��� �߰������� ���� �����ڸ� ȣ���ϱ� ������ ���� ���� �����ں��� ������.

### ����

������ �����ε��� ���� �ٷ�鼭 �� ���� �߿��� ����Ʈ�� ���� �����ϸ� ������ ����.

- �� ���� ������ ��ü ���̿��� ���� �����ڴ� ��� �Լ��� �ƴ� �ܺ� �Լ��� �����ε��ϴ� ���� ����.
  - ���� ��� `Complex` �� `operator+(const Complex&, const Complex&) cont` �� ���� ���̴�.
- �� ���� ��ü ������ ���� ������������ �� ��ü�� ���� �ٲ�� �� �������� ���� ���� �����ڴ� ��� �Լ��� �����ε��ϴ� ���� ����.
  - ���� ��� `operator+=` �� ���� ������������ `operator+=(const Complex&)` �� ����.
- ���� �����ڴ� ��� �Լ��� �����ε��ϴ� ���� ����.
  - ���� ��� `operator++` �� ��� ��� �Լ��� �����ε��Ѵ�.
- �Ϻ� �����ڵ��� �ݵ�� ��� �Լ��θ� �����ε��ؾ� �Ѵ�.

## 5-3 ������ �����ε� ������Ʈ - N���� �迭

### c++ ��Ÿ���� ĳ����



### N���� �迭 �����(���� ����)
