#include "main.h"

/**
 * _headers - defines the headers on a global scale without global variables
 * Return: void
*/
headers_t _headers(void)
{
	headers_t headers;

	headers.opcode = OPC_RESET;
	headers.args = ARG_RESET;
	headers.file = FILE_RESET;
	headers.flag = FLAG_RESET;

	return (headers);
}
