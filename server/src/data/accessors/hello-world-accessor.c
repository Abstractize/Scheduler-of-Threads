#include "../models/hello-world.c"
hello_world_t data;

void add(hello_world_t new_data)
{
    data = new_data;
}

hello_world_t get()
{
    return data;
}