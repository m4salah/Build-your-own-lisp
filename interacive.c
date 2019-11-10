#include <stdio.h>

static char input[2048];
int
main(){
    /* Pring usfull staff */
    puts("Lisp version 0.0.0.0.1");
    puts("Press ctr-c to Exit\n");

    // infinte loooooooooooooooop

    while(!0){
        
        fputs("Lispy> ",stdout);
        fgets(input, 2048, stdin);

        // echo the call
        printf("No you're a %s", input);
    }
    return 0;
}
