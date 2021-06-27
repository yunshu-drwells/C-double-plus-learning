
##### 示例：calc文件中给定<a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/blob/master/practice_creat_lib/calc/add.c">add.c</a> <a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/blob/master/practice_creat_lib/calc/div.c">div.c</a> <a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/blob/master/practice_creat_lib/calc/mult.c">mult.c</a> <a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/blob/master/practice_creat_lib/calc/sub.c">sub.c</a>制作静态库<a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/blob/master/practice_creat_lib/calc/libcalc.a">libcalc.a</a>以及使用


###### 进入.c源文件路径
    
    cd /practice_creat_lib/calc/

###### gcc生成.o目标文件

    gcc add.c div.c mult.c sub.c -c

###### 生成静态库

    ar rcs libcalc.a add.o div.o mult.o sub.o
    或者：
    ar rcs libcalc.a *.o

> 不包括main.c

##### 使用libcalc.a静态库库

###### 从calc中生成的静态库libcalc.a拷贝到library/lib/下

    cp calc/libcalc.a library/lib/

###### 从calc中拷贝头文件head.h到library/include/下

    cp calc/head.h library/include/

###### 编译library中的程序

    gcc main.c -o app -I ../include/ -l calc -L ../lib/

> -I 选项指定include包含文件的搜索路径
> -l 选项指定加载的静态库名
> -L 选项指定搜索的库的路径

测试发现生成的可执行文件可以正常运行



---

<img src="https://img-blog.csdnimg.cn/20210129183339102.png" height=30>





##### 示例：calc文件中给定<a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/blob/master/practice_creat_lib/calc/add.c">add.c</a> <a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/blob/master/practice_creat_lib/calc/div.c">div.c</a> <a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/blob/master/practice_creat_lib/calc/mult.c">mult.c</a> <a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/blob/master/practice_creat_lib/calc/sub.c">sub.c</a> <a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/blob/master/practice_creat_lib/calc/main.c">main.c</a>制作动态库<a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/blob/master/practice_creat_lib/calc//libcalc.so">libcalc.so</a>以及使用


###### 进入calc先删除制作静态库生成的.o目标文件和之前使用的动态库以及可执行文件

    rm *.o
    rm library/lib/libcalc.a
    rm src/app
    

###### 生成与位置无关的代码

    gcc -c -fpic *.c

> 包括main.c

###### 生成动态库

    gcc -shared *.o -o libcalc.so


##### 使用libcalc.so动态库库


###### 拷贝calc中生成的动态库libcalc.so到library的lib下

    cp calc/libcalc.so library/lib/

> library/include/下任然需要calc中的head.h



###### 进入src路径开始编译


     gcc main.c -o app -I ../include/ -l calc -L ../lib/

> -I 选项指定include包含文件的搜索路径





##### 定位动态库

程序要正常执行需要定位动态库：先后搜索elf文件的 DT_RPATH段——> 环境变量 LD_LIBRARY_PATH ——> /etc/ld.so.cache 文件列表——>/lib/, /usr/lib 目录找到库文件



###### 将动态库添加到环境变量LD_LIBRARY_PATH(临时性的)

    # 找到libcalc.so的绝对路径
    pwd library/lib
    # 添加到环境变量LD_LIBRARY_PATH
    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/ubuntu/code/practice_creat_lib/library/lib

echo对比环境变量LD_LIBRARY_PATH添加libcalc.so的绝对路径前后的值

```
    ubuntu@VM-0-10-ubuntu:~/code/practice_creat_lib/library$ echo $LD_LIBRARY_PATH
    
    ubuntu@VM-0-10-ubuntu:~/code/practice_creat_lib/library$ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/ubuntu/code/practice_creat_lib/library/lib
    ubuntu@VM-0-10-ubuntu:~/code/practice_creat_lib/library$ echo $LD_LIBRARY_PATH
    :/home/ubuntu/code/practice_creat_lib/library
```

ldd命令检查动态库依赖关系,看是否可以找到动态库

```
    ubuntu@VM-0-10-ubuntu:~/code/practice_creat_lib/library/src$ ldd app
	linux-vdso.so.1 (0x00007fff29545000)
	libcalc.so => /home/ubuntu/code/practice_creat_lib/library/lib/libcalc.so (0x00007f47a4b3a000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f47a4749000)
	/lib64/ld-linux-x86-64.so.2 (0x00007f47a4f3e000)
```

> 就可以正常执行了


###### 修改配置文件.bashrc(用户级别的配置文件)(永久有效)

进入~

    cd

ll命令找到.bashrc文件

    # 认真找
    ll
    # 或者grep
    ll | grep .bashrc

![在这里插入图片描述](https://img-blog.csdnimg.cn/20210627120549529.png)

vim修改 .bashrc

    vim .bashrc

在文件末尾插入

```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/ubuntu/code/practice_creat_lib/library/lib
```

同步一下(刷新一下)

```
. .bashrc
# 或
source .bashrc
# .就是source
```

> 此时共享库就可以成功定位，app 就可以正常运行了了


###### 修改配置文件/etc/profile(系统级别的配置文件)(永久有效)


进入~

    cd

设置/etc/profile权限为可修改

    chmod 777 /etc/profile

vim修改 /etc/profile

    vim /etc/profile


在文件末尾插入

```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/ubuntu/code/practice_creat_lib/library/lib
```

