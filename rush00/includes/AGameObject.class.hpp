#ifndef AGAMEOBJECT_HPP
# define AGAMEOBJECT_HPP

# include <string>

class AGameObject
{
	public:
		AGameObject(void);
		AGameObject(AGameObject const & src);
		AGameObject(unsigned int x, unsigned int y);
		~AGameObject(void);

		AGameObject &	operator=(AGameObject const & rhs);

		void setX(int x);
		int getX(void);
		void setY(int y);
		int getY(void);

		void setAlive(int alive);
		int getAlive(void);

		virtual void move(std::string move) = 0;

	private: 
		unsigned int _x;
		unsigned int _y;
		int 		_isAlive;
};

#endif