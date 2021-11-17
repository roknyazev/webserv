#ifndef SERVER_OBJECT_HPP
#define SERVER_OBJECT_HPP

// #include "AConfigObject.hpp"
// #include "ConfObjectData.hpp"
#include "IServerData.hpp"
#include "LocationConfObj.hpp"

class ServerConfObj : public AConfigObject, IServerData, ConfObjectData
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

		void parseServerName(); // override
		void parseListen(); // override

		typedef void (ServerConfObj::*parseArg)(void);

		std::map<std::string, parseArg> parseFuncs_;
		std::vector<std::string> serverNames_;
		std::vector<Listen_t> listenAddresses_;
		std::vector<LocationConfObj> locations_;
};
 
#endif // SERVER_OBJECT_HPP
