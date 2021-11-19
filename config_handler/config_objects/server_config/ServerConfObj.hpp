#ifndef SERVER_OBJECT_HPP
#define SERVER_OBJECT_HPP

#include "AConfigObject.hpp"
#include "ConfObjectData.hpp"
#include "LocationConfObj.hpp"

class ServerConfObj : public AConfigObject, ConfObjectData
{
	public:
		ServerConfObj();
		ServerConfObj(const ServerConfObj& other);
		~ServerConfObj();

		ServerConfObj& operator=(const ServerConfObj& other);

		bool add(const std::string& key, const std::string& value); // override

	private:
		void initParseFuncs(); // override
		void initParseVariables(); // override

		void parseServerName();
		void parseListen();
		// void addLocation(); // override

		typedef void (ServerConfObj::*parseArg)(void);

		std::map<std::string, parseArg> parseFuncs_;
		std::vector<std::string> serverNames_;
		std::vector<Listen_t> listenAddresses_;
};
 
#endif // SERVER_OBJECT_HPP
