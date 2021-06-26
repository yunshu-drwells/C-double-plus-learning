
给<a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/tree/master/coding/practic_Makefile/add.c">add.c</a> <a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/tree/master/coding/practic_Makefile/div.c">div.c</a> <a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/tree/master/coding/practic_Makefile/sub.c">sub.c</a> <a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/tree/master/coding/practic_Makefile/mult.c">mult.c </a><a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/tree/master/coding/practic_Makefile/main.c">main.c</a>练习makefile命令

###### 使用命令编译：

	gcc add.c div.c sub.c mult.c main.c o app


###### <a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/blob/master/coding/practic_Makefile/Makefile1">Makefile1</a>:

```
	app: sub.c add.c mult.c div.c main.c
		gcc sub.c add.c mult.c div.c main.c -o app
```

拷贝到Makefile:

	cp Makefile1 Makefile

make一下，执行命令：

	gcc sub.c add.c mult.c div.c main.c -o app

> 符合规则：如果存在，执行命令


###### <a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/blob/master/coding/practic_Makefile/Makefile2">Makefile2</a>:


```
app: sub.o add.o mult.o div.o main.o
	gcc sub.c add.c mult.c div.c main.c -o app

sub.o:sub.c
	gcc -c sub.c -o sub.o

add.o:add.c
	gcc -c add.c -o add.o

mult.o:mult.c
	gcc -c mult.c -o mult.o

div.o:div.c
	gcc -c div.c -o div.o

main.o:main.c
	gcc -c main.c -o main.o
```



拷贝到Makefile:

	cp Makefile2 Makefile

make一下，执行命令：

    gcc -c sub.c -o sub.o
    gcc -c add.c -o add.o
    gcc -c mult.c -o mult.o
    gcc -c div.c -o div.o
    gcc -c main.c -o main.o
    gcc sub.o add.o mult.o div.o main.o -o app

> 符合基本原理：如果不存在，向下检查其它规则，检查有没有一个规则是用来生成这个依赖的，如果找到了，则执行该规则中的命令



更改一下add.c文件

add修改时间会比上一次生成app目标文件时间晚，make一下，执行命令：

```
gcc -c add.c -o add.o
gcc sub.o add.o mult.o div.o main.o -o app
```
Makefile工具会检测更新情况，如果依赖文件比目标文件修改时间晚则会重新生成，如果依赖文件没有更新则会提升已经时最新的，不再重新生成

继续make一下，提示：

    make: 'app' is up to date.

> 符合基本原理：如果依赖的时间比目标时间晚，需要更新生成目标；如果依赖的时间比目标时间早，目标不需要更新，对应规则中的命令不需要被执行

make时遇到Makefile:2: *** missing separator.  Stop.问题请参考文章：<a href="https://blog.csdn.net/qq_43808700/article/details/118241610">Makefile:2: *** missing separator. Stop.</a>





###### 使用变量<a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/blob/master/coding/practic_Makefile/Makefile3">编写Makefile3</a>：

```
# 定义变量
src=sub.o add.o mult.o div.o main.o
target=app
$(target):$(src)
	$(CC) $(src) -o $(target)

sub.o:sub.c
	gcc -c sub.c -o sub.o

add.o:add.c
	gcc -c add.c -o add.o

mult.o:mult.c
	gcc -c mult.c -o mult.o

div.o:div.c
	gcc -c div.c -o div.o

main.o:main.c
	gcc -c main.c -o main.o
```


拷贝到Makefile:

	cp Makefile3 Makefile

make一下，执行命令：

    gcc -c sub.c -o sub.o
    gcc -c add.c -o add.o
    gcc -c mult.c -o mult.o
    gcc -c div.c -o div.o
    gcc -c main.c -o main.o
    cc sub.o add.o mult.o div.o main.o -o app




###### 使用匹配模式，简化Makefile3-><a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/blob/master/coding/practic_Makefile/Makefile4">Makefile4</a>

```
src=sub.o add.o mult.o div.o main.o
target=app
$(target):$(src)
	$(CC) $(src) -o $(target)

%.o:%.c
   $(CC) -c $< -o $@
```


拷贝到Makefile:

	cp Makefile4 Makefile

make一下，执行命令：

    cc -c sub.c -o sub.o
    cc -c add.c -o add.o
    cc -c mult.c -o mult.o
    cc -c div.c -o div.o
    cc -c main.c -o main.o
    cc sub.o add.o mult.o div.o main.o -o app


###### 使用函数编写<a href="https://github.com/yangzhiyuanDrwells/C-double-plus-learning/blob/master/coding/practic_Makefile/Makefile5">Makefile5</a>




```
src=$(wildcard ./*.c) # 通过wildcard函数在./路径下找和*.c匹配的内容
objs=$(patsubst %.c, %.o, $(src)) # 通过patsubst将src中的字符串匹配到的%.o替换成%.o
# 依赖文件过多书写起来不美观而且容易遗漏，这种方式在增加某个依赖文件时可以自动搜索到简洁又快捷
target=app
$(target):$(objs)
	$(CC) $(objs) -o $(target)

%.o:%.c
	$(CC) -c $< -o $@

.PHONY:clean 
clean:
	rm $(objs) -f # 删除所有生成的.o依赖文件;-f 强制删除

# 后面的规则都是为第一条规则服务的，可以在bash中make clean随时执行clean命令，
# 但是如果Makefile路径下有一个时间比较新的clean文件,clean命令后面没有依赖文件，因此时间是比较老的
# 这时在bash中make clean就会提示clean已经是最新的了，clean命令就不能执行了
# 因此需要.PYONY声明一下clean是伪目标，意思不会生成目标文件
```

拷贝到Makefile:

    cp Makefile5 Makefile

make一下，执行命令：

```
cc -c mult.c -o mult.o
cc -c main.c -o main.o
cc -c add.c -o add.o
cc -c div.c -o div.o
cc -c sub.c -o sub.o
cc  ./mult.o  ./main.o  ./add.o  ./div.o  ./sub.o  -o app
```

没有执行rm $(objs) -f命令，因为后面的规则都是为第一条规则服务的

可以在bash中调用指定命令：make clean

    rm  ./add.o  ./mult.o  ./main.o  ./div.o  ./sub.o  -f # 删除所有生成的.o依赖文件;-f 强制删除

> 不是第一条规则依赖的规则，就可以在bash中执行了，持续make clean命令都是可以正常执行的

如果在Makefile同一路径下执行touch clean，会创建一个clean的文件，此时make clean就会发现提示：

    make: 'clean' is up to date.

> clean命令是没有依赖文件的，因此时间是比较老的时间，touch clean的时机又是比较新的，touch clean之后，clean文件的时机太新了，因此clean就不再执行了

此时就需要.PHONY声明clean是伪目标，意思不会生成文件

此时再在bash中make clean，就可以正常调用clean命令了：

    rm  ./add.o  ./mult.o  ./main.o  ./div.o  ./sub.o  -f # 删除所有生成的.o依赖文件;-f 强制删除

