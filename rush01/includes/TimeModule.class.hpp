#ifndef TIMEMODULE_CLASS_HPP
# define TIMEMODULE_CLASS_HPP

# include <ctime>
# include "../includes/AModule.class.hpp"

class TimeModule : public AModule
{
	public:
		TimeModule(void);
		TimeModule(TimeModule const & src);
		~TimeModule(void);
		TimeModule const & operator=(TimeModule const & rhs);

		void setTimeinfo(void);

	private:
};

#endif