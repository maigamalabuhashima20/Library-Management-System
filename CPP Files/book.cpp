#include <string.h>
#include "../Header Files/book.h"

Book::Book()
{

	id = 0;
	category[0] = 0;
	Name[0] = 0;
	Author[0] = 0;
	Qty = 0;
	price = 0;
}

Book::Book(short shId, char *c, char *n, char *a, short q, float p)
{
	id = shId;
	category = c;
	Name = n;
	Author = a;
	Qty = q;
	price = p;
}

void Book::setId(short id)
{
	this->id = id;
}
void Book::setCategory(const char *category)
{
	this->category == category;
}
void Book::setName(const char *name)
{
	this->Name == name;
}
void Book::setAuthor(const char *author)
{
	this->Author == author;
}
void Book::setQty(float qty)
{
	this->Qty = qty;
}
void Book::setPrice(float price)
{
	this->price = price;
}

short Book::getId() const
{
	return id;
}
const char *Book::getCategory() const
{
	return category;
}
const char *Book::getName() const
{
	return Name;
}
const char *Book::getAuthor() const
{
	return Author;
}
short Book::getQty() const
{
	return Qty;
}
float Book::getPrice() const
{
	return price;
}

// initialize a VariableLengthRecord to be used for Books
void Book::InitRecord(VariableLengthRecord &record)
{
	record.init(6);				  //#fields
	record.AddField(0, 'F', 2);	  // id
	record.AddField(1, 'D', '|'); // category
	record.AddField(2, 'D', '#'); // name
	record.AddField(3, 'D', '%'); // author
	record.AddField(4, 'F', 2);	  // qty
	record.AddField(5, 'F', 4);	  // price
}

// this pack is for the person class
int Book::Pack(VariableLengthRecord &record)
{
	// pack the fields into a VariableLengthRecord, return  ( 1 )TRUE if all succeed, FALSE o/w
	int result, recordSize = 0; // Length Indicator  id(short) = 120 , name = AMES , Delimiter = 1 = > 7

	// because we are length indicator record
	recordSize = 11 + strlen(Name) + strlen(category) + strlen(Author);

	record.Clear(recordSize);

	// result = record.Pack(0, (void *)&id, sizeof(short));

	// but this pack is for the variable length record
	result = record.Pack(0, (void *)&id, sizeof(short)) &&
			 record.Pack(1, (void *)category, strlen(category)) &&
			 record.Pack(2, (void *)Name, strlen(Name)) &&
			 record.Pack(3, (void *)Author, strlen(Author)) &&
			 record.Pack(4, (void *)&Qty, sizeof(short)) &&
			 record.Pack(5, (void *)&price, sizeof(float));

	return result;
}

int Book::Unpack(VariableLengthRecord &record)
{

	// use true with array of char to tell us that text is done
	int result;
	result = record.Unpack(0, (char *)&id) && record.Unpack(1, category, true) &&
			 record.Unpack(2, Name, true) &&
			 record.Unpack(3, Author, true) &&
			 record.Unpack(4, (char *)&Qty) &&
			 record.Unpack(5, (char *)&price);
	return result;
}
////////////////////////////////////////////////////////////////////mrymhuobppup
void Book::Print(ostream &stream)
{
	stream << "Book:"
		   << "\tId '" << getId() << "'\n"
		   << "\tcategory '" << getCategory() << "'\n"
		   << "\tName '" << getName() << "'\n"
		   << "\tAuthor '" << getAuthor() << "'\n"
		   << "\tQty '" << getQty() << "'\n"
		   << "\tprice '" << getPrice() << "'\n";
}
