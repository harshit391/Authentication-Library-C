

// Some Macros for Email Length and Verfiication Code Length
#define FROM "harshitsingla1761@gmail.com"
#define EMAIL_LEN 256
#define VER_CODE_LEN 7

// Defines the object which stores the basic values for our email that needs to be send via SMTP
struct email 
{
    int lines_read; // To Calculate the size of data needs to be sent
			
  	char verf_code[VER_CODE_LEN]; // Main Verification Code

  	char recipient[EMAIL_LEN]; // To Store Recipient Email
};

// Main Payload of our Email
static size_t payload_source(void *ptr, size_t size, size_t nmemb, void *userp)
{
  	struct email *curr_email = (struct email *) userp; // Setting up the email

  	const char *data; // Setting up the curr email data
 	
	char buffer[512]; // Used it to store curr recipient email address 

	// Checking for Empty values 
	
  	if ((size == 0) || (nmemb == 0) || ((size*nmemb) < 1)) 
	{
    	return 0;
  	}

	// Setting up the data of mail
  	switch(curr_email->lines_read)
	{
		case 0:
				snprintf(buffer, sizeof(buffer), "To: %s\r\n", curr_email->recipient);
				data = buffer;
				break;
		case 1:
				data = "From: " FROM " (Singla Ji)\r\n";
				break;
		case 2:
				data = "Subject: Email Verification\r\n";
				break;
		case 3:
				data = "\r\n";
				break;
		case 4:
				data = "Hello,\r\n";
				break;
		case 5:
				data = "Please verify your email address by entering the Verification Code Given Below:\r\n";
				break;
		case 6:
				data = curr_email->verf_code;
				break;
		case 7:
				data = "\r\n";
				break;
		case 8:
				data = "Thank you!\r\n";
				break;
		default:
				data = NULL;
				break;
    }
	
	// If we are able to setup data successfully for email
 	if (data) 
 	{
		size_t len = strlen(data); // Then we calculate the length of data we made

		memcpy(ptr, data, len); // Copying the data to the main source declared in send Mail function
    		
		curr_email->lines_read++; // Updating the email lines 
    		
		return len; 
  	}

  	return 0;
}

int sendMail(char rec[], char verf_code[])
{
	// Setting up the CURL Object
  	CURL *curl;

	// To Keep checking the response we are getting from CURL
  	CURLcode res = CURLE_OK;
  
	// Declaring recipients
	struct curl_slist *recipients = NULL;
  	
	// Declaring our email object
	struct email curr_email = {0};

	// Storing current verification code
	strcpy(curr_email.verf_code, verf_code);
	
	// Copying the recipient mail we recieved during runtime to email object recipient
	strncpy(curr_email.recipient, rec, EMAIL_LEN - 1);
  	curr_email.recipient[EMAIL_LEN - 1] = '\0';

	// Initiliazing the CURL now
  	curl = curl_easy_init();
  
	// If we are able to setup CURL 
	if (curl)
	{
		char userName[100];
		char appPass[100];

		getDataFromFile(userName, "database/mailuser.txt");
		getDataFromFile(appPass, "database/mailpass.txt");

		/* Setting Up Login Credentials for SMTP Server */
		curl_easy_setopt(curl, CURLOPT_USERNAME, userName); 
		curl_easy_setopt(curl, CURLOPT_PASSWORD, appPass); // App Password 
		curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587"); // Gmail SMTP server with TLS 587 PORT

		/* Set the sender and receiver */
		curl_easy_setopt(curl, CURLOPT_MAIL_FROM, FROM);
		recipients = curl_slist_append(recipients, rec);
		curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

		/* Set the payload data */
		curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
		curl_easy_setopt(curl, CURLOPT_READDATA, &curr_email);
		curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

		/* Set SMTP options for TLS */
		curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L); // Verify SSL certificates
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L); // Verify the hostname

		/* Increase verbosity */
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

		/* Send the message */
		res = curl_easy_perform(curl);

		/* Check for errors */
		if (res != CURLE_OK) 
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		}
		else
		{
			printf("Email sent successfully.\n");
		}

		/* Clearnup at the end */
		curl_slist_free_all(recipients);
		curl_easy_cleanup(curl);
	}

  	return (int)res;
}

