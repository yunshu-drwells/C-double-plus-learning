/*
ulimit -a查看发现默认core file 是 0
ulimit -c unlimited 修改core文件大小未无限制
编译运行这个core就会提示段错误并且生成一个core文件

编译(-g选项)
gcc core.c -g

运行a.out
./a.out

会生成一个core的文件

调试a.out
gdb a.out

在gdb中输入以下命令就可以通过core文件查看错误
core-file core

提示错误信息：
:Program terminated with signal SIGSEGV, Segmentation fault.
#0  0x000055bdd9118602 in main () at core.c:19
*/

#include <stdio.h>
#include <string.h>

int main() {

    char * buf;

    strcpy(buf, "hello");

    return 0;
}