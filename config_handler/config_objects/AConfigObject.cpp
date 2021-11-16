#include "AConfigObject.hpp"

AConfigObject::AConfigObject()
{ }

AConfigObject::AConfigObject(const std::map<std::string, std::string>& variables)
	: variables_(variables)
{ }

AConfigObject::AConfigObject(const AConfigObject& other)
	: variables_(other.variables_)
{ }

AConfigObject::~AConfigObject()
{ }

AConfigObject& AConfigObject::operator=(const AConfigObject& other)
{
	if (this != &other)
	{
		variables_ = other.variables_;
	}
	return *this;
}
