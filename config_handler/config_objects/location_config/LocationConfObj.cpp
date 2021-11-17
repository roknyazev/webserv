#include "LocationConfObj.hpp"

LocationConfObj::LocationConfObj()
{
	
}

LocationConfObj::LocationConfObj(const LocationConfObj& other)
{
	
}

LocationConfObj::~LocationConfObj()
{
	
}

LocationConfObj& LocationConfObj::operator=(const LocationConfObj& other)
{
	return *this;
}

bool LocationConfObj::add(const std::string& key, const std::string& value)
{
	return true;
}

void LocationConfObj::initParseFuncs()
{
	parseFuncs_["alias"] = &LocationConfObj::parseAlias;
	parseFuncs_["cgi_pass"] = &LocationConfObj::parseCGIPass;
	parseFuncs_["autoindex"] = &LocationConfObj::parseAutoindex;
	parseFuncs_["root"] = &LocationConfObj::parseRoot;
	parseFuncs_["index"] = &LocationConfObj::parseIndex;
	parseFuncs_["access_method"] = &LocationConfObj::parseAccessMethods;
	parseFuncs_["error_page"] = &LocationConfObj::parseErrorPages;
	parseFuncs_["client_body_buffer_size"] = &LocationConfObj::parseClienBodyBufferSize;
}

void LocationConfObj::initParseVariables()
{
	variables_.insert("alias");
	variables_.insert("cgi_pass");
	variables_.insert("autoindex");
	variables_.insert("root");
	variables_.insert("index");
	variables_.insert("access_method");
	variables_.insert("error_page");
	variables_.insert("client_body_buffer_size");
}

void LocationConfObj::parseAlias()
{

}

void LocationConfObj::parseCGIPass()
{

}

