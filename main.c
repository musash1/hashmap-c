#include <stdio.h>
#include "hashmap.h"

int main() {
    HashMap* map = newHashMap();

    set(map, "age", 18);
    set(map, "height", 190);
    set(map, "weight", 85);

    printf("Age: %d\n", get(map, "age"));
    printf("Height: %d\n", get(map, "height"));
    printf("Weight: %d\n", get(map, "weight"));

    set(map, "age", 19);
    printf("Age: %d\n", get(map, "age"));
    printf("Map cap: %u, len: %u\n", map->cap, map->len);

    destroyHashMap(map);

    return 0;
}
