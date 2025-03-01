#include "picol_test.h"

void test_edge_cases() {
    struct picolInterp interp;
    picolInitInterp(&interp);
    picolRegisterCoreCommands(&interp);
    
    printf("Testing division by zero...\n");
    assert_eval_result(&interp, "/ 10 0", NULL, PICOL_ERR);
    assert(strcmp(interp.result, "Division by zero") == 0);
    
    printf("Testing non-existent command...\n");
    assert_eval_result(&interp, "nonexistentcommand", NULL, PICOL_ERR);
    assert(strncmp(interp.result, "No such command", 15) == 0);
    
    printf("Testing incorrect argument count...\n");
    assert_eval_result(&interp, "set", NULL, PICOL_ERR);
    assert(strncmp(interp.result, "Wrong number of args", 19) == 0);
    
    printf("Testing non-existent variable...\n");
    assert_eval_result(&interp, "set a $nonexistentvariable", NULL, PICOL_ERR);
    assert(strncmp(interp.result, "No such variable", 16) == 0);
    
    printf("Testing break outside of loop...\n");
    assert_eval_result(&interp, "break", NULL, PICOL_BREAK);
    
    printf("Testing continue outside of loop...\n");
    assert_eval_result(&interp, "continue", NULL, PICOL_CONTINUE);
    
    printf("Testing nested procedure calls with many args...\n");
    const char *proc_def = "proc sum_all {a b c d e} {return [+ $a [+ $b [+ $c [+ $d $e]]]]}";
    assert_eval_result(&interp, proc_def, "", PICOL_OK);
    assert_eval_result(&interp, "sum_all 1 2 3 4 5", "15", PICOL_OK);
    
    printf("Testing procedure with wrong number of arguments...\n");
    assert_eval_result(&interp, "sum_all 1 2 3", NULL, PICOL_ERR);
    assert(strncmp(interp.result, "Proc 'sum_all' called with wrong arg num", 39) == 0);
    
    printf("Testing deeply nested brackets...\n");
    assert_eval_result(&interp, "set a [set b [set c [set d [set e 5]]]]", "5", PICOL_OK);
    assert_eval_result(&interp, "set a", "5", PICOL_OK);
    
    printf("Testing empty command...\n");
    assert_eval_result(&interp, "", "", PICOL_OK);
    
    printf("Testing extremely long variable name...\n");
    char long_var_name[100] = "very_long_variable_name_";
    for (int i = 0; i < 5; i++) strcat(long_var_name, "more_and_more_");
    assert_eval_result(&interp, "set very_long_variable_name_more_and_more_more_and_more_more_and_more_more_and_more_more_and_more_ 42", "42", PICOL_OK);
    
    printf("Testing comments...\n");
    assert_eval_result(&interp, "# This is a comment\nset x 10", "10", PICOL_OK);
    
    printf("Testing return outside of proc...\n");
    assert_eval_result(&interp, "return 10", "10", PICOL_RETURN);
    
    printf("All edge case tests passed!\n");
}

#ifdef TEST_STANDALONE
int main() {
    printf("====== PICOL EDGE CASE TESTS ======\n\n");
    test_edge_cases();
    printf("\n====== ALL EDGE CASE TESTS COMPLETED SUCCESSFULLY ======\n");
    return 0;
}
#endif
