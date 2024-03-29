## 章节
> 1. ***词法“陷阱”***
> 2. 语法“陷阱”
> 3. 语义“陷阱”
> 4. 链接
> 5. 库函数
> 6. 预处理
> 7. 可移植性
> 8. 建议
> 9. 附录

---

## 词法“陷阱”

我们知道，将 C 语言源文件翻译成计算机可以识别的可执行文件，需要经过预处理、编译、汇编和链接四个过程。源文件本质上是`文本文件`，翻译得到的可执行文件则属于`二进制文件`。在这个翻译过程中，预处理部分进行一些简单的文本操作，编译部分则是将 C 代码翻译成汇编代码，而汇编部分又将汇编代码翻译成二进制的机器指令，最后由链接部分把有关的文件进行链接，整合成最终的可执行文件。（更详细的分析请查阅《编译原理》）

那么，编译过程中将 C 程序分解成一个个`符号（token，即基本组成单元）`的部分，一般称为“词法分析器”。对于词法分析这一部分，有一些可能会发生的“陷阱”。

#### 1.1 = 不同于 ==（略）

#### 1.2 & 和 | 不同于 && 和 ||

& 和 | 是位运算符，而 && 和 || 属于逻辑运算符。有人可能会发现，有时候用 & 和 | 代替 && 和 || 程序依然可以运行，但这仅限于两边的操作数为 0(false) 或 1(true) 时。

```C
if(4 & 1)
    printf("4 & 1\n");
// 4 & 1 的结果为 0，条件为假

if(4 && 1)
    printf("4 && 1\n");
// 条件为真
```

就算如此，&& 和 || 也有其特殊之处：求 值顺序，**&& 左边为假则跳过右边，|| 左边为真则跳过右边。**而 & 和 | 则不行。

#### 1.3 词法分析中的“贪心法”

C 语言中的 `/`、`*`、`=`等，只有一个字符，为*单字符符号*；而 `/*`、`==` 等，包括了多个字符，为*多字符符号*。那么词法分析器就必须做出判断：是将其作为两个符号（token）对待，还是一个。

```C
int a = 20, b = 10;
int c = a---b; // ?
int* p = &b;
c = a/*p; // ?
```

C 编译器的解决办法是，**每一个符号应该包含尽可能多的字符**。这个处理方法有时被称为“贪心法”。但注意：除了字符串常量和字符常量，符号的中间不能嵌有空白。上述代码猜测其本意应改为：

```C
int c = (a--) - b; // 或者 int c = a - (--b);
c = a / (*p);
```

#### 1.4整型常量中的八进制数

有些老版本的 C 编译器会把 8 和 9 也当作八进制数字处理，如`0195`。C 标准禁止这种用法。

#### 1.5字符与字符串

用单引号引起的一个字符**本质是一个整数**，用双引号引起的字符串**本质是该字符串首字符的地址**。

> ##### 练习 1\_1
> 某些 C 编译器允许对`/* comments */`作嵌套注释`/*/* comments */*/`，而不允许的编译器只能检测到`/*/* comments */`。<br>
> 请写一个测试程序，测试当前编译器是否允许嵌套注释。