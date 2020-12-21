#include <sys/types.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>




#define MYPORT  8887
#define BUFFER_SIZE 1024

#define STDIN_FD    0

int main()
{
	int fd_max = STDIN_FD;
	//stdin
	int stdin_fd = STDIN_FD;

	//定义sockfd
    int sock_fd = socket(AF_INET,SOCK_STREAM, 0);
	if(sock_fd > fd_max) fd_max = sock_fd;

	///定义sockaddr_in
 	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(MYPORT);  ///服务器端口
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  ///服务器ip

	///连接服务器，成功返回0，错误返回-1
	while (connect(sock_fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
		perror("connect");
		//exit(1);
		sleep(1);
	}

	//socket pair
	int sock_pair[2] = {-1};//R,W
	if(socketpair(AF_UNIX, SOCK_STREAM, 0, sock_pair) == -1 ){
		perror("Error, socketpair create failed, errno");
	}else{
		int opt;
		opt = fcntl(sock_pair[0], F_GETFL, 0);
		opt = fcntl(sock_pair[1], F_GETFL, 0);
		fcntl(sock_pair[0], F_SETFL, opt | O_NONBLOCK);
		fcntl(sock_pair[1], F_SETFL, opt | O_NONBLOCK);
		if(sock_pair[0] > fd_max) fd_max = sock_pair[0];
	} 
	
	//select
	fd_set fdset;

	printf("fd_max:%d, %d,%d,%d,%d\n",fd_max,stdin_fd,sock_fd, sock_pair[0], sock_pair[1]);
	char sendbuf[BUFFER_SIZE];
	char recvbuf[BUFFER_SIZE];
	while(1){
		FD_ZERO(&fdset); 
		FD_SET(stdin_fd, &fdset);
		FD_SET(sock_fd, &fdset);
		if(-1 != sock_pair[0]) FD_SET(sock_pair[0], &fdset);
		int ret = select(fd_max+1, &fdset, NULL, NULL, NULL);
		printf(">>ret:%d, %d,%d,%d\n",ret, FD_ISSET(stdin_fd, &fdset), FD_ISSET(sock_fd, &fdset), FD_ISSET(sock_pair[0], &fdset));
		if(FD_ISSET(stdin_fd, &fdset)){
			printf(">>stdin_fd\n");
			memset(sendbuf, 0, sizeof(sendbuf));
			int r_len = read(stdin_fd, sendbuf, sizeof(sendbuf));
			if(r_len > 0){
				printf("=======stdin:%s\n",sendbuf);
				send(sock_fd, sendbuf, strlen(sendbuf),0); ///发送
				if(-1 != sock_pair[1]) send(sock_pair[1], sendbuf, strlen(sendbuf), 0);
				if(strcmp(sendbuf,"exit\n")==0) break;
			}
		}
		if(FD_ISSET(sock_fd, &fdset)){
			printf(">>sock_fd\n");
			memset(recvbuf, 0, sizeof(recvbuf));
			int r_len = recv(sock_fd, recvbuf, sizeof(recvbuf),0); ///接收
			if(r_len <= 0){
				printf("clost fd, reconnect\n");
				close(sock_fd);
				sock_fd = socket(AF_INET,SOCK_STREAM, 0);
				while (connect(sock_fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
					perror("connect");
					//exit(1);
					sleep(1);
				}
				
			}else{
				printf("come service:%s\n",recvbuf);
			}
		}
		if(-1 != sock_pair[0] && FD_ISSET(sock_pair[0], &fdset)){
			printf(">>sock_pair read\n");
			memset(recvbuf, 0, sizeof(recvbuf));
			int r_len = recv(sock_pair[0], recvbuf, sizeof(recvbuf),0); ///接收
			if(r_len > 0){
				printf("come sock_pair:%s\n",recvbuf);
			}
		}

	}

	close(sock_fd);
	return 0;
}
