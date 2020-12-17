#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>

#define MYPORT  8887
#define QUEUE   20
#define BUFFER_SIZE 1024

#define CONNECT_NUM_MAX   10
int main()
{
	int maxsock = 0;
	fd_set client_fdset;        //监听文件描述符集合
	struct timeval timeout;     //超时时间
	int client_fd[CONNECT_NUM_MAX] = {0};     //已连接客户端套接字
	int connectcount = 0;       //描述符数量
	char buff[BUFFER_SIZE];
	int ret = 0;
	//定义sockfd
	int serverfd = socket(AF_INET,SOCK_STREAM, 0);
	maxsock = serverfd;

	///定义sockaddr_in
	struct sockaddr_in server_sockaddr;
	server_sockaddr.sin_family = AF_INET;
	server_sockaddr.sin_port = htons(MYPORT);
	server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	// 设置套接字选项避免地址使用错误
	int on = 1;
	if(setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on))){
		perror("setsockopt failed");
		exit(EXIT_FAILURE); 
	}
	///bind，成功返回0，出错返回-1
	if(bind(serverfd,(struct sockaddr *)&server_sockaddr,sizeof(server_sockaddr))==-1)
	{
		perror("bind");
		exit(1);
	}

	///listen，成功返回0，出错返回-1
	if(listen(serverfd,QUEUE) == -1)
	{
		perror("listen");
		exit(1);
	}
	while(1){
		printf("start\n");
		FD_ZERO(&client_fdset);             //初始化集合
		FD_SET(serverfd,&client_fdset);     //将该描述符加入到描述符集合中
		timeout.tv_sec = 30; 
		timeout.tv_usec = 0;

		//将可能存在的描述符加入监听
		for(int i = 0;i<CONNECT_NUM_MAX;i++){
			if(client_fd[i] != 0){
				printf("FD_SET:i:%d, %d\n",i, client_fd[i]);
				FD_SET(client_fd[i],&client_fdset);
			}
		}
		/*select只监听可读状态*/
		ret = select(maxsock+1,&client_fdset,NULL,NULL,NULL);
		printf("select ret:0x%x\n",ret);
		if(ret == -1) break;
		else if(ret == 0){
			printf("timeout\n");
			continue;
		}

		//遍历已经连接描述符，检查是否有可都状态
		for(int i = 0; i < CONNECT_NUM_MAX; i++){
			//判断当前描述符是否加入监视集合
			if(FD_ISSET(client_fd[i],&client_fdset)){
				memset(buff, 0, sizeof(buff));
				int len = recv(client_fd[i],buff,1024,0);
				printf("recv_fd:%d ,len %d\n",client_fd[i], len);
				if(len <= 0){
					printf("close:i:%d, %d\n",i, client_fd[i]);
					close(client_fd[i]);
					client_fd[i] = 0;
					connectcount--;
					break;
				}else{
					fputs(buff, stdout);
					if(strcmp(buff,"exit\n")==0){
						printf("close:i:%d, %d\n",i, client_fd[i]);
						close(client_fd[i]);
						client_fd[i] = 0;
						connectcount--;
						break;
					}
					send(client_fd[i], buff, len, 0);
					printf("send: %s\n",buff);
				}
			}  

		}
		//检查是否有新的连接
		if(FD_ISSET(serverfd,&client_fdset)){
			struct sockaddr_in  addr_cl;
			socklen_t  socksize = sizeof(struct sockaddr_in);
			int sockclient = accept(serverfd,(struct sockaddr*)&addr_cl,&socksize);
			if(sockclient <= 0){
				printf("accept err!");
				continue;
			}
			if(connectcount < CONNECT_NUM_MAX){
				connectcount++;
				for(int i = 0;i<CONNECT_NUM_MAX;i++){
					if(client_fd[i] == 0){
						client_fd[i] = sockclient; //保存新连接，方便加入描述符集合
						break;
					}
				}
				bzero(buff,1024);
				strcpy(buff,"this is server! welcome!\n");
				send(sockclient,buff,1024,0);

				if(sockclient > maxsock){
					maxsock = sockclient;   //记录最大套接字描述符
				}
			}
		}
	}
	
	for(int i = 0;i<CONNECT_NUM_MAX;i++){
		if(client_fd[i] != 0){
			close(client_fd[i]);
		}
	}
	close(serverfd);
	return 0;
}

