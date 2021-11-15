#ifndef CONFIG_OBJECT_HPP
#define CONFIG_OBJECT_HPP

#include "EConfObjParams.hpp"
#include <iostream>

class AConfigObject
{
	public:
		AConfigObject();
		AConfigObject(const AConfigObject& other);
		virtual ~AConfigObject();

		AConfigObject& operator=(const AConfigObject& other);

		//TODO(dkenchur): think about key type
		virtual const std::string& get(/*key*/) = 0;

		protected:

};

#endif // CONFIG_OBJECT_HPP
