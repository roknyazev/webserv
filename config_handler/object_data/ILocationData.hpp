#ifndef ILOCATION_DATA_HPP
#define ILOCATION_DATA_HPP

#include "IObjectData.hpp"

class ILocationData : public virtual IObjectData
{
	public:
		virtual ~ILocationData() {}
		//TODO(dkenchur): what is fucking alias
		virtual void parseAlias() = 0;
		virtual void parseCGIPass() = 0;
};

#endif // ILOCATION_DATA_HPP
