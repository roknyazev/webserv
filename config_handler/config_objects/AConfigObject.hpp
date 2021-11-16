#ifndef CONFIG_OBJECT_HPP
#define CONFIG_OBJECT_HPP

#include <string>
#include <map>

class AConfigObject
{
	public:
		AConfigObject();
		AConfigObject(const std::map<std::string, std::string>& variables);
		AConfigObject(const AConfigObject& other);
		virtual ~AConfigObject();

		AConfigObject& operator=(const AConfigObject& other);

		virtual bool add(const std::string& key, const std::string& value) = 0;
		virtual const std::string& get(const std::string& key) const = 0;

	protected:
		std::map<std::string, std::string> variables_;
};

#endif // CONFIG_OBJECT_HPP
