#ifndef NAMEMODULE_CLASS_HPP
# define NAMEMODULE_CLASS_HPP

# include "../includes/AModule.class.hpp"

class NameModule : public AModule
{
	public:
		NameModule(void);
		NameModule(NameModule const & src);
		~NameModule(void);

		NameModule const & operator=(NameModule const & rhs);

		void setHostName(void);
		void setUserName(void);

	private:
};

#endif