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
	char Name[20];
	char Author[20];
	short Qty;
	float price;

public:
	// Setters
	void setId(short id);
	void setCategory(const char *category);
	void setName(const char *name);
	void setAuthor(const char *author);
	void setQty(short qty);
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
	void Add_Book();
	void Updata_Books();
	void display_book (fstream& file);
};
