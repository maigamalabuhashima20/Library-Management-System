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
	strcpy(book_name, bname);
	strcpy(book_name, sname);
	strcpy(book_name, Rdate);
	strcpy(book_name, Idate);
}

//set
void Issue::setId(short student_id)
{
	this->student_id = student_id;
}

void Issue::setbook_name(const char* book_name)
{
	strcpy(this->book_name, book_name);
}

void Issue::setstudent_name(const char* student_name)
{
	strcpy(this->student_name, student_name);
}

void Issue::setReturn_date(const char* Return_date)
{
	strcpy(this->Return_date, Return_date);
}

void Issue::setIssue_date(const char* Issue_date)
{
	strcpy(this->Issue_date, Issue_date);
}


//get
short Issue::getId() const
{
	return student_id;
}

const char* Issue::getbook_name() const
{
	return book_name;
}

const char* Issue::getstudent_name() const
{
	return student_name;
}

const char* Issue::getReturn_date() const
{
	return Return_date;
}

const char* Issue::getIssue_date() const
{
	return Issue_date;
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
		&& record.Unpack(2, student_name, true) // الترو عشان تعرفني انه نهاية السترينج
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



//add =>mryam

//serch=>mryam

