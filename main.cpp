#include "Game.h"

int main()
{
    Game game(165);
    while (!game.GetWindow()->IsDone())
    {
        game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClockFixed();
        game.RestartClock();
    }
}
