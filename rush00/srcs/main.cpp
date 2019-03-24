#include "../includes/GameMaster.class.hpp"

int main(void)
{
    GameMaster master;

    master.initialize_game();
    master.execution_loop();
    master.closeGame();
}
