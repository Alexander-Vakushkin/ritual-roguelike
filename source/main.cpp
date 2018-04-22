#include <iostream>
#include <libtcod.hpp>


int main()
{
    TCOD_renderer_t renderer=TCOD_RENDERER_SDL;
    TCOD_key_t key = {TCODK_NONE,0};

	TCODConsole::initRoot(80,50,"Ritual roguelike game",false,renderer);
    TCODConsole::root->setDefaultForeground(TCODColor::grey);
    TCODConsole::root->setDefaultBackground(TCODColor::black);
    TCODConsole::root->printEx(30,25,TCOD_BKGND_SET,TCOD_LEFT,"Hello from libtcod!");

    TCODConsole::flush();

    do
    {
        TCODSystem::checkForEvent((TCOD_event_t)(TCOD_EVENT_KEY_PRESS),&key, nullptr);
    } while (key.vk != TCODK_ENTER);

    return 0;
}
