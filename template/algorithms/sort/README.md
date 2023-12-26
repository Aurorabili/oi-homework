# 排序算法

## 语法基础

本章节将介绍一些课堂上未提及的语法基础以便于你理解代码。

### 使用模板定义函数

不止是整数类型的数据需要排序函数，有时候我们希望对实数类型的数据进行排序，有时候我们希望对字符串类型的数据进行排序，有时候我们希望对自定义类型的数据进行排序。也许我们会这样写：

```cpp
void sort_int(int *array, int size);
void sort_double(double *array, int size);
void sort_string(string *array, int size);
void sort_custom(custom *array, int size);
```

显然这样写是不合理的，当我们需要修改排序算法时，我们需要修改所有的排序函数。这样的代码是不可维护的。
我们总是希望一个逻辑只有一个实现，这样的代码才是可维护的。

在C++中，我们可以使用模板来定义函数，这样我们就可以实现一个逻辑对应多个实现的代码。

```cpp
template <typename T>
void sort(T *array, int size);
```

这样以来，无论`array`是什么类型的数据，我们都可以使用`sort`函数对其进行排序。

### 使用array

在C语言以及C++98中，我们需要使用指针来表示数组。
    
```cpp
int array[10];

// 传递数组
void sort(int *array, int size);
sort(array, 10);
```

这样的代码隐含着内存安全问题。我们无法保证`array`的长度是`size`，也无法保证`array`不是空指针。一旦发生越界行为，程序就会产生意料之外的行为，崩溃就是其中一种。

在C++11中，标准模板库引入了`array`类型，我们可以使用`array`类型来表示数组。

```cpp
#include <array>

std::array<int, 10> array; // 长度为10的int数组

// 传递数组
void sort(std::array<int, 10> &array);
sort(array);
```

此处的`array`是一个对象，它的长度是固定的，我们无法修改它的长度。当我们传递`array`时，我们传递的是`array`的引用，这样我们就可以保证`array`不是空指针。使用非`const`引用表示`sort()`将被允许对原数组进行修改和排序。

**并不是所有情况都应该使用array代替数组指针。**

### 比较函数

通常情况下，我们知道如何比较两个整数数据。但是对于自定义类型的数据，我们可能不知道如何比较两个数据的大小。例如现在有一个`Student`类，我们希望对`Student`类的对象进行排序，但是我们不知道如何比较两个`Student`对象的大小。

```cpp
typedef struct {
    int id;
    string name;
    int age;
} Student;
```

在一些情况下，我们希望对年龄`age`进行排序，有时候我们希望对学号`id`进行排序，有时候我们希望对姓名`name`进行排序。我们可以使用函数指针来传递比较函数。

```cpp
bool cmp(Student *a, Student *b) {
    return a->id > b->id;
}
```

该比较函数接受两个`Student`对象的指针，返回`true`表示`a`大于`b`，返回`false`表示`a`小于等于`b`。这样我们就定义了`Student`对象的**序**。

很多时候，为了方便，我们希望像比较整数那样使用大于号和小于号来比较两个对象的大小。我们可以重载`operator>`和`operator<`来实现这一功能。

```cpp
typedef struct {
    int id;
    string name;
    int age;

    bool operator>(const Student &b) const {
        return id > b.id;
    }

    bool operator<(const Student &b) const {
        return id < b.id;
    }
} Student;
```

这样我们就可以使用`>`和`<`来比较两个`Student`对象的大小了。

```cpp
Student a, b;
a.id = 1;
b.id = 2;
cout << (a > b) << endl; // 0
cout << (a < b) << endl; // 1
```

### 使用lambda表达式

在前面的章节中，我们使用类型模板来定义函数，使用比较函数定义了对象的序。

现在我们需要将比较函数传入排序函数，我们可以使用函数指针来传递比较函数。

```cpp
void sort(int *array, int size, bool (*cmp)(int, int));

bool cmp(int a, int b) {
    return a > b;
}

int array[10];
sort(array, 10, cmp);
```

当我们需要对不同类型的数据进行排序时，使用模板改写。

```cpp
template <typename T, std::size_t N, typename Compare>
void sort(std::array<T, N> &array, Compare cmp);

bool cmp(int a, int b) {
    return a > b;
}

std::array<int, 10> array;
sort(array, cmp);
```

显然如果对每一种类型都显式的定义一个比较函数是繁杂且丑陋的，这样会降低代码的可读性。
比如你使用自然语言描述排序时，你可能会说“按照学号从小到大排序”，“按照年龄从大到小排序”，“按照姓名从小到大排序”。
我们希望使用自然语言描述排序的方式来定义比较函数。

使用lambda表达式可以定义一个匿名函数，我们可以使用lambda表达式来定义比较函数。

```cpp
std::array<int, 10> array;
sort(array, [](int a, int b) { return a > b; });
```

代码`[](int a, int b) { return a > b; }`定义了一个比较函数，该比较函数接受两个`int`类型的参数，返回`true`表示`a`大于`b`，返回`false`表示`a`小于等于`b`。

这很直观地使用一句话表达了“按照自然序从小到大排序”的意思。如果我们希望改成从大到小排序，只需要将`>`改成`<`即可。

