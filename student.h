#include<iomanip>
class Student //this is the parent class
{
protected:
        enum Course {ENGLISH, HISTORY, MATH};
        char firstName[21];
        char lastName[21];
        Course course;

public:
        Student(const char* first, const char* last, Course c);
        virtual double ComputeGrade() const = 0;
        virtual double getFinalExam() const;
        virtual ~Student();
        const char* getCourseName() const;
        const char* getFirstName() const;
        const char* getLastName() const;
};
class English: public Student
{
public:
        English(const char* fs, const char* ls, double a, double p, double m, double f);
        double ComputeGrade() const;
        double getFinalExam() const;
private:
        double attendance;
        double project;
        double midterm;
        double finalExam;
};
class History: public Student
{
public:
        History(const char * fs, const char * ls, double t, double m, double f); 
        double ComputeGrade() const;
        double getFinalExam() const;
private:
        double termPaper;
        double midTerm;
        double finalExam;
};
class Math: public Student
{
public:
        Math(const char * fs, const char * ls, double q1, double q2, double q3, double q4, double q5, double t1, double t2, double f);
        double ComputeGrade() const;
        double getFinalExam() const;
private:
        double quiz1;
        double quiz2;
        double quiz3;
        double quiz4;
        double quiz5;
        double test1;
        double test2;
        double finalExam;
};


