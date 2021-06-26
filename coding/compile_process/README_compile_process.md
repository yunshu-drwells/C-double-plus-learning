
### GCC编译流程

<img src="https://img-blog.csdnimg.cn/20210625113417164.png" height=350/>

##### 源码

```c
#include <stdio.h>

#define PI 3.14

int main(){
    //注释

    int num = 10+PI;

    printf("hello, %d", num);cd 
    return 0;
}
```

<a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/tree/master/coding/compile_process/test.c">test.c</a>

##### 预处理生成.i文件

gcc -E test.c -o test.i

<a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/tree/master/coding/compile_process/test.i">test.i</a>


##### 预编译：这个过程主要的处理操作如下：

（1） 将所有的#define删除并替换，展开所有的宏定义

（2） 处理所有的条件预编译指令，如#if、#ifdef

（3） 处理#include预编译指令，将被包含的文件插入到该预编译指令的位置。

（4） 过滤所有的注释

（5） 添加行号和文件名标识。



##### 编译生成.S文件

gcc -S test.i -o test.S

<a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/tree/master/coding/compile_process/test.S">test.S</a>


##### 汇编生成.o文件

gcc -c test.S -o test.o

<a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/tree/master/coding/compile_process/test.o">test.o</a>


##### 链接

gcc test.o -o test.out

<a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/tree/master/coding/compile_process/test.out">test.out</a>