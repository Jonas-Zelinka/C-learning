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




}//   MAIN END
