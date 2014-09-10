#include"headers.h"

/*
================================
	PRINTING ERROR MESSAGES
================================
*/

void printErr(int error_code)
{
	switch(error_code)
	{
		case UNABLE_TO_CREATE:

			fprintf(stderr, "Unable to create file!\nExiting..\n");
			exit(EXIT_FAILURE);

			break;

		case ARGC:

			fprintf( stderr, "Invalid parameters. Usage: <code> <filename><extension (optional)>\nRestart The Application. Exiting..\n");
			exit(EXIT_FAILURE);
			
			break;

		case FILE_LOCATION:

			fprintf(stderr,"Error finding default file location!\nExiting..\n");
			exit(EXIT_FAILURE);
			break;

		case APP_LOCATION:

			fprintf(stderr,"Error finding application location!\nExiting..\n");
			exit(EXIT_FAILURE);
			break;

		case INVALID_TYPE:
		
			fprintf(stderr, "Invalid File Type! Exiting..\n");
			exit(EXIT_FAILURE);
			break;

		case APP_OPEN:
			
			fputs("Error opening file using application!\nExiting..\n", stderr);
			exit(EXIT_FAILURE);
			break;

		case HEADER_FILE:

			fputs("Error retreiving header file defaults!\nExiting..\n", stderr);
			exit(EXIT_FAILURE);
			break;

		case MAIN_FUNC:

			fputs("Error retreiving main function template from file!\nExiting..\n", stderr);
			exit(EXIT_FAILURE);
			break;

		case COUNT_FILE_ERROR:
		case INCREMENT_ERROR:

			fputs("Error accessing the configuration files.\n", stderr);
			exit(EXIT_FAILURE);
			break;

		default:
			exit(EXIT_FAILURE);
	}
}



