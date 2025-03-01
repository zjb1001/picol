#include "picol_test.h"

void test_basic_functionality() {
    struct picolInterp interp;
    picolInitInterp(&interp);
    picolRegisterCoreCommands(&interp);
    
    printf("Testing arithmetic operations...\n");
    assert_eval_result(&interp, "set a 5", "5", PICOL_OK);
    assert_eval_result(&interp, "set b 3", "3", PICOL_OK);
    assert_eval_result(&interp, "+ $a $b", "8", PICOL_OK);
    assert_eval_result(&interp, "- $a $b", "2", PICOL_OK);
    assert_eval_result(&interp, "* $a $b", "15", PICOL_OK);
    assert_eval_result(&interp, "/ $a $b", "1", PICOL_OK);
    
    printf("Testing conditional execution...\n");
    assert_eval_result(&interp, "if {> $a $b} {set result \"a is greater\"}", "a is greater", PICOL_OK);
    assert_eval_result(&interp, "if {< $a $b} {set result \"b is greater\"} else {set result \"a is greater or equal\"}", "a is greater or equal", PICOL_OK);
    
    printf("Testing loops...\n");
    assert_eval_result(&interp, "set sum 0", "0", PICOL_OK);
    assert_eval_result(&interp, "set i 1", "1", PICOL_OK);
    assert_eval_result(&interp, "while {<= $i 10} {set sum [+ $sum $i]; set i [+ $i 1]}", "", PICOL_OK);
    assert_eval_result(&interp, "set sum", "55", PICOL_OK);
    
    printf("Testing procedures...\n");
    const char *proc_def = "proc add {a b} {return [+ $a $b]}";
    assert_eval_result(&interp, proc_def, "", PICOL_OK);
    assert_eval_result(&interp, "add 5 7", "12", PICOL_OK);
    
    printf("Testing nested commands...\n");
    assert_eval_result(&interp, "set x [+ 1 [* 2 3]]", "7", PICOL_OK);
    
    printf("Testing variable interpolation...\n");
    assert_eval_result(&interp, "set greeting \"Hello, world!\"", "Hello, world!", PICOL_OK);
    assert_eval_result(&interp, "puts $greeting", "", PICOL_OK);
    
    printf("Testing comparison operators...\n");
    assert_eval_result(&interp, "== 5 5", "1", PICOL_OK);
    assert_eval_result(&interp, "!= 5 5", "0", PICOL_OK);
    assert_eval_result(&interp, "< 3 5", "1", PICOL_OK);
    assert_eval_result(&interp, "<= 5 5", "1", PICOL_OK);
    assert_eval_result(&interp, "> 5 3", "1", PICOL_OK);
    assert_eval_result(&interp, ">= 5 5", "1", PICOL_OK);
    
    printf("All basic functionality tests passed!\n");
}

#ifdef TEST_STANDALONE
int main() {
    printf("====== PICOL BASIC FUNCTIONALITY TESTS ======\n\n");
    test_basic_functionality();
    printf("\n====== ALL BASIC TESTS COMPLETED SUCCESSFULLY ======\n");
    return 0;
}
#endif
