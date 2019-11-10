#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>

/** #include <editline/history.h> */

int
main(){
    /* Pring usfull staff */
    puts("Lisp version 0.0.0.0.1");
    puts("Tht\'s will be fun :)");
    puts("Press ctr-c to Exit\n");

    // infinte loooooooooooooooop

    while(!0){
        
        // out prompt and get history
        char* input = readline("myLispy> ");
        
        // add input to the history
        add_history(input);

        // echo the call
        printf("No you're a %s as me\n", input) ; // \n mean insert newlinie

        free(input);
    }
    return 0;
}
