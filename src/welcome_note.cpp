
#include"headers.h"
/*

	This function accounts for the "Welcome Note" of the program.
*/

void giveIntro();

void welcome()
{

	int cnt;

	//open the count file.
	FILE*  fp = fopen((PWD + "/Config/counts.txt").c_str(),"r+");
	
	//file error check.
	if(!fp)
		printErr(COUNT_FILE_ERROR);
	
	//incrementing the count.
	if(fscanf(fp, "%d", &cnt))
	{
		if(cnt==0)
		{
			giveIntro();
		}

	}

	else
	printErr(COUNT_FILE_ERROR);
}


/*
=====================================
GET INSTALLATION DETAILS FROM USER
=====================================
*/
/*
void getDetails()
{
	string
	app_name, def_folder_name, abs_path;

	//print welcome note
	welcomeNote();

	//Getting Application Name.
	printf("Enter name of default application/IDE with which you want to open C/C++ files. :");
	cin>>app_name;
	cout<<app_name;

	//Getting storage folder name.
	printf("Enter absolute path of location where you would want files to be stored. End it with '/':");
	cin>>def_folder_name;
	cout<<def_folder_name;

	//Getting absolute path of code-kick-starter folder.
	printf("Enter absolute path of permanent location where \"code-kick-starter\" folder is stored. End it with '/':");
	cin>>abs_path;
	cout<<abs_path;
	

=========================
IMPLEMENTING ALL CHANGES
=========================



	//APPLICATION NAME
	cout<<"Storing Application name.."<<endl;
	int common_fptr = open((abs_path + "Config/application_kick_starter.txt").c_str(), O_WRONLY, O_RDWR);

	if(common_fptr==-1)
	printErr(APP_LOCATION);

	if(write(common_fptr, (const char*)app_name.c_str(), app_name.size())==-1)
	{
		fprintf(stderr, "Failed to update application name. Contact pc.mayank@gmail.com stating the error.\n");
		exit(1);
	}

	//Job Done. Closing File.
	close(common_fptr);
	cout<<"Done!"<<endl;


	//STORAGE FOLDER NAME
	cout<<"Storing default folder location name.."<<endl;
	common_fptr = open((abs_path + "Config/folder_kick_starter.txt").c_str(), O_WRONLY, O_RDWR);

	if(common_fptr==-1)
	printErr(FILE_LOCATION);

	if(write(common_fptr, (const char*)def_folder_name.c_str(), def_folder_name.size())==-1)
	{
		fprintf(stderr, "Failed to store storage location. Contact pc.mayank@gmail.com stating the error.\n");
		exit(1);
	}

	//Job Done. Closing File.
	close(common_fptr);
	cout<<"Done!"<<endl;


	//PWD modification. The MOST difficult task! :P
	puts("PWD done later. done now!");
}
*/

void giveIntro()
{
	//opening Welcome.txt..
	char line[300];
	FILE*  fp = fopen((PWD + "/Welcome.txt").c_str(),"r+");

	//printing everything out..
	while( fscanf(fp, "%s", line) != EOF )
	{
		puts(line);
	}

	puts("");
}		
