#include <iostream>
#include <lua.hpp>

int main()
{
    lua_State* L = luaL_newstate();

    std::cout << "Hello World!" << std::endl;
    return 0;
}