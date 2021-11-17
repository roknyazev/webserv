#ifndef CONFIG_OBJECT_HPP
#define CONFIG_OBJECT_HPP

#include <string>
#include <set>

class AConfigObject
{
	public:
		AConfigObject();
		AConfigObject(const AConfigObject& other);
		virtual ~AConfigObject();

		AConfigObject& operator=(const AConfigObject& other);

		virtual bool add(const std::string& key, const std::string& value) = 0;
		//TODO(dkenchur): delete getter
		virtual const std::string& get(const std::string& key) const = 0;

		protected:
			virtual void initParseFuncs() = 0;
			virtual void initParseVariables() = 0;

			std::set<std::string> variables_;
};

#endif // CONFIG_OBJECT_HPP
