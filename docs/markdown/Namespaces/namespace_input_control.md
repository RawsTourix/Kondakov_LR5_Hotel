---
title: InputControl
summary: Пространство имён для функций управления вводом данных 

---

# InputControl

Пространство имён для функций управления вводом данных 

## Classes

|                | Name           |
| -------------- | -------------- |
| struct | **[InputControl::DelimitedContainer](Classes/struct_input_control_1_1_delimited_container.md)** <br>Шаблонный класс для работы с разделителями (базовый шаблон)  |
| struct | **[InputControl::DelimitedContainer< Delim, Container &, enable_if_t< is_same_v< typename Container::value_type, string >, void > >](Classes/struct_input_control_1_1_delimited_container_3_01_delim_00_01_container_01_6_00_01enable__if__t_e12e72f0c289026bc10ec07e7fe406c5.md)** <br>Специализация [DelimitedContainer](Classes/struct_input_control_1_1_delimited_container.md) для работы со строками  |

## Functions

|                | Name           |
| -------------- | -------------- |
| void | **[trim](Namespaces/namespace_input_control.md#function-trim)**(string & str)<br>Удаляет пробелы в начале и конце строки  |
| template <char Delim,typename Container \> <br>void | **[split](Namespaces/namespace_input_control.md#function-split)**(const string & input_line, [DelimitedContainer](Classes/struct_input_control_1_1_delimited_container.md)< Delim, Container & > & dc)<br>Разделяет строку на подстроки по разделителю  |
| string | **[get_lowercase](Namespaces/namespace_input_control.md#function-get-lowercase)**(const string str)<br>Преобразует строку в нижний регистр  |
| void | **[make_first_letter_uppercase](Namespaces/namespace_input_control.md#function-make-first-letter-uppercase)**(string & str)<br>Делает первую букву строки заглавной  |
| bool | **[is_input_empty](Namespaces/namespace_input_control.md#function-is-input-empty)**(const string & input)<br>Проверяет, является ли ввод пустым (для отмены операции)  |
| template <typename T \> <br>bool | **[check_min_max](Namespaces/namespace_input_control.md#function-check-min-max)**(const T & number, T min, T max)<br>Проверяет число на вхождение в диапазон  |
| bool | **[input](Namespaces/namespace_input_control.md#function-input)**(string & varLink, const string & label)<br>Функция ввода для строк  |
| bool | **[input](Namespaces/namespace_input_control.md#function-input)**(bool & varLink, const string & label)<br>Функция ввода для bool.  |
| template <typename T \> <br>enable_if_t< is_arithmetic_v< T >, bool > | **[input](Namespaces/namespace_input_control.md#function-input)**(T & varLink, const string & label, T min =0, T max =numeric_limits< T >::max())<br>Функция ввода для чисел  |
| char | **[get_char](Namespaces/namespace_input_control.md#function-get-char)**()<br>Получает один символ из ввода  |
| bool | **[yes_or_no](Namespaces/namespace_input_control.md#function-yes-or-no)**(const string & label)<br>Запрашивает подтверждение (y/n)  |


## Functions Documentation

### function trim

```cpp
void trim(
    string & str
)
```

Удаляет пробелы в начале и конце строки 

**Parameters**: 

  * **str** Строка для обработки 


### function split

```cpp
template <char Delim,
typename Container >
void split(
    const string & input_line,
    DelimitedContainer< Delim, Container & > & dc
)
```

Разделяет строку на подстроки по разделителю 

**Parameters**: 

  * **input_line** Входная строка 
  * **dc** Контейнер с разделителем
  * **input_line** Входная строка 
  * **dc** Контейнер с разделителем


**Template Parameters**: 

  * **Delim** Разделитель 
  * **Container** Тип контейнера для результатов 
  * **Delim** Разделитель 
  * **Container** Тип контейнера для результатов 



Очищает целевой контейнер, разделяет строку по разделителю, удаляет пустые элементы, проверяет на дубликаты (без учёта регистра), делает первую букву каждого элемента заглавной 


### function get_lowercase

```cpp
string get_lowercase(
    const string str
)
```

Преобразует строку в нижний регистр 

**Parameters**: 

  * **str** Входная строка 


**Return**: Строка в нижнем регистре 

### function make_first_letter_uppercase

```cpp
void make_first_letter_uppercase(
    string & str
)
```

Делает первую букву строки заглавной 

**Parameters**: 

  * **str** Строка для обработки 


### function is_input_empty

```cpp
bool is_input_empty(
    const string & input
)
```

Проверяет, является ли ввод пустым (для отмены операции) 

**Parameters**: 

  * **input** Входная строка 
  * **input** Входная строка 


**Return**: 

  * true если ввод пустой, иначе false
  * true если ввод пустой, иначе false



Выводит сообщение "[Отмена операции]" если ввод пустой 


### function check_min_max

```cpp
template <typename T >
bool check_min_max(
    const T & number,
    T min,
    T max
)
```

Проверяет число на вхождение в диапазон 

**Parameters**: 

  * **number** Проверяемое число 
  * **min** Минимальное значение 
  * **max** Максимальное значение 
  * **number** Проверяемое число 
  * **min** Минимальное значение 
  * **max** Максимальное значение 


**Template Parameters**: 

  * **T** Тип числа 
  * **T** Тип числа 


**Return**: 

  * true если число в диапазоне, иначе false
  * true если число в диапазоне, иначе false



Выводит сообщение об ошибке если число вне диапазона 


### function input

```cpp
bool input(
    string & varLink,
    const string & label
)
```

Функция ввода для строк 

**Parameters**: 

  * **varLink** Ссылка на переменную для сохранения результата 
  * **label** Подпись для ввода 


**Return**: true если операция отменена, иначе false 

### function input

```cpp
bool input(
    bool & varLink,
    const string & label
)
```

Функция ввода для bool. 

**Parameters**: 

  * **varLink** Ссылка на переменную для сохранения результата 
  * **label** Подпись для ввода 
  * **varLink** Ссылка на переменную для сохранения результата 
  * **label** Подпись для ввода 


**Return**: 

  * true если операция отменена, иначе false
  * true если операция отменена, иначе false



Использует ввод числа (0 или 1) с последующим преобразованием в bool 


### function input

```cpp
template <typename T >
enable_if_t< is_arithmetic_v< T >, bool > input(
    T & varLink,
    const string & label,
    T min =0,
    T max =numeric_limits< T >::max()
)
```

Функция ввода для чисел 

**Parameters**: 

  * **varLink** Ссылка на переменную для сохранения результата 
  * **label** Подпись для ввода 
  * **min** Минимальное значение 
  * **max** Максимальное значение 
  * **varLink** Ссылка на переменную для сохранения результата 
  * **label** Подпись для ввода 
  * **min** Минимальное значение 
  * **max** Максимальное значение 


**Template Parameters**: 

  * **T** Арифметический тип данных 
  * **T** Арифметический тип данных 


**Return**: 

  * true если операция отменена, иначе false
  * true если операция отменена, иначе false



Запрашивает ввод пока не будет получено корректное число в заданном диапазоне 


### function get_char

```cpp
char get_char()
```

Получает один символ из ввода 

**Return**: 

  * Введённый символ
  * Введённый символ



Очищает буфер ввода после считывания символа 


### function yes_or_no

```cpp
bool yes_or_no(
    const string & label
)
```

Запрашивает подтверждение (y/n) 

**Parameters**: 

  * **label** Подпись для запроса 
  * **label** Подпись для запроса 


**Return**: 

  * true если введено 'y' или 'Y', false если 'n' или 'N'
  * true если введено 'y' или 'Y', false если 'n' или 'N'



Циклически запрашивает ввод пока не будет получен корректный ответ 






-------------------------------

Updated on 2025-05-06 at 23:16:47 +0300