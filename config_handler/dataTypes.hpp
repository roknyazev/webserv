#ifndef DATA_TYPES_HPP
#define DATA_TYPES_HPP

enum ERequests
{
	GET = 0,
	POST,
	DELETE
};

struct Listen_t
{
	unsigned int host;
	//TODO(dkenchur): host type is unsigned int???
	unsigned int port;
};

#endif // DATA_TYPES_HPP
