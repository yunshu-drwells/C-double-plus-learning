#include <iostream>
using namespace std;

#define __THROW_BAD_ALLOC  cerr << "out of memory" << endl; exit(1)

template <int inst>
class __malloc_alloc_template{
private:
	static void* oom_malloc(size_t);
	static void* oom_realloc(void*, size_t);
	static void (*__malloc_alloc_oom_handler)();
public:
	static void* allocate(size_t n)	{
		void* result = malloc(n);
		if (0 == result)
			result = oom_malloc(n);  //out of memory malloc
		return result;
	}
	static void deallocate(void* p, size_t /* n */)	{
		free(p);
	}
	static void* reallocate(void* p, size_t /* old_sz */, size_t new_sz)		{
		void* result = realloc(p, new_sz);
		if (0 == result)
			result = oom_realloc(p, new_sz);
		return result;
	}
	static void(*set_malloc_handler(void(*f)()))()
	{
		void(*old)() = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;
		return(old);
	}

};

template <int inst>
void* __malloc_alloc_template<inst>::oom_malloc(size_t n) {
	void (*my_malloc_handler)();
	void* result;

	for (;;){
		my_malloc_handler = __malloc_alloc_oom_handler;
		if (0 == my_malloc_handler)
			__THROW_BAD_ALLOC; //throw bad_alloc();
		(*my_malloc_handler)();
		result = malloc(n);
		if (result)	return(result);
	}
}
template <int inst>
void* __malloc_alloc_template<inst>::oom_realloc(void* p, size_t n) {
	void (*my_malloc_handler)();
	void* result;

	for (;;)	{
		my_malloc_handler = __malloc_alloc_oom_handler;
		if (0 == my_malloc_handler)
			__THROW_BAD_ALLOC;
		(*my_malloc_handler)();
		result = realloc(p, n);
		if (result) return(result);
	}
}
template <int inst>
void (*__malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = 0;

int main() {
	/*int* p = (int*)__malloc_alloc_template<0>::allocate(sizeof(int));

	__malloc_alloc_template<0>::reallocate(p, sizeof(int), sizeof(int) * 10);
	__malloc_alloc_template<0>::deallocate(p, sizeof(int) * 10);*/


	//申请失败的情形：
	int* p2 = (int*)__malloc_alloc_template<0>::allocate(sizeof(int) * 536870911);  //(2^32 / 4) / 2 = 536870912

	return 0;
}

#if 0
//异常处理版本
#include<iostream>
using namespace std;

//#define __THROW_BAD_ALLOC  cerr << "out of memory" << endl; exit(1)
#define __THROW_BAD_ALLOC throw bad_alloc

template <int inst>
class __malloc_alloc_template
{
private:
	static void* oom_malloc(size_t);
	static void* oom_realloc(void*, size_t);
	static void (*__malloc_alloc_oom_handler)();

public:
	static void* allocate(size_t n)
	{
		void* result = malloc(n);
		if (0 == result)
			result = oom_malloc(n);  //out of memory malloc
		return result;
	}
	static void deallocate(void* p, size_t /* n */)
	{
		free(p);
	}
	static void* reallocate(void* p, size_t /* old_sz */, size_t new_sz)
	{
		void* result = realloc(p, new_sz);
		if (0 == result)
			result = oom_realloc(p, new_sz);
		return result;
	}
public:
	static void(*set_malloc_handler(void(*f)()))()
	{
		void(*old)() = __malloc_alloc_oom_handler;
		__malloc_alloc_oom_handler = f;
		return(old);
	}
};

template<int inst>
void (*__malloc_alloc_template<inst>::__malloc_alloc_oom_handler)() = 0;

template<int inst>
void* __malloc_alloc_template<inst>::oom_malloc(size_t n)
{
	void (*my_malloc_handler)();
	void* result;

	for (;;)
	{
		my_malloc_handler = __malloc_alloc_oom_handler;
		if (0 == my_malloc_handler)
		{
			__THROW_BAD_ALLOC(); //throw bad_alloc();
		}
		(*my_malloc_handler)();
		result = malloc(n);
		if (result)
			return(result);
	}
}

template<int inst>
void* __malloc_alloc_template<inst>::oom_realloc(void* ptr, size_t)
{
	void (*my_malloc_handler)();
	void* result;

	for (;;)
	{
		my_malloc_handler = __malloc_alloc_oom_handler;
		if (0 == my_malloc_handler)
		{
			__THROW_BAD_ALLOC;
		}
		(*my_malloc_handler)();
		result = realloc(p, n);
		if (result)
			return(result);
	}
}

void Out_Of_Memory()
{
	cout << "Out Of Memory." << endl;
	//GC /*垃圾回收器*/
	exit(1);
}
int main()
{
	//set_new_handler;
	__malloc_alloc_template<0>::set_malloc_handler(Out_Of_Memory);
	try
	{
		int* p = (int*)__malloc_alloc_template<0>::allocate(sizeof(int) * 536870911); //malloc(sizeof(int));
	}
	catch (const bad_alloc & e)
	{
		cout << "bad_alloc catched" << endl;
		return;
	}
	return 0;
}
#endif

