#include "main.h"

/**
 * _headers - defines the headers on a global scale without global variables
 * Return: void
*/
headers_t *_headers(void)
{
	static headers_t headers;

	return (&headers);
}
