#include <iostream>
//#include "fixtext.h"
//#include "lentext.h"
#include "varlen.h"

using namespace std;

class Issue
{
public:
	// fields
	short	id;
	char	student_name[11];
	short   Qty;
	char    date[11];
	char category[20];



	void setId(short id);
	void setCategory(char category[]);
	void setstudent_name(char name[]);
	void setQty(float qty);

	// Getters
	short getId() const;
	char getCategory() const;
	char getstudent_name() const;
	short getQty() const;

	
	Issue();
	Issue(short id, char cat[], char n[], short q, float p);

	void InitRecord(VariableLengthRecord&); //set Record  Configuration

	int Pack(VariableLengthRecord&);	//  From ObjectPerson  to  Record =>  Write

	int Unpack(VariableLengthRecord&);  // From Record to  Object Person  => Read

	void Print(ostream&);

	//Add..mryam
	//serch..mryam

};
