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
	char *category;
	char *Name;
	char *Author;
	short Qty;
	float price;

public:
	// Setters
	void setId(short id);
	void setCategory(const char *category);
	void setName(const char *name);
	void setAuthor(const char *author);
	void setQty(float qty);
	void setPrice(float price);

	// Getters
	short getId() const;
	const char *getCategory() const;
	const char *getName() const;
	const char *getAuthor() const;
	short getQty() const;
	float getPrice() const;

	// operations
	Book();
	Book(short shId, char *c, char *n, char *a, short q, float p); /// this is error here ??  now it's no error

	void InitRecord(VariableLengthRecord &); // set Record  Configuration

	int Pack(VariableLengthRecord &); //  From ObjectPerson  to  Record =>  Write

	int Unpack(VariableLengthRecord &); // From Record to  Object Person  => Read

	void Print(ostream &);
};
