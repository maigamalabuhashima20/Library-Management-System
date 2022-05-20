#include <string.h>
#include "../Header Files/Issue.h"

Issue::Issue()
{
	id = 0;
	Name[0] = 0;
}

Issue::Issue(short id, char cat[], char n[],short q, float p)
{
	id = 0;
	category[0] = 0;
	student_name[0] = 0;
	Qty = 0;
	date[0] = 0;
}


