#include "../Header Files/book.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void main()
{
	Book Book;

	VariableLengthRecord outRecord, inRecord;

	//fill object
	Book.id = 120;
	strcpy_s(Book.Name, "Ames");

	Book.InitRecord(outRecord); // configuration only once
	// packing
	cout << "pack Book " << Book.Pack(outRecord) << endl;

	// start writing process
	#pragma region Writing(Packing)

	ofstream TestOut("deltext.dat", ios::out | ios::binary);
	// writing header only once
	outRecord.WriteHeader(TestOut); // Only Once.

	// writing data
	outRecord.Write(TestOut);
	Book.Print(cout);

	// add new Book 1- fill Book data (object)  2- packing  3- writing

	Book.id = 130;
	strcpy_s(Book.Name, "Ahmed");

	Book.Pack(outRecord); // Precord  => array  of  char   120Ames| , 130Ahmed|

	outRecord.Write(TestOut);

	Book.Print(cout); // for logging

	TestOut.close(); // close

	// end of add Book
	// end of writing process

	// start of reading process
#pragma endregion

#pragma region Reading(UnPacking)

	ifstream TestIn("deltext.dat", ios::in | ios::binary);
	inRecord.ReadHeader(TestIn);

	cout << "read " << inRecord.Read(TestIn) << endl;
	cout << "unpack " << Book.Unpack(inRecord) << endl;
	Book.Print(cout);

	cout << "read " << inRecord.Read(TestIn) << endl;
	cout << "unpack " << Book.Unpack(inRecord) << endl;
	Book.Print(cout);
#pragma endregion
}