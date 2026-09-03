#include <iostream>
#include <fstream>
#include <cctype>
#include "studentlist.h"
#include "student.h"
using namespace std;

int main()
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
	while(choice != 'Q')
	{
		cout<<"enter choice ";
		cin>>choice;

		choice = toupper(choice);
		switch(choice)
		{
			case 'I':
			{
				char filename[31];
				cout<<"Enter a file name";
				cin>>filename;
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
				cin>>filename;

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
			default:
				cout<< "Invalid choice, please try again"<<endl;
		}
	}
	return 0;
}
