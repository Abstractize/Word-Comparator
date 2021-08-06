#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char* my_env_var = getenv("REST_URL");

    if(my_env_var)
        printf("Var found: %s \n", my_env_var );
    else
        printf("Var not found. \n");                

    return 0;
}
