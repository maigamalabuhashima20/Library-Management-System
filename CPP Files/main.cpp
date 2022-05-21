#include "../Header Files/book.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	Book Book;

	VariableLengthRecord outRecord, inRecord;

	// fill object or function add

	Book.setId(30);
	Book.setCategory("computer");
	Book.setName("INTRO TO C++");
	Book.setAuthor("JAMES");
	Book.setQty(300);
	Book.setPrice(300.0);

	Book.InitRecord(outRecord); // configuration only once
	// packing
	cout << "pack Book " << Book.Pack(outRecord) << endl;

// start writing process
#pragma region Writing(Packing)

	ofstream TestOut("deltext.dat", ios::out | ios::binary);
	// writing header only once
	outRecord.WriteHeader(TestOut); // Only Once.

	// writing data
	outRecord.WriteL(TestOut);
	Book.Print(cout);

	// add new Book 1- fill Book data (object)  2- packing  3- writing

	Book.setId(300);
	Book.setCategory("physics");
	Book.setName("INTRO TO physics");
	Book.setAuthor("ahmed");
	Book.setQty(200);
	Book.setPrice(100.0);

	Book.Pack(outRecord); // Precord  => array  of  char   120Ames| , 130Ahmed|

	outRecord.WriteL(TestOut);

	Book.Print(cout); // for logging

	TestOut.close(); // close

	// end of add Book
	// end of writing process

	// start of reading process
#pragma endregion

#pragma region Reading(UnPacking)

	ifstream TestIn("deltext.dat", ios::in | ios::binary);
	inRecord.ReadHeader(TestIn);

	cout << "read " << inRecord.ReadL(TestIn) << endl;
	cout << "unpack " << Book.Unpack(inRecord) << endl;
	Book.Print(cout);

	cout << "read " << inRecord.ReadL(TestIn) << endl;
	cout << "unpack " << Book.Unpack(inRecord) << endl;
	Book.Print(cout);
#pragma endregion
}