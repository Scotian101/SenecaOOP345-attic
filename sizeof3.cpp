#include <iostream>
using namespace std;

#include <malloc.h>

int main(int argc, char ** argv)
{
	uint8_t *big_buf = (uint8_t *) malloc(10000000);

	cout << sizeof(big_buf) << endl;
	cout << big_buf << endl;

	if(big_buf) free(big_buf);
}

