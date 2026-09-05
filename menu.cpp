#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include "studentlist.h"
#include "student.h"
using namespace std;

int main(int argc, char* argv[])
{
	StudentList studentlist;
	//printing the main menu
	char choice = '\0';
	cout<<"           *** Student List menu ***"<<endl;
	cout<<"I          Import students from a file"<<endl;
	cout<<"S          Show student list (brief)"<<endl;
	cout<<"E          Export a grade report (to file)"<<endl;
	cout<<"M          Show this Menu "<<endl;
	cout<<"Q          Quit Program"<<endl;

	cout << "You've entered " << argc << " arguments:\n";
	
	for(int i = 1; i < argc && choice != 'Q'; i++)
	{
		cout<<"enter choice ";

		choice = toupper(argv[i][0]);
		switch(choice)
		{
			case 'I':
			{
				char filename[31];
				//this is where they enter the file name
				++i;
				strcpy(filename, argv[i]);
				if(!studentlist.ImportFile(filename))
					cout<<"bad file, task not completed"<<endl;
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
				cout<<"Enter file name";
				strcpy(filename, argv[i]);
				++i;
				if(!studentlist.CreateReportFile(filename))
					cout<<"Error creating report file\n";
				else
					cout<<"Report successfully written to file";
			}
			break;
			case 'M':
			{
				cout<<"           *** Student List menu ***"<<endl;
			        cout<<"I          Import students from a file"<<endl;
        			cout<<"S          Show student list (brief)"<<endl;
        			cout<<"E          Export a grade report (to file)"<<endl;
        			cout<<"M          Show this Menu "<<endl;
        			cout<<"Q          Quit Program"<<endl;

			}
			break;	
			case 'Q':
			{
			}
			break;
			default:
				cout<< "Invalid choice, please try again"<<endl;
		}
	}
	return 0;
}
