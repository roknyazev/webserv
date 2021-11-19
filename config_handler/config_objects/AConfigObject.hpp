#ifndef CONFIG_OBJECT_HPP
#define CONFIG_OBJECT_HPP

#include <string>
#include <set>
#include "LocationConfObj.hpp"

class LocationConfObj;

class AConfigObject
{
	public:
		AConfigObject();
		AConfigObject(const AConfigObject& other);
		virtual ~AConfigObject();

		AConfigObject& operator=(const AConfigObject& other);

		virtual bool add(const std::string& key, const std::string& value) = 0;
		void addLocation(LocationConfObj* locationObj, const std::string& locationPath);
		const std::vector<LocationConfObj*>& getLocations() const;
		// TODO(dkenchur): delete getter
		// virtual const std::string& get(const std::string& key) const = 0;

	protected:
		virtual void initParseFuncs() = 0;
		virtual void initParseVariables() = 0;

		std::set<std::string> variables_;
		// TODO(dkenchur): change vector type to AConfigObject*?
		// Or add member function to AConfigObject*: addLocation(LocationConfObj*)! ---priority---
		std::vector<LocationConfObj*> locations_;
};

#endif // CONFIG_OBJECT_HPP
