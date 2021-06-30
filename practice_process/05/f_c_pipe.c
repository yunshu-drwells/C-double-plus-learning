//子进程只向管道写，父进程只从管道读
/*
创建出来的默认的文件描述符是阻塞的，不是非阻塞;
是因为管道读写规则，当管道没有数据可读时，read调用阻塞，因此子进程执行完成之前父进程read操作会阻塞
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#define ERR_EXIT(m) \
do \
{ \
perror(m); \
exit(EXIT_FAILURE); \
} while(0)
int main(int argc, char* argv[])
{
	int pipefd[2];
	if (pipe(pipefd) == -1)
		ERR_EXIT("pipe error");
	pid_t pid;
	pid = fork();
	if (pid == -1)
		ERR_EXIT("fork error");
	if (pid == 0) {
		// close(pipefd[0]);
		write(pipefd[1], "hello", 5);
		// close(pipefd[1]);
		printf("child write successed\n");
		exit(EXIT_SUCCESS);
	}
	// close(pipefd[1]);
	char buf[10] = { 0 };
	read(pipefd[0], buf, 10);
	printf("father read successed\n");
	printf("buf=%s\n", buf);
	return 0;
}