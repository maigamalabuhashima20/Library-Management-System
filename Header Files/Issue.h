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
	void setbook_name(char name[]);
	void setstudent_name(char name[]);
	void setReturn_date(char category[]);
	void setIssue_date(char category[]);


	// Getters
	short getId() const;
	char getbook_name() const;
	char getstudent_name() const;
	char getReturn_date() const;
	char getIssue_date() const;

	
	Issue();
	Issue(short id, char book_name[], char student_name[], char Return_date[], char Issue_date[]);

	void InitRecord(VariableLengthRecord&); //set Record  Configuration

	int Pack(VariableLengthRecord&);	//  From ObjectPerson  to  Record =>  Write

	int Unpack(VariableLengthRecord&);  // From Record to  Object Person  => Read

	void Print(ostream&);
	
// add => mryam
//serch => mryam
};
