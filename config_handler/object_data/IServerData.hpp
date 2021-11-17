#ifndef ISERVER_DATA_HPP
#define ISERVER_DATA_HPP

#include "IObjectData.hpp"

class IServerData : public virtual IObjectData
{
	public:
		virtual ~IServerData() {}
		virtual void parseServerName() = 0;
		virtual void parseListen() = 0;
};

#endif // ISERVER_DATA_HPP
