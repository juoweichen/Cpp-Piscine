#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

class ZombieHorde {
	public:
		ZombieHorde(void);
		ZombieHorde(int N);
		~ZombieHorde(void);

		void createHorde(void);
		void announce(void);
		void set

	private:
		int _N;
		Zombie *_horde;
};

#endif