src=$(wildcard ./*.cpp)
objs=$(patsubst %.cpp, %.o, $(src))
target=app

$(target):$(objs)
	$(CXX) $(objs) -o $(target)

%.o:%.c
	$(CXX) -c $< -o $@

.PHONY:clean 
clean:
	rm $(objs) -f # 删除所有生成的.o依赖文件;-f 强制删除