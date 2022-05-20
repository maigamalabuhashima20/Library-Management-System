#include <string.h>
#include "issue.h"


Issue::Issue()
{
	id = 0;
	student_name[0] = 0;
	Qty = 0;
	date[0]=0;
	category[0]=0;
}

Issue::Issue(short id, char book_name[], char student_name[], char Return_date[], char Issue_date[])
{
	id = 0;
	category[0] = 0;
	student_name[0] = 0;
	Qty = 0;
	date[0] = 0;
}

