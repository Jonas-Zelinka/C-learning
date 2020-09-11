#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#define LINEBUFF 256
#define NAME 200
//////////////////////////////////////////////////////////
//	Void´s						//
//////////////////////////////////////////////////////////
static void error_exit( char *errormessage ) {
    fprintf (stderr, "\n %s ; %s \n", errormessage, strerror(errno));
    exit(EXIT_FAILURE); }
//////////////////////////////////////////////////////////
//	MAIN						//
//////////////////////////////////////////////////////////
int main( int argc, char *argv[] )
{//   MAIN START
char buff[LINEBUFF];

char name[NAME],fname[NAME];
int day,month,year;
FILE *fd;
char path[]=".test.txt";
fd= fopen(path,"r");
// read line by line till end
printf("\n");
while(fgets(buff,LINEBUFF,fd) != NULL)
	{
	printf("DATA: %s",buff);
	}
fclose(fd);

fd= fopen(path,"r");
// read word by word
printf("\n now read word by word ...\n");
while( fscanf(fd,"%d %d %d %s %s",&month,&day,&year,&name,&fname) != -1) // print till end
	{
	printf("DATA: %02d %02d %04d %s %s\n",month,day,year,name,fname);
	}
fclose(fd);
printf("\n");
}//   MAIN END
