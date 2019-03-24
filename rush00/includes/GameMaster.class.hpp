#ifndef GAMEMASTER_HPP
# define GAMEMASTER_HPP

# include <ncurses.h>
# include <iostream>
# include <unistd.h>
# include <string>

# define AMMO 50
# define HORBE_NUMBER 10

class GameMaster {

    public:
        GameMaster();
        ~GameMaster();

        void initialize_game(void);
        void execution_loop(void);
		void closeGame(void);

        GameMaster &	operator=(GameMaster const & rhs);

        void    setSizeX(int sizeX);
		int     getSizeX(void);

		void    setSizeY(int sizeY);
		int     getSizeY(void);
        
		void            setHorbeDirection(std::string dir);
		std::string     getHorbeDirection(void);

        void            setAlienLeft(bool is);

    private:
        int _sizeX;
    	int _sizeY;
        
        std::string _horbeDirection;
        bool _isAlienLeft;
};

#endif