#include <fstream>
#include <iostream>
#include "studentlist.h"
#include <iomanip>
#include <cstring>
#include "student.h"
using namespace std;

StudentList :: StudentList()
{
	size = 0;
	list = nullptr;
}
StudentList :: ~StudentList()
{
	for(int i = 0; i<size; i++)
	{
		delete list[i];
	}
	delete[] list;
}

bool StudentList :: CreateReportFile(const char* filename)
{
	ofstream outFile;
	outFile.open(filename);
	if (!outFile) 
	{
    		return false;
	}
	outFile<< "Student Grade Summary"<<endl;
	outFile << "----------------------------------------------------------------------" << endl;
	outFile << endl;
	//3 for loops
	outFile << "ENGLISH CLASS"<<endl;
	outFile << endl;
	outFile << left
		<< setw(42) << "Student Name"
		<< setw(6) << "Final"
		<< setw(8) << "Final"
		<< setw(8) << "Letter"
		<<endl;
	outFile << left
		<< setw(42) << ""
		<< setw(6) << "Exam"
		<< setw(8) << "Avg"
		<< setw(8) << "Grade"
		<< endl;
	outFile << "----------------------------------------------------------------------" << endl;
	int numA = 0;
	int numB = 0;
	int numC = 0;
	int numD = 0;
	int numF = 0;
	for(int i = 0; i<size; i++)
	{
		if(strcmp(list[i]-> getCourseName(), "English")==0)
		{
				string fullName = string(list[i]->getFirstName()) + " " + list[i]->getLastName();
				outFile << left
        			<< setw(42) << fullName
				<< setw(6) << list[i] -> getFinalExam();
				outFile<<fixed<<setprecision(2);
				outFile<< setw(8) << list[i] -> ComputeGrade();
			if(list[i] -> ComputeGrade() >= 90)
			{
				outFile << left
					<< setw(8)
					<< "A" << endl;
				numA++;
			}
			else  if(list[i] -> ComputeGrade() >= 80)
                        {              
                                outFile << left
                                        << setw(8)
                                        << "B" << endl;
				numB ++;
                        }
			else if(list[i] -> ComputeGrade() >= 70)
                        {              
                                outFile << left
                                        << setw(8)
                                        << "C" << endl;
				numC++;
                        }
			else  if(list[i] -> ComputeGrade() >= 60)
                        {   
                                outFile << left
                                        << setw(8)
                                        << "D" << endl;
				numD ++;
                        }
			else
			{
				outFile << left
					<< setw(8)
					<< "F" << endl;
				numF ++;
			}
		} 
	}

	outFile << "HISTORY CLASS"<<endl;
        outFile << endl;
        outFile << left
                << setw(42) << "Student Name"
                << setw(6) << "Final"
                << setw(8) << "Final"
                << setw(8) << "Letter"
                <<endl;
        
        outFile << left
                << setw(42) << ""
                << setw(6) << "Exam"
                << setw(8) << "Avg"
                << setw(8) << "Grade"
                << endl;
	outFile << "----------------------------------------------------------------------" << endl;
	for(int i = 0; i<size; i++)
        {
                if(strcmp(list[i]-> getCourseName(), "History") == 0)
                {
                        string fullName = string(list[i]->getFirstName()) + " " + list[i]->getLastName();
			outFile << left
        			<< setw(42) << fullName
                                << setw(6) << list[i] -> getFinalExam();
				outFile<<fixed<<setprecision(2);
                                outFile<< setw(8) << list[i] -> ComputeGrade();
                        if(list[i] -> ComputeGrade() >= 90)
                        {
                                outFile << left
                                        << setw(8)
                                        << "A" << endl;
				numA ++;
                        }
                        else  if(list[i] -> ComputeGrade() >= 80)
                        {              
                                outFile << left
                                        << setw(8)
                                        << "B" << endl;
				numB ++;
                        }
                        else if(list[i] -> ComputeGrade() >= 70)
                        {              
                                outFile << left
                                        << setw(8)
                                        << "C" << endl;
				numC ++;
                        }
                        else  if(list[i] -> ComputeGrade() >= 60)
                        {              
                                outFile << left
                                        << setw(8)
                                        << "D" << endl;
				numD ++;
                        }
                        else
                        {
                                outFile << left
                                        << setw(8)
                                        << "F" << endl;
				numF ++;
                        }
 
                } 
        }
	outFile << "MATH CLASS"<<endl;
        outFile << endl;
        outFile << left
                << setw(42) << "Student Name"
                << setw(6) << "Final"
                << setw(8) << "Final"
                << setw(8) << "Letter"
                <<endl;
        
        outFile << left
                << setw(42) << ""
                << setw(6) << "Exam"
                << setw(8) << "Avg"
                << setw(8) << "Grade"
                << endl;
	outFile << "----------------------------------------------------------------------" << endl;
	  for(int i = 0; i<size; i++)
        {
                if(strcmp(list[i]-> getCourseName(), "Math") == 0)
                {
                        string fullName = string(list[i]->getFirstName()) + " " + list[i]->getLastName();
			outFile << left
        			<< setw(42) << fullName
                                << setw(6) << list[i] -> getFinalExam();
				outFile << fixed << setprecision(2);
                                outFile << setw(8) << list[i] -> ComputeGrade();
                        if(list[i] -> ComputeGrade() >= 90)
                        {
                                outFile << left
                                        << setw(8)
                                        << "A" << endl;
				numA++;
                        }
                        else  if(list[i] -> ComputeGrade() >= 80)
                        {              
                                outFile << left
                                        << setw(8)
                                        << "B" << endl;
				numB ++;
                        }
                        else if(list[i] -> ComputeGrade() >= 70)
                        {              
                                outFile << left
                                        << setw(8)
                                        << "C" << endl;
				numC ++;
                        }
                        else  if(list[i] -> ComputeGrade() >= 60)
                        {             
                                outFile << left
                                        << setw(8)
                                        << "D" << endl;
				numD ++;
                        }
                        else
                        {
                                outFile << left
                                        << setw(8)
                                        << "F" << endl;
				numF ++;
                        }
		
                } 
        }
	outFile<<endl<<endl;
	outFile<<"OVERALL GRADE DISTRIBUTION"<<endl<<endl;
	outFile<<"A: "<<"     "<<numA<<endl;
	outFile<<"B: "<<"     "<<numB<<endl;
	outFile<<"C: "<<"     "<<numC<<endl;
	outFile<<"D: "<<"     "<<numD<<endl;
	outFile<<"F: "<<"     "<<numF<<endl;
	return true;
	// firstName space lastName 20 spaces finalExam space finalAverage space LetterGrade
}
void StudentList::ShowList() const
{
    for (int i = 0; i < size; i++)
    {
        cout << left
             << setw(20) << list[i]->getLastName()
             << setw(20) << list[i]->getFirstName()
             << setw(12) << list[i]->getCourseName()
             << endl;
    }
}
bool StudentList :: ImportFile(const char* filename)
{
	ifstream inFile;
	inFile.open(filename);
	if(!inFile)
		return false;
	int numStudents;
	inFile>>numStudents;
	inFile.ignore(1000, '\n');

	Student ** newList = new Student*[size+numStudents];
	for(int i = 0; i<size; i++)
	{
		newList[i] = list[i];
	}
	for(int i = 0; i<numStudents; i++)
	{
		//list[i] is a pointer to Student
		char last[21], first[21];
		inFile.getline(last, 21, ',');
		inFile.getline(first, 21, '\n');
		if (first[0] == ' ') //making sure first doesn't start with a space 
		{
    			for (int j = 0; first[j]; j++) 
			{
        			first[j] = first[j + 1];
    			}
		}
		char course[20];
		inFile >> course;
		if(strcmp(course, "English") == 0)
		{
			double a, p, m, f;
			inFile >> a >> p >> m >> f;
			newList[size + i] = new English(first, last, a,p,m,f);
			cout<<first<<" "<<last<<" "<<course<<endl;
		}
		else if(strcmp(course, "Math")==0)
		{
			double q1, q2, q3, q4, q5, t1, t2, f;
			inFile >> q1 >> q2 >> q3 >> q4 >> q5 >> t1 >> t2 >> f;
			newList[size + i] = new Math(first, last, q1, q2, q3, q4, q5, t1, t2, f);
			cout<<first<<" "<<last<<" "<<course<<endl;
		}
		else if(strcmp(course, "History")==0)
		{
			double tp, mt, fe;
			inFile >> tp >> mt >> fe;
			newList[size + i] = new History(first, last, tp, mt, fe);
			cout<<first<<" "<<last<<" "<<course<<endl;
		}
		else //if the input file is wrong
		{
			newList[size + i] = new History(first, last, 0, 0, 0);
		}
		if (inFile.peek() == '\n') 
		{
    			inFile.ignore();
		} //this is essential, don't remove it
	}
	delete [] list;
	list = newList;
	size += numStudents;
	for (int i = 0; i < size; i++) 
        {
                cout << list[i]->ComputeGrade() << endl;
        }

	return true;
}






