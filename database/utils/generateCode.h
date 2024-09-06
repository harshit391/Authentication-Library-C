// Generate Verification Code
void generate_verf_code(char *verfcode, int n) 
{       	
	// Setting the seed
	srand(time(NULL));
    	
	// Generating random numbers 
	for (int i = 0; i < n - 1; i++) 
	{
    	verfcode[i] = '0' + (rand() % 10);
    }
	
	// Termination the code character array 
	verfcode[n - 1] = '\0';
}