## 章节

> 1. 词法“陷阱”
> 2. 语法“陷阱”
> 3. 语义“陷阱”
> 4. 链接
> 5. ***库函数***
> 6. 预处理
> 7. 可移植性
> 8. 建议
> 9. 附录

---

## 库函数

#### 5.1 返回 int 的 getchar

看代码：

```C
#include <stdio.h>
int main()
{
    char ch;
    while((ch = getchar()) != EOF)
        putchar(ch);
    return 0;
}
```

这个程序乍一看似乎是把标准输入复制到标准输出，实则不然。函数`getchar`返回 int 类型而 ch 是 char 类型，意味着 ch 可能无法容下所有字符（有些编译器把 char 实现为有符号类型，范围是 -128~127；有些则是实现为无符号类型，范围是 0~255）

> 注：getchar 可以用宏实现也可以用函数实现。

#### 5.2 更新顺序文件

> 顺序文件：*文件内容的逻辑顺序 与 实际存储的物理顺序一致*的文件

为了保持与过去的程序的兼容性，以“读写”打开的文件，一个输入操作后不能直接跟一个输出操作，反之亦然。输入和输出操作之间要有`fseek`函数，`fseek`函数能改变文件的状态。

#### 5.3 缓冲输出与内存分配

使用缓冲区可以减少输入输出的系统开销，但要注意最后一次的清空。设置缓冲区的函数`setbuf`和`setvbuf`，清空缓冲区的函数`fflush`。

> 当一个程序异常终止时，程序输出的最后几行可能会丢失，原因是什么？怎么解决这个问题？

一个异常中止的程序可能没有机会清空其输出缓冲区（如果有缓冲区的话）。这对于调试这类程序的人来说会产生误导，以为 bug 在丢失的输出之前。解决方法是输出时不缓冲：如果缓冲区是我们设置的，取消设置；如果是系统默认设置的，则把下面的语句作为`main`函数的第一条语句即可。

```C
setbuf(stdout, (char *)0);
```

#### 5.4 使用 errno 检测错误

需要引用库文件`<errno.h>`。

```C
printf("%s\n", strerror(errno));
```

#### 5.5 库函数 signal

所有的 C 语言实现中都包含`signal`库函数，将其作为捕获异步事件的一种方式。

信号（signal）非常复杂棘手，而且具有一些从本质上而言不可移植的特性。我们最好采取“守势”，让 signal 处理函数尽可能简单，并将它们组织在一起。这样，当需要适应一个新系统时，我们可以很容易地进行修改。
