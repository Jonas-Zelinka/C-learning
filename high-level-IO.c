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
#define LINEBUFF 256	//define buffer length for one line
#define NAME 200	//define buffer length for one Name
//////////////////////////////////////////////////////////
//	Void´s						//
//////////////////////////////////////////////////////////
static void error_exit( char *errormessage ) {	// error checking function
    fprintf (stderr, "\n %s ; %s \n", errormessage, strerror(errno));
    exit(EXIT_FAILURE); }
//////////////////////////////////////////////////////////
//	MAIN						//
//////////////////////////////////////////////////////////
int main( int argc, char *argv[] )
{//   MAIN START
char buff[LINEBUFF]; // declare buffer for one hole Line

char name[NAME],fname[NAME]; // declare name buffer and second name buffer
int day,month,year;		// declare int types for date,
FILE *fd;	//file descriptor
char path[]=".test.txt";	// path to file...
fd= fopen(path,"r");		// open file with "Read" permissions
// read line by line till end
printf("\n"); // space
while(fgets(buff,LINEBUFF,fd) != NULL) // write line by line in buff with length="LINEBUFF" from file descriptor "fd" till the end of file "!= NULL"
	{
	printf("DATA: %s",buff); // Print one hole line (buff)
	}
fclose(fd); // close file descriptor

fd= fopen(path,"r"); // open file descriptor again with "Read" permissions
// read word by word
printf("\n now read word by word ...\n");
while( fscanf(fd,"%d %d %d %s %s",&month,&day,&year,&name,&fname) != -1) // print till end
	{	// copie every word in a diffrent buffer (perfekt for Date programms and so on)
	printf("DATA: %02d %02d %04d %s %s\n",month,day,year,name,fname); // print Date
	}
fclose(fd);	// close file descriptor
printf("\n");	// space
}//   MAIN END
