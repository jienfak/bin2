#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *argv0;

static void
usage(void)
{
	printf("Usage: %s\n", argv0);
}

 int
main(int argc, char *argv[])
{
	int n, siz;
	char type;
	TYPE buf[BUFSIZ];
	char *fmt;

	if( argc!=1 ){
		argv0 = argv[0] ;
		usage();
	}

	fmt = FORMAT ;
	siz = sizeof(TYPE) ;
	do{
		n = fread(buf, siz, BUFSIZ, stdin) ;
		if(n>0)
			for( int i=0 ; i<n ; ++i )
				printf(fmt, buf[i]);
	}while(n==sizeof buf);

	return 0 ;
}
