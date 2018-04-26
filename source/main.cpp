#include <iostream>
#include <random>
#include <libtcod.hpp>

#include "map.h"

int main()
{
    std::unique_ptr<IMap> map = std::make_unique<Map>(50, 80);
    std::unique_ptr<TCODRandom> rng = std::make_unique<TCODRandom>();
    for(int i = 0; i < 30; ++i)
    {
        map->get_tile(rng->getInt(0, 49), rng->getInt(0, 79)) = Tile('#', false);
    }



	TCODConsole::initRoot(80,50,"Ritual roguelike game");
    TCODConsole::root->setDefaultForeground(TCODColor::grey);
    TCODConsole::root->setDefaultBackground(TCODColor::black);
    TCODConsole::root->printEx(30,25,TCOD_BKGND_SET,TCOD_LEFT,"Hello from libtcod!");

    for(size_t i = 0; i < 50; ++i)
    {
        for(size_t j = 0; j < 80; ++j)
        {
            const Tile& tile = map->get_tile(i, j);
            TCODConsole::root->putCharEx(j, i, tile.get_view(), TCODColor::white, TCODColor::black);
        }
    }

    TCODConsole::flush();

    TCOD_key_t key = {TCODK_NONE,0};
    do
    {
        TCODSystem::checkForEvent((TCOD_event_t)(TCOD_EVENT_KEY_PRESS),&key, nullptr);
    } while (key.vk != TCODK_ENTER);

    return 0;
}
