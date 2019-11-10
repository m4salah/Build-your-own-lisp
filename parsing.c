#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>
#include "mpc.h"
/** #include <editline/history.h> */

int
main(){
    /* Create Some Parsers */
    mpc_parser_t* Number   = mpc_new("number");
    mpc_parser_t* Operator = mpc_new("operator");
    /** mpc_parser_t* FNumber   = mpc_new("float_number"); */
    mpc_parser_t* Expr     = mpc_new("expr");
    mpc_parser_t* Lispy    = mpc_new("lispy");

    /* Define them with the following Language */
    mpca_lang(MPCA_LANG_DEFAULT,
    "                                                       \
        number       : /-?[0-9]+/ ;                             \
        operator     : '+' | '-' | '*' | '/' | '%';             \
        expr         : <number> | '(' <operator> <expr>+ ')' ;  \
        lispy        : /^/ <operator> <expr>+ /$/ ;             \
    ",
      Number, Operator, Expr, Lispy);
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

        /* Attempt to Parse the user Input */
        mpc_result_t r;
        if (mpc_parse("<stdin>", input, Lispy, &r)) {
            /* On Success Print the AST */
            mpc_ast_print(r.output);
            mpc_ast_delete(r.output);
        } 
        else {
            /* Otherwise Print the Error */
            mpc_err_print(r.error);
            mpc_err_delete(r.error);
        }

        free(input);
    }
    /* Undefine and Delete our Parsers */
    mpc_cleanup(4, Number, Operator, Expr, Lispy);
    return 0;
}
