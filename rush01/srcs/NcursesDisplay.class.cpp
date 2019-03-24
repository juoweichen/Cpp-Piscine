#include "../includes/NcursesDisplay.class.hpp"
#include <sys/ioctl.h>

NcursesDisplay::NcursesDisplay(void)
{
	this->initialize();
}

NcursesDisplay::NcursesDisplay(NcursesDisplay const & src)
{
	*this = src;
}

NcursesDisplay::~NcursesDisplay(void)
{

}

NcursesDisplay const & NcursesDisplay::operator=(NcursesDisplay const & rhs)
{
	(void)rhs;
	return *this;
}

void NcursesDisplay::initialize(void)
{
	initscr();
	cbreak();
	nonl();
	noecho();
	intrflush(stdscr,FALSE);
    nodelay(stdscr,TRUE);
	keypad(stdscr,TRUE);
    curs_set(0);
	start_color();
	refresh();
}

void NcursesDisplay::title(std::string title)
{	
	int i = 0;
	struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
	int width = (w.ws_col < 60) ? w.ws_col : 60;

	for(i = 0; i < width; i++)
		printw("-");
	printw("\n %s\n", title.c_str());
	for(i = 0; i < width; i++)
		printw("-");
	printw("\n");
}

void NcursesDisplay::close(void)
{
	endwin();	            
	exit(1);
}