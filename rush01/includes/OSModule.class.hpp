#ifndef OSMODULE_CLASS_HPP
# define OSMODULE_CLASS_HPP

# include "../includes/AModule.class.hpp"

class OSModule : public AModule
{
	public:
		OSModule(void);
		OSModule(OSModule const & src);
		~OSModule(void);
		OSModule const & operator=(OSModule const & rhs);

		void setOSinfo(void);

	private:
};

#endif