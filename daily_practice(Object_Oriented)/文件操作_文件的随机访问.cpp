/*
C/C++学习指南部发www.afanilhao.cn
文件的随机访冋
计算机领域的两个术语
顺序访问: sequential access,按顺序访问,不能跳跃
疸机访问: random access,随意跳到一个位置访问

举例,当在看一个IP4电影时,你可以拖放进度条到任意位
置访问。你在拖放(seek)的时候,实际上播放器就是用了随
机访问。

文件是不是支持“随机访问”?是由物理存储和系统驱动决
定的。一般来说,我们使用的硬盘都是支持“随机访问”的


fseek
ANSI C函数:使用fseek可以实现文件FILE*的随机访问
int fseek(FILE *stream, long offset, int mode);

注:本篇只讧论在“读”文件时候的随机访问技术

参数
stream:文件指针 
offset:一个整数,表示偏移值
mode:  相对位置
返回值
0,操作成功;-1,操作失败

*/