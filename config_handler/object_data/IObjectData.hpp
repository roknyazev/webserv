#ifndef IOBJECT_DATA_HPP
#define IOBJECT_DATA_HPP

class IObjectData
{
	public:
		virtual ~IObjectData() {}
		virtual void parseAutoindex() = 0;
		virtual void parseRoot() = 0;
		virtual void parseIndex() = 0;
		virtual void parseAccessMethods() = 0;
		virtual void parseErrorPages() = 0;
		virtual void parseClienBodyBufferSize() = 0;
};

#endif // IOBJECT_DATA_HPP
