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
	book_name = bname;
	student_name = sname;
	Return_date = Rdate;
	Issue_date = Idate;
}



