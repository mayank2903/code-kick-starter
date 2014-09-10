#include"headers.h"
extern string filename;

/*
===============================================
      INCREMENTING COUNT & ADDING TIMESTAMP
===============================================
*/

void incrementCount()
{	
	int count;

//COUNT INCREMENT

	//open the count file.
	FILE*  fp = fopen((PWD + "/Config/counts.txt").c_str(),"r+");

	//file error check.
	if(!fp)
		printErr(COUNT_FILE_ERROR);

	//incrementing the count.
	if(fscanf(fp, "%d", &count))
	{
		if(fseek(fp,0 , SEEK_SET)!=0)
			printErr(INCREMENT_ERROR);

		fprintf(fp, "%d", count+1);
	}

	//closing the file.
	fclose(fp);

//TIMESTAMP

	ofstream log((PWD+"/logs/logfile.txt").c_str(), ios::app);

    	log << currentDateTime() + " " + filename <<endl;
}

/*
=======================================================
Get current date/time, format is YYYY-MM-DD.HH:mm:ss
=======================================================
*/
string currentDateTime()
{

    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
