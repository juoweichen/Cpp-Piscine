#ifndef NCURSESDISPLAY_CLASS_HPP
# define NCURSESDISPLAY_CLASS_HPP

# include <stdlib.h>
# include <ncurses.h>
# include <string>

class NcursesDisplay
{
	public:
		NcursesDisplay(void);
		NcursesDisplay(NcursesDisplay const & src);
		~NcursesDisplay(void);

		NcursesDisplay const & operator=(NcursesDisplay const & rhs);

		void initialize(void);
		void close(void);

		void title(std::string title);

	private:
};

#endif