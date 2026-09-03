#include<iomanip>
class Student;
class StudentList
{
public:
   StudentList();		// starts out empty
   ~StudentList();		// cleanup (destructor)

   bool ImportFile(const char* filename);
   bool CreateReportFile(const char* filename);
   void ShowList() const;	// print basic list data

private:
	int size;
	Student ** list;
};

