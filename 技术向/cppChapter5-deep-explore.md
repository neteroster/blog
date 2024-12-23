# C++ 第五章 “深度探索” 笔记

## 编译

生成可执行文件的第一步就是编译。（注意：这里的编译是指生成“目标文件”的编译，而不是指生产可执行文件的编译）。

每一个 `.cpp` 文件对应一个编译单元。编译程序每次处理一个编译单元，分多次编译。各个编译单元互相独立，在编译过程中不产生联系。

每个编译单元被编译后生成对应的 `.o` 目标文件（在 VCPP 下是 `.obj`），这个 `.o` 文件结构大致如下：

```
---TEXT---
这里是代码段。存放代码文本。没有分割标记。

---DATA---
这里存放已经有初值静态生存期对象的数据，没有对应符号。

---BSS---
这里存放没有初值的静态生存期变量需要分配的空间大小，没有对应符号。

---SYMB---
这里是符号表。每一个静态生存期的函数和对象、变量都对应一个符号。符号表将符号与他在上面三个段的位置建立联系。

```
注意：符号表同时包含不在本编译单元的符号（静态生存期函数、对象符号），但是没有对应位置。

一个简单的例子如下：

```cpp
// a.cpp
extern int y; // y is defined in b.cpp
int func(int v); // func is defined in b.cpp
int main()
{
	int z = 1;
	y = func(z);
	return 0;
}

// b.cpp
int x = 3;
int y;
int func(int v)
{
	return v + x;
}
```

那么：（注意：`.o` 文件结构只是示意）

```
(a.o)
---TEXT---
(...main_func_content...)

---DATA---
1

---BSS---

---SYMB---
main() -> TEXT[0]
func() -> ?UNDEF?
y -> ?UNDEF?

(b.o)
---TEXT---
(...func_content...)

---DATA---
3

---BSS---
(32b)

---SYMB---
x -> DATA[0]
y -> BSS[0]
func_v -> TEXT[0]
```

需要注意：目标文件中，函数的参数需在名字上体现，因为参数不同的函数属于重载，不是同一个函数，必须在目标文件以不同符号体现。

## 链接

编译完成后，就要将不同编译单元分别生成的 `.o` 进行链接。链接过程中，符号表中未定义位置的变量之位置得以从其他 `.o` 文件中取得。互相交换符号表以及其它一些数据后，便生成可执行文件。为什么不能重定义也是因为链接的时候如果两张符号表出现同一个符号，则他们的地址有两个，无法确定是哪一个，则链接错误。

## 运行

生成可执行文件后，可以开始运行。当开始运行时，操作系统首先进行引导操作，为静态生存期函数、变量、对象分配内存空间，装载静态函数代码，初始化有初值的静态对象，然后引导进入 `main()` 函数。

## 为什么“静态生存期”显得特别

静态生存期对象和函数与普通对象函数的根本区别就是：静态生存期对象在开始运行程序时就分配**固定**的内存地址；而普通对象和函数则是由（静态生存期函数中的）代码在适当时机创建和销毁。所谓“静态”，就是其地址不会发生改变（在同一个程序运行周期中）。由代码创建和销毁的变量和对象，每次创建和销毁都不会是同一地址，所以不“静态”。
