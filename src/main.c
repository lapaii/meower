#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char** argv)
{
    // checking arguments
    if (argc < 2) {
        printf("must specify an amount of meows!\n");
        return 1;
    }

    if (argc > 2) {
        printf("too many arguments supplied!\n");
        return 1;
    }

    // number of meows to do
    long num_meows = strtol(argv[1], NULL, 10);

    if (num_meows < 0) {
        printf("num_meows must be greater than 0!\n");
        return 1;
    }

    char* meows[]
        = { "meow", "maow", "mrrrow", "mrrrp", "nyaaa", "nya",
              "mew", "meowwww", "prrp", "nyaaaaaaaaaa", "mreow" };
    int meows_length = sizeof(meows) / sizeof(char*);

    // seeding the random function
    struct timeval time_now;
    gettimeofday(&time_now, NULL);

    srand((time_now.tv_sec * 1000) + (time_now.tv_usec / 1000));

    // for loop printing the meows
    for (int i = num_meows; i > 0; i--) {
        int random = rand() % meows_length;

        printf("%s ", meows[random]);
    }

    // should we add a :3 to the end or not?
    int prob = rand() % 100;

    if (prob < 33) {
        printf(":3\n");
    } else {
        printf("\n");
    }

    return 0;
}