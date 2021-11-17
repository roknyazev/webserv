#ifndef LOCATION_OBJECT_HPP
#define LOCATION_OBJECT_HPP

#include "AConfigObject.hpp"
#include "ConfObjectData.hpp"
#include "ILocationData.hpp"

class LocationConfObj : public AConfigObject, ILocationData, ConfObjectData
{
	public:
		LocationConfObj();
		LocationConfObj(const LocationConfObj& other);
		~LocationConfObj();

		LocationConfObj& operator=(const LocationConfObj& other);

		bool add(const std::string& key, const std::string& value); // override

	private:
		void initParseFuncs(); // override
		void initParseVariables(); // override

		void parseAlias(); // override
		void parseCGIPass(); // override

		typedef void (LocationConfObj::*parseArg)(void);

		std::map<std::string, parseArg> parseFuncs_;
		std::string alias_;
		std::string CGIPass_;
		std::vector<LocationConfObj> locations_;
};

#endif // LOCATION_OBJECT_HPP
