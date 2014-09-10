/*
	==================================
		CODE-KICK-STARTER!!
	==================================

	Creator: Mayank Bhura
	Email: pc.mayank@gmail.com
	Institute: NIT Karnataka
	Language: C++
	Date: 10.08.2014

*/

/*
=====================
	INCLUDES
======================
*/

#include"headers.h"

/*
============================
	GLOBAL VARIABLES
============================
*/

string filename;
int extension;

/*
===========================
	START OF PROGRAM
===========================
*/

int main(int argc, char* argv[])
{
	int
	error;

	string
	folder, application, temp;

	welcome();
/*
=================================
	CHECK FOR VALID ARGC
=================================
*/

	if(argc!=2)
	printErr(ARGC);

/*
==================================================
	FETCHING DEFAULT FILE LOCATION
==================================================
*/

	ifstream folder_location((PWD + "/Config/folder_kick_starter.txt").c_str());
	
	//error case:
	if(!folder_location.is_open())
		printErr(FILE_LOCATION);

	//fetching folder location from file's first line.
	if(!getline(folder_location, folder))
		printErr(FILE_LOCATION);


	//if "folder" variable contains env variable, substitute it.
	size_t envPart = folder.find("$HOME");

	if(envPart!=string::npos)
	{
		folder.replace(envPart, 5, (string)getenv("HOME"));
	}


/*
===============================================
	FETCHING DEFAULT APPLICATION LOCATION
===============================================
*/

	ifstream app_location((PWD + "/Config/application_kick_starter.txt").c_str());

	//error case:
	if(!app_location.is_open())
		printErr(APP_LOCATION);

	//fetching application location from file's first line.
	if(!getline(app_location, application))		
		printErr(APP_LOCATION);			

	application = application + " ";

/*
=======================================================
	SEARCHING FOR EXISTING FILE/CREATING NEW FILE
=======================================================
*/

	//check for file extension.
	extension = findExtension(argv[1]);
	filename=argv[1];
	
	switch(extension)
	{
		case NO_TYPE:

			//try for both extensions.
			if( searchFile(folder, temp = filename+".c") || searchFile(folder, temp = filename+".cpp") )
			{
				filename = temp;

				//file exists. open using application.
				openUsingApplication(application + folder + temp);
			}

			//file not found. create file using .cpp extension.
			else
			{
				filename = temp;
				
				//create file.
				createFile(folder, filename, application);
			}
				
			break;

		case C_TYPE:
			
			//search for existing file.
			if(searchFile(folder, filename))
			{
				//file existent. open using application
				openUsingApplication(application + folder + filename);
			}
			
			//not found. create file using .c extension
			else
			createFile(folder, filename, application);

			break;
			
		case CPP_TYPE:
			
			//search for existing file.
			if(searchFile(folder, filename))
			{
				//file existent. open using application
				openUsingApplication(application + folder + filename);
			}

			//not found. create using .cpp extension.
			else
			createFile(folder, filename, application);

			break;

		case INVALID_TYPE:

			printErr(INVALID_TYPE);
	}

	return EXIT_SUCCESS;
}

/*
================================
	FINDING FILE EXTENSION
================================
*/

int findExtension(char* filename)
{
	int point = strlen(filename);

	if(strstr(filename, ".cpp") == (filename+point-4))
	return CPP_TYPE;

	if(strstr(filename, ".c") == (filename+point-2))
	return C_TYPE;

	if(strstr(filename, "."))
	return INVALID_TYPE;

	return NO_TYPE;
}

/*
================================
	SEARCHING FOR FILE
================================
*/

bool searchFile(string location, string filename)
{
	ifstream fp((location+filename).c_str());

	if(!fp.is_open())
	return false;
	
	fp.close();
	return true;
}

/*
================================
	CREATING NEW FILE
================================
*/

void createFile(string folder, string file, string application)
{
	//creating file.
	ofstream openFile((folder+file).c_str());

	//error case:
	if(!openFile.is_open())
	printErr(UNABLE_TO_CREATE);

	//fill in the headers.
	fillHeaders(openFile);

	//open using default application.
	openUsingApplication(application + folder + file);
}

/*
================================
    OPENING USING APPLICATION
================================
*/

void openUsingApplication(string command)
{
	incrementCount();

	if(system(command.c_str()) == -1)
		printErr(APP_OPEN);
}

/*
================================
	FILLING HEADER FILES
================================
*/

void fillHeaders(ofstream& file)
{
	int i;
	string line;
	ifstream header_content_file;

	//Filling according to extension.
	//Extension: .c
	if(extension == C_TYPE)
		header_content_file.open((PWD + "/HeaderTemplates/C_headers.txt").c_str(), std::ifstream::in);

	//Extension: .cpp
	else
	header_content_file.open((PWD + "/HeaderTemplates/CPP_headers.txt").c_str(), std::ifstream::in);

	//A check for file errors.
	if(!header_content_file.is_open())
		printErr(HEADER_FILE);

	while(getline(header_content_file, line))
		file<<line<<endl;

	//Opening the main() function template file
	ifstream main_template((PWD + "/MainTemplate/main_template.txt").c_str(), std::ifstream::in);

	//A check for file errors.
	if(!main_template.is_open())
		printErr(MAIN_FUNC);

	while(getline(main_template, line))
		file<<line<<endl;

	file.close();
}
