#include <iostream>
//#include "fixtext.h"
//#include "lentext.h"
#include "varlen.h"

using namespace std;

class Book
{
private:
	// fields
	short id;
	char category[20];
	char Name[11];
	char Author[11];
	short Qty;
	float price;

public:
	// Setters
	void setId(short id);
	void setCategory(char category[]);
	void setName(char name[]);
	void setAuthor(char author[]);
	void setQty(float qty);
	void setPrice(float price);

	// Getters
	short getId() const;
	char getCategory() const;
	char getName() const;
	char getAuthor() const;
	short getQty() const;
	float getPrice() const;

	// operations
	Book();
	Book(short shId, char c[], char n[], char a[], short q, float p); /// this is error here ??  now it's no error

	void InitRecord(VariableLengthRecord &); // set Record  Configuration

	int Pack(VariableLengthRecord &); //  From ObjectPerson  to  Record =>  Write

	int Unpack(VariableLengthRecord &); // From Record to  Object Person  => Read

	void Print(ostream &);
};
