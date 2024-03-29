//#include <stdlib>
#include <iostream>

using namespace std;

class Person;

struct Field
{
	char szFieldRepresentation;  // F (Fixed Length)  D (Delimited) L (Length Indicator) 
	char length;				// F,L => Max 255
	char delimiter;				// Delimiter char
};

// Abstract class designed to support variable length records
// Fields may be of a variety of types
class VariableLengthRecord
{
	// props

private:
	Field* m_recordFields;  // array of  fields (dynamic)
	int		m_iRecordSize, m_iNextByte, m_iFieldsCount; // m_iNextByte Index Tracker
	char* pRecord; // Record itself.



	// Operations
public:

	VariableLengthRecord();

	void init(int iFieldsCount);

	void AddField(int index, char szType, char delimiter);  //Delimited 0 D |
	void AddField(int index, char szType, int length);  // Fixed , LI   1 [F or L] (Length)

	bool WriteHeader(ostream&) const;
	bool ReadHeader(istream&);

	void Clear(int recordSize = -1); // clear fields from Record

	bool PackFixLen(void* lpData, int dataLength, int fieldLength); // Value,Valuelength,FieldLength
	bool PackDelimeted(void* lpData, int dataLength, char delimiter);
	bool PackLength(void* lpData, short dataLength, char lengthIndicatorSize);


	bool Pack(int, void*, int);


	bool UnpackFixLen(char* lpData, int fieldLength);
	bool UnpackDelimeted(char* lpData, char delimiter, bool bIsText = false);
	bool UnpackLength(char*, char lengthIndicatorSize, bool bIsText = false);


	bool Unpack(int, char*, bool bIsText = false);

	bool ReadL(istream&);
	bool WriteL(ostream&) const;

	bool ReadF(istream&);
	bool WriteF(ostream&) const;

	bool ReadD(istream&);
	bool WriteD(ostream&) const;
};