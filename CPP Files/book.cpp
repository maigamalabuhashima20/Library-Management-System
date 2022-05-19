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

Book::Book(short shId, char c[], char n[], char a[], short q, float p)
{
	id = shId;
	strcpy_s(category, c);
	strcpy_s(Name, n);
	strcpy_s(Author, a);
	Qty = q;
	price = p;
}

void Book::setId(short id)
{
	this->id = id;
}
void Book::setCategory(char category[])
{
	this->category[] = category[];
}
void Book::setName(char name[])
{
	this->name[] = name[];
}
void Book::setAuthor(char author[])
{
	this->author[] = author;
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
char * Book::getCategory() const
{
	return category;
}
char * Book::getName() const
{
	return Name;
}
char * Book::getAuthor() const
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
	record.AddField(1, 'D', '|'); //category
	record.AddField(2, 'D', '#'); // name
	record.AddField(3, 'D', '%'); // author
	record.AddField(4, 'F', 2);	  // qty
	record.AddField(5, 'F', 4);	  //price
}

int Book::Pack(VariableLengthRecord &record)
{
	// pack the fields into a VariableLengthRecord, return  ( 1 )TRUE if all succeed, FALSE o/w
	int result, recordSize = 0; // Length Indicator  id(short) = 120 , name = AMES , Delimiter = 1 = > 7

	// because we are length indicator record
	recordSize = 11 + strlen(Name) + strlen(category) + strlen(Author);

	record.Clear(recordSize);

	//result = record.Pack(0, (void *)&id, sizeof(short));

	result = record.Pack(0, (void *)&id, sizeof(short))
	 		&& record.Pack(1, (void *)category, strlen(category)) 
		 	&& record.Pack(1, (void *)Name, strlen(Name)) 
			&& record.Pack(1, (void *)Author, strlen(Author))
			&& record.Pack(1, (void *)&Qty, sizeof(short))
			&& record.Pack(1, (void *)&price, sizeof(float));

	return result;
}

int Book::Unpack(VariableLengthRecord &record)
{
	int result;
	result = record.Unpack(0, (char *)&id);
	result = result && record.Unpack(1, Name, true);
	return result;
}
////////////////////////////////////////////////////////////////////mrym
void Book::Print(ostream &stream)
{
	stream << "Book:"
		   << "\tId '" << id << "'\n"
		   << "\tName '" << Name << "'\n";
}
