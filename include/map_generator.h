#ifndef MAP_GENERATOR_H_a804bf2de06d28e4a8cbd20395ad071c254ee896
#define MAP_GENERATOR_H_a804bf2de06d28e4a8cbd20395ad071c254ee896

#include <map.h>
#include <memory>

class IMapGenerator
{
public:
    virtual std::unique_ptr<IMap> generate(size_t height, size_t width) const = 0;
};

#endif // MAP_GENERATOR_H_a804bf2de06d28e4a8cbd20395ad071c254ee896
