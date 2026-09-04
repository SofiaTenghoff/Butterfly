#include <fstream>
#include <iostream>
#include "student.h"
#include <iomanip>
#include <cstring>
using namespace std;
Student :: Student(const char* fs, const char* ls, Course c) //Student is an a>
{
        strncpy(firstName, fs, 20);
        firstName[20] = '\0';
        strncpy(lastName, ls, 20);
        lastName[20] = '\0';
        course = c;
}
const char* Student :: getCourseName() const
{
        switch(course)
        {
                case ENGLISH: return "English";
                case HISTORY: return "History";
                case MATH: return "Math";
        }
        return "";
}
const char* Student :: getFirstName() const
{
        return firstName;
}
const char* Student :: getLastName() const
{
        return lastName;
}
double Student::getFinalExam() const
{
    return 0;  // default (won\xE2t really be used)
}
History :: History(const char* fs, const char* ls, double t, double m, double f ) : Student(fs, ls, HISTORY)
{
        termPaper = t;
        midTerm = m;
        finalExam = f;
}
Math :: Math(const char * fs, const char * ls, double q1, double q2, double q3, double q4, double q5, double t1, double t2, double f) : Student(fs, ls, MATH)
{
        quiz1 = q1;
        quiz2 = q2;
        quiz3 = q3;
        quiz4 = q4;
        quiz5 = q5;
        test1 = t1;
        test2 = t2;
        finalExam = f;
}
/* Math(char * fs, char * ls, double q1, double q2, double q3, double q4, double q5, double t1, double t2, double f);
        double ComputeGrade() const;
*/

English :: English(const char* fs, const char* ls, double a, double p, double m, double f) : Student(fs, ls, ENGLISH)
{
        attendance = a;
        project = p;
        midterm = m;
        finalExam = f;
}
double English :: ComputeGrade() const
{
        double finalGrade = attendance*0.10 + project*0.30 + midterm*0.30 + finalExam*0.30;
        return finalGrade;
}
double History :: ComputeGrade() const
{
        return termPaper*0.25 + midTerm*0.35 + finalExam*0.40;
}
double Math :: ComputeGrade() const
{
        double quizAverage = quiz1 + quiz2 + quiz3 + quiz4 + quiz5;
        quizAverage /= 5;
        double finalGrade = (quizAverage * 0.15) + test1*0.25 + test2*0.25 + finalExam*0.35;
        return finalGrade;
}


double English :: getFinalExam() const
{
        return finalExam;
}
double Math :: getFinalExam() const
{
        return finalExam;
}
double History :: getFinalExam() const
{
        return finalExam;
}
Student :: ~Student() {}


