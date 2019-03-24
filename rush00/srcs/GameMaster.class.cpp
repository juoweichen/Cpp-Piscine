#include "../includes/GameMaster.class.hpp"
#include "../includes/Projectile.class.hpp"
#include "../includes/Player.class.hpp"
#include "../includes/Alien.class.hpp"
#include "../includes/AGameObject.class.hpp"
#include "../includes/Space.class.hpp"

GameMaster::GameMaster()
{
    this->initialize_game();
}

GameMaster::~GameMaster()
{

}

void GameMaster::initialize_game()
{
    initscr();
	cbreak();
	nonl();
	noecho();
	intrflush(stdscr,FALSE);
    nodelay(stdscr,TRUE);   //no delay on getch
	keypad(stdscr,TRUE);
    curs_set(0);    //hide cursor
	refresh();

    getmaxyx(stdscr, this->_sizeY, this->_sizeX);
    this->setHorbeDirection("LEFT");
    this->_isAlienLeft = false;
}

void GameMaster::execution_loop()
{
	int ch = 0;		/* for getch */

    //space for collision detection
    Space space;
    space.createSpace();

    //create ship
    Player player(this->getSizeX() * 0.5, this->getSizeY() * 0.8);
    player.setAlive(1);

    //set ammo magezine
    Projectile *mag[AMMO];
    int magIndex = 0;

    //Load projectile to mag
    for (int i = 0; i < AMMO; i++)
    {
        mag[i] = new Projectile(player.getX(), player.getY());
        mag[i]->setIsFire(0);
        mag[i]->setAlive(1);
    }

    //create Enemy
    Alien *alienHorbe[HORBE_NUMBER];

    for (int i = 0; i < HORBE_NUMBER; i++)
    {
        alienHorbe[i] = new Alien(this->getSizeX() * 0.2 + (i * 2), this->getSizeY() * 0.2);
        alienHorbe[i]->setAlive(1);
    }

    //main loop
    do
    {
        //catch keyboard input
        ch = getch();
        clear();
        box(stdscr,'|','-');

        //set user input
        switch(ch)								
		{							
			case KEY_UP:
                if (player.getY() > 2)
                    player.move("UP");
                break;
			case KEY_DOWN:
                if (player.getY() < this->getSizeY() - 2)
                    player.move("DOWN");
                break;		
			case KEY_RIGHT:
                if (player.getX() < this->getSizeX() - 5)
                    player.move("RIGHT");
                break;		
			case KEY_LEFT:
                if (player.getX() > 2)
                    player.move("LEFT");
                break;
            case ' ':
                if (magIndex < AMMO && mag[magIndex]->getIsFire() == 0)
                {
                    mag[magIndex]->setIsFire(1);
                    mag[magIndex]->setX(player.getX());
                    mag[magIndex]->setY(player.getY());
                    magIndex++;
                }
                else
                    magIndex = 0;
                break ;
            case 27:		/* Esc key */
				endwin();	            
				exit(1);
            default:
				break;
        }

        //move enemy
        for (int i = 0; i < HORBE_NUMBER; i++)
            alienHorbe[i]->move(this->getHorbeDirection());
        
        //if out of boundry, change direction
        if (alienHorbe[HORBE_NUMBER - 1]->getX() > this->getSizeX() - 5)
            this->setHorbeDirection("LEFT");
        if (alienHorbe[0]->getX() < 3)
            this->setHorbeDirection("RIGHT");

        //check if projectile out of boundary
        for (int i = 0; i < AMMO; i++)
            if (mag[i]->getY() <= 2)
                mag[i]->setIsFire(0);

        //move projectile and draw it
        for (int i = 0; i < AMMO; i++)
        {
            mag[i]->move("");
            if (mag[i]->getIsFire() == 1)
                mvaddstr(mag[i]->getY() - 1, mag[i]->getX() + 1, "^");
        }

        // //detect collision
        space.updateSpace(player, mag, alienHorbe);
        space.detectCollision(player, mag, alienHorbe);

        //draw player
        if (player.getAlive() == 0)
        {
            endwin();
            std::cout << "YOU DIED" << std::endl;
            exit(0);
        }
        //mvaddstr(player.getY() - 1, player.getX() + 1, "A");
        mvaddstr(player.getY(), player.getX() ,"A");

        this->setAlienLeft(false);
        //draw enemy
        for (int i = 0; i < HORBE_NUMBER; i++)
        {
            if (alienHorbe[i]->getAlive() > 0)
            {
                mvaddstr(alienHorbe[i]->getY(), alienHorbe[i]->getX() ,"W");
                this->setAlienLeft(true);
            }
            //mvaddstr(alienHorbe[i]->getY() + 1, alienHorbe[i]->getX() + 1 ,"WW");
        }

        if (this->_isAlienLeft == false)
        {
            endwin();
            std::cout << "YOU WIN" << std::endl;
            exit(0);
        }

        usleep(10000);
        
    } while (1);
}

void    GameMaster::closeGame(void)
{
    //show how's win or lose
    endwin();
}

void    GameMaster::setSizeX(int sizeX)
{
    this->_sizeX = sizeX;
}

int     GameMaster::getSizeX(void)
{
    return this->_sizeX;
}

void    GameMaster::setSizeY(int sizeY)
{
    this->_sizeY = sizeY;
}

int     GameMaster::getSizeY(void)
{
    return this->_sizeY;
}

void    GameMaster::setHorbeDirection(std::string dir)
{
    this->_horbeDirection = dir;    
}

std::string     GameMaster::getHorbeDirection(void)
{
    return this->_horbeDirection;
}

void    GameMaster::setAlienLeft(bool is)
{
    this->_isAlienLeft = is;
}

GameMaster & GameMaster::operator=( GameMaster const & rhs )
{
	if ( this != &rhs )
	{
		this->_sizeX = rhs._sizeX;
		this->_sizeY = rhs._sizeY;
        this->_horbeDirection = rhs._horbeDirection;
        this->_isAlienLeft = rhs._isAlienLeft;
	}
	return *this;
}