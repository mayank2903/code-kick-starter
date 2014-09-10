/*

	================================
		INSTALLATION FILE
	================================

	Tasks:
	1.Create folder $HOME/CKS_Sources
	2.Compile code-kick-starter.cpp and store the generated file into $HOME/code-kick-starter/bin/.
	3.Print statements to clarify procedure.

*/

#include<stdio.h>
#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

using namespace std;

int main()
{
	//Creating Folder.
	cout<<"Creating required folder..."<<endl;
	
	string sources[] = { "code-kick-starter.cpp", "error_msgs.cpp", "log_tasks.cpp", "welcome_note.cpp" }; 
	string src = "$HOME/code-kick-starter/src/";
	string files("");
	
	for(int i = 0; i<4; i++)
	{
		files+= src+sources[i]+" ";
	}

	if( system("mkdir $HOME/CKS_Sources") == -1)
	{
		fprintf(stderr, "Error creating required folders. Make sure you have root access.\n");
		exit(EXIT_FAILURE);
	}
	
	//Compile code.
	cout<<"Compiling source code..."<<endl;

	if( system( ("g++ " + files + "-o $HOME/code-kick-starter/bin/code").c_str()) == -1)
	{
		fprintf(stderr, "Error in compiling source files. Please make sure you have installed g++ and gcc.\n");
		exit(EXIT_FAILURE);
	}	

	puts("Installation Successful!!");
}
