#ifndef IMONITORMODULE_CLASS_HPP
# define IMONITORMODULE_CLASS_HPP

# include <unistd.h>
# include <string>
# include <map>

class IMonitorModule
{
	public:
		IMonitorModule(void);
		IMonitorModule(IMonitorModule const & src);
		virtual ~IMonitorModule(void);
		IMonitorModule const & operator=(IMonitorModule const & rhs);

		virtual std::string getFromMap(std::string label) = 0;
		virtual void updateMap(std::string label, std::string output) = 0;

	protected:
		std::map<std::string, std::string> _moduleMap;
};

#endif