#include <string.h>
#include "issue.h"


Issue::Issue()
{
	student_id = 0;
	book_name[0] = 0;
	student_name[0] = 0;
	Return_date[0]=0;
	Issue_date[0]=0;
}

Issue::Issue(short id, char* bname, char* sname, char* Rdate, char* Idate)
{
	student_id = id;
	book_name = bname;
	student_name = sname;
	Return_date = Rdate;
	Issue_date = Idate;
}

// initialize a VariableLengthRecord to be used for Persons
void Issue::InitRecord(VariableLengthRecord& record)
{
	record.init(5);
	record.AddField(0, 'F', 2);  
	record.AddField(1, 'D', '|');
	record.AddField(2, 'D', '|');
	record.AddField(3, 'F', 8);
	record.AddField(4, 'F', 8);
	

}

int Issue::Pack(VariableLengthRecord& record)
{
	
	int result, recordSize = 0;   // Lenght Indicator  id(short) = 120 , name = AMES , Delimiter = 1 = > 7

	recordSize = 2 + strlen(book_name) + 1 + strlen(student_name) + 1  + 8 +8 ;  // all size 

	record.Clear(recordSize);          // بفضي مكان 

	result = record.Pack(0, (void*)&student_id, sizeof(short)) 
		&& record.Pack(1, (void*)book_name, strlen(book_name))
		&& record.Pack(2, (void*)student_name, strlen(student_name))
		&& record.Pack(3, (void*)&Return_date, sizeof(short))
		&& record.Pack(4, (void*)&Issue_date, sizeof(short));

	return result;
}

int Issue::Unpack(VariableLengthRecord& record)
{
	int result;
	
	result = record.Unpack(0, (char*)&student_id)
		&& record.Unpack(1, book_name, true)
		&& record.Unpack(2, student_name, true)    // الترو عشان تعرفني انه نهاية السترينج
		&& record.Unpack(3, (char*)&Return_date)
		&& record.Unpack(4, (char*)&Issue_date);
	return result;
}

void Issue::Print(ostream& stream)
{
	stream << "Issue:"
		<< "\tstudent's id '" << student_id << "'\n"
		<< "\tbook's name '" << book_name << "'\n"
		<< "\tstudent's name '" << student_name << "'\n"
		<< "\tReturn's date '" << Return_date << "'\n"
		<< "\tIssue's date '" << Issue_date << "'\n";
}



