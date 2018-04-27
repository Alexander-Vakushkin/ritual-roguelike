#ifndef DUNGEON_MAP_GENERATOR_H_e56f797f93026d5fd61da31c5a88bd95e8e8fe95
#define DUNGEON_MAP_GENERATOR_H_e56f797f93026d5fd61da31c5a88bd95e8e8fe95

#include <map_generator.h>

#include "../map.h"

class DungeonMapGenerator
    : public IMapGenerator
{
public:
    virtual std::unique_ptr<IMap> generate(size_t height, size_t width) const final;

private:
    
};



#endif // DUNGEON_MAP_GENERATOR_H_e56f797f93026d5fd61da31c5a88bd95e8e8fe95
