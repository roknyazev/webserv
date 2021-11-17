#ifndef CONF_OBJECT_DATA_HPP
#define CONF_OBJECT_DATA_HPP

#include <string>
#include <vector>
#include <set>
#include <map>
#include "dataTypes.hpp"
#include "IObjectData.hpp"

class ConfObjectData : public virtual IObjectData
{
	public:
		virtual ~ConfObjectData();

	protected:
		ConfObjectData();

		void parseAutoindex(); // override
		void parseRoot(); // override
		void parseIndex(); // override
		void parseAccessMethods(); // override
		void parseErrorPages(); // override
		void parseClienBodyBufferSize(); // override

		bool autoindex_;
		std::string root_;
		std::vector<std::string> index_;
		std::set<ERequests> accessMethods_;
		std::map<int, std::string> errorPages_;
		int clientBodyBufferSize_;
};

#endif // CONF_OBJECT_DATA_HPP
