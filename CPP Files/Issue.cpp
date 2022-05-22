#include <string.h>
#include "issue.h"
#include <fstream>


Issue::Issue()
{
	student_id = 0;
	book_name[0] = 0;
	student_name[0] = 0;
	Return_date[0]=0;
	Issue_date[0]=0;
}

Issue::Issue(short id, char bname[], char sname[], char Rdate[], char Idate[])
{
	student_id = id;
	strcpy_s(book_name, bname);
	strcpy_s(student_name, sname);
	strcpy_s(student_name, Rdate);
	strcpy_s(Issue_date, Idate);
}

//set
void Issue::setId(short student_id)
{
	this->student_id = student_id;
}

void Issue::setbook_name(const char* book_name)
{
	strcpy_s(this->book_name, book_name);
}

void Issue::setstudent_name(const char* student_name)
{
	strcpy_s(this->student_name, student_name);
}

void Issue::setReturn_date(const char* Return_date)
{
	strcpy_s(this->Return_date, Return_date);
}

void Issue::setIssue_date(const char* Issue_date)
{
	strcpy_s(this->Issue_date, Issue_date);
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
void Issue::Add_Book() {
	VariableLengthRecord outRecord;

	short id, choice =1;
	char book_name[20], student_name[20], Return_date[20], Issue_date[20];

	InitRecord(outRecord); // only once

	
	ofstream TestOut("deltext2.dat", ios::out | ios::binary | ios::app);

	outRecord.WriteHeader(TestOut);  // Only Once.

	if (TestOut.is_open()) {
		while (choice )
		{
			cout << "Enter the student id\n";
			cin >> id;
			setId(id);

			cout << "Enter the book name\n";
			cin >> book_name;
			setbook_name(book_name);

			cout << "Enter the student name\n";
			cin >> student_name;
			setstudent_name(student_name);

			cout << "Enter the Return date\n";
			cin >> Return_date;
			setReturn_date(Return_date);

			cout << "Enter the Issue date\n";
			cin >> Issue_date;
			setIssue_date(Issue_date);

			Pack(outRecord);
			outRecord.WriteL(TestOut);

			cout << " added done successfully\nenter 1 to insert a new book or 0 to main menu ";
			cin >> choice;
		}
	}
	TestOut.close();
}

//serch=>mryam
void Issue::search() 

	{
		short id, choice = 1, flag = 0;

		VariableLengthRecord inRecord;
		ifstream TestIn("deltext2.dat", ios::in | ios::binary);

		inRecord.ReadHeader(TestIn);
		if (TestIn.is_open())
		{
			while (choice)
			{
				cout << "Enter id search for : ";
				cin >> id;

				while (!TestIn.eof())
				{
					inRecord.ReadL(TestIn);
					Unpack(inRecord);

					if (getId() == id)
					{
						Print(cout);
						flag = 1;
						break;
					}
					else
					{
						flag = 0;
						continue;
					}
				}
				if (flag == 0)
					cout << "Not Found\n";
				cout << "want to search again ? enter 1 to search  or 0 to main menu ";
				cin >> choice;
			}

		}
	}


void Issues ::display_Issues ()
{
 VariableLengthRecord inRecord;      //object from chass varable hength

 ifstream TestIn("deltext2.dat", ios::in | ios::binary);
 inRecord.ReadHeader(TestIn);
 TestIn.seekg(0, ios::beg);        // Reset Cursor
 if (TestIn.is_open())
 {
  while (!TestIn.eof())
  {
   cout << "read " << inRecord.ReadL(TestIn) << endl;
   cout << "unpack " << Unpack(inRecord) << endl;
   Print();

    cout << "student_ id : " << Id() << endl;
  cout << " student_name: " << sname()  << endl;
  cout << "book_ Name : " <<  bName()<< endl;
  cout << " Return_date: " <<Rdate ()<< endl;
  cout << " Issue_date: " <<Idate ()<< endl;
 
  }
 }
 TestIn.close();
 // TestIn.clear();  //to able to read aga
}
