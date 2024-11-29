#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "hw1.h"

int main(int argc, char **argv)
{
    assert(argc == 4);
    int num_x, num_o;
    

    printf("Initial state: %s\n", argv[3]);
    int result = solve(argv[3], (int)strtoul(argv[1], NULL, 10), (int)strtoul(argv[2], NULL, 10), &num_x, &num_o);
    //int result = solve("-o----o--oxx---o--ox--------o--x--xx--xxxo--------------x-x-----o---x------xx-ox-----o-------o-----oo-oo----x---o----x-x----o------x---------------xoo-x---x--ox--o-x---o------o----ooo-x--x-----------------ox----x---x--xxoo--------o--o----oo-o--------o---x---ooox--x------x-------xo----o--------x---o-ooo--o---x-x-x---o-o--ox-----xx------ooo-o----o-----o-ox--oox-x----xxx--oo--xo--x-ooo----o-o-x-----x", 
    //20, 20, &num_x, &num_o);
    printf("Result: %d\n", result);
    return 0;
}
