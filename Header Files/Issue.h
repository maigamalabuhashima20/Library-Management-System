#include <iostream>
//#include "fixtext.h"
//#include "lentext.h"
#include "varlen.h"

using namespace std;

class Issue
{
public:
	// fields
	short	student_id;
	char	*book_name;
	char	*student_name;
	char    *Return_date;
	char    *Issue_date;

	

	void setId(short id);
	void setbook_name(const char* book_name);
	void setstudent_name(const char* student_name);
	void setReturn_date(const char* return_date);
	void setIssue_date(const char* issue_date);


	// Getters
	short getId() const;
	const  char* getbook_name() const;
	const  char* getstudent_name() const;
	const  char* getReturn_date() const;
	const  char* getIssue_date() const;

	
	Issue();
	Issue(short id, char* bname, char* sname, char* Rdate, char* Idate);

	void InitRecord(VariableLengthRecord&); //set Record  Configuration

	int Pack(VariableLengthRecord&);	//  From ObjectPerson  to  Record =>  Write

	int Unpack(VariableLengthRecord&);  // From Record to  Object Person  => Read

	void Print(ostream&);
//add => mryam
//serch=> mryam
};
