/*
=====================
	MACROS
=====================
*/
#define NO_TYPE 0
#define C_TYPE 1
#define CPP_TYPE 2
#define UNABLE_TO_CREATE 3
#define ARGC 4
#define FILE_LOCATION 5
#define APP_LOCATION 6
#define INVALID_TYPE 7
#define APP_OPEN 8
#define HEADER_FILE 9
#define MAIN_FUNC 10
#define COUNT_FILE_ERROR 11
#define INCREMENT_ERROR 12

/*
=====================
	INCLUDES
======================
*/

using namespace std;

#include<errno.h>
#include<fcntl.h>
#include<fstream>
#include<ios>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<time.h>
#include<unistd.h>

/*
====================
	FUNCTIONS
====================
*/

int findExtension(char*);
void openUsingApplication(string command);
bool searchFile(string, string);
void createFile(string, string, string);
void fillHeaders(ofstream&);
void printErr(int);
void incrementCount();
string currentDateTime();
void welcome();

const string home(getenv("HOME"));
const string PWD(home+"/code-kick-starter");

