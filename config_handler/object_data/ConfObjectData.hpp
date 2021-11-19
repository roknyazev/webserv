#ifndef CONF_OBJECT_DATA_HPP
#define CONF_OBJECT_DATA_HPP

#include <string>
#include <vector>
#include <set>
#include <map>
#include "dataTypes.hpp"

class ConfObjectData
{
	public:
		ConfObjectData();
		virtual ~ConfObjectData();

	protected:
		void parseAutoindex();
		void parseRoot();
		void parseIndex();
		void parseAccessMethods();
		void parseErrorPages();
		void parseClienBodyBufferSize();

		bool autoindex_;
		std::string root_;
		std::vector<std::string> index_;
		std::set<ERequests> accessMethods_;
		std::map<int, std::string> errorPages_;
		int clientBodyBufferSize_;
};

#endif // CONF_OBJECT_DATA_HPP
