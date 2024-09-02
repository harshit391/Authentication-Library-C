#include "sendmail.h"
#include "generateCode.h"

int main()
{
	char verfcode[100];

	generate_verf_code(verfcode, 7);
	sendMail("balwinderthinda456@gmail.com", verfcode);
	return 0;
}
