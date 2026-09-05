#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "studentlist.h"
#include "student.h"

using namespace std;
//command line instructions: First command: menu choice #1  Second command: filename if user chose 'I' or 'E', otherwise menu choice #2, and so on 
int main(int argc, char* argv[])
{
	StudentList studentlist;
	//printing the main menu
	
	char choice = '\0';
	/*
	cout<<"           *** Student List menu ***"<<endl;
	cout<<"I          Import students from a file"<<endl;
	cout<<"S          Show student list (brief)"<<endl;
	cout<<"E          Export a grade report (to file)"<<endl;
	cout<<"M          Show this Menu "<<endl;
	cout<<"Q          Quit Program"<<endl; */
	
	for(int i = 1; i < argc && choice != 'Q'; i++)
	{
		//command line argument gets read here

		choice = toupper(argv[i][0]);
		switch(choice)
		{
			case 'I':
			{
				char filename[31];
				// next command line argument, the filename, gets read here
				++i;
				strcpy(filename, argv[i]);
				if(!studentlist.ImportFile(filename))
					cerr<<"bad file, task not completed"<<endl;
			}
			break;
			case 'S':
			{
				studentlist.ShowList();
			}
			break;
			case 'E':
			{
				char filename[31];
				// next command line argument, the filename, gets read here
				++i;
				strcpy(filename, argv[i]);
				if(!studentlist.CreateReportFile(filename))
					cerr<<"Error creating report file\n";
				else
					cerr<<"Report successfully written to file";
			}
			break;
			case 'M':
			{
				/*cout<<"           *** Student List menu ***"<<endl;
			        cout<<"I          Import students from a file"<<endl;
        			cout<<"S          Show student list (brief)"<<endl;
        			cout<<"E          Export a grade report (to file)"<<endl;
        			cout<<"M          Show this Menu "<<endl;
        			cout<<"Q          Quit Program"<<endl;*/

			}
			break;	
			case 'Q':
			{
			}
			break;
			default:
				cerr<< "Invalid choice, please try again"<<endl;
		}
	}
	return 0;
}
