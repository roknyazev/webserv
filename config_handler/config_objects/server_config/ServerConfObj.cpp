#include "ServerConfObj.hpp"

ServerConfObj::ServerConfObj()
{
	initParseFuncs();
	initParseVariables();
}

ServerConfObj::ServerConfObj(const ServerConfObj& other)
{

}

ServerConfObj::~ServerConfObj()
{
	
}

ServerConfObj& ServerConfObj::operator=(const ServerConfObj& other)
{
	return *this;
}

bool ServerConfObj::add(const std::string& key, const std::string& value)
{
	return true;
}

void ServerConfObj::initParseFuncs()
{
	parseFuncs_["server_name"] = &ServerConfObj::parseServerName;
	parseFuncs_["listen"] = &ServerConfObj::parseListen;
	parseFuncs_["autoindex"] = &ServerConfObj::parseAutoindex;
	parseFuncs_["root"] = &ServerConfObj::parseRoot;
	parseFuncs_["index"] = &ServerConfObj::parseIndex;
	parseFuncs_["access_method"] = &ServerConfObj::parseAccessMethods;
	parseFuncs_["error_page"] = &ServerConfObj::parseErrorPages;
	parseFuncs_["client_body_buffer_size"] = &ServerConfObj::parseClienBodyBufferSize;
}

void ServerConfObj::initParseVariables()
{
	variables_.insert("server_name");
	variables_.insert("listen");
	variables_.insert("autoindex");
	variables_.insert("root");
	variables_.insert("index");
	variables_.insert("access_method");
	variables_.insert("error_page");
	variables_.insert("client_body_buffer_size");
}

void ServerConfObj::parseServerName()
{

}
void ServerConfObj::parseListen()
{

}
