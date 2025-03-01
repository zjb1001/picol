#include "picol_test.h"

void test_performance() {
    struct picolInterp interp;
    picolInitInterp(&interp);
    picolRegisterCoreCommands(&interp);
    
    clock_t start, end;
    double cpu_time_used;
    
    // Test 1: Large loop
    printf("Performance test: Executing a loop with 10,000 iterations...\n");
    start = clock();
    assert_eval_result(&interp, "set x 0", "0", PICOL_OK);
    assert_eval_result(&interp, "set i 0", "0", PICOL_OK);
    assert_eval_result(&interp, "while {< $i 10000} {set x [+ $x 1]; set i [+ $i 1]}", "", PICOL_OK);
    assert_eval_result(&interp, "set x", "10000", PICOL_OK);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Loop completed in %f seconds\n", cpu_time_used);
    
    // Test 2: Recursive factorial
    printf("\nPerformance test: Computing factorial recursively...\n");
    assert_eval_result(&interp, 
        "proc factorial {n} {if {<= $n 1} {return 1} else {return [* $n [factorial [- $n 1]]]}}",
        "", PICOL_OK);
    start = clock();
    assert_eval_result(&interp, "factorial 10", "3628800", PICOL_OK);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Factorial(10) computed in %f seconds\n", cpu_time_used);
    
    // Test 3: Fibonacci sequence (stress test for recursive calls)
    printf("\nPerformance test: Computing Fibonacci recursively...\n");
    assert_eval_result(&interp, 
        "proc fib {n} {if {<= $n 1} {return $n} else {return [+ [fib [- $n 1]] [fib [- $n 2]]]}}",
        "", PICOL_OK);
    start = clock();
    assert_eval_result(&interp, "fib 20", "6765", PICOL_OK);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Fibonacci(20) computed in %f seconds\n", cpu_time_used);
    
    // Test 4: String operations
    printf("\nPerformance test: String concatenation...\n");
    assert_eval_result(&interp, "set str \"\"", "", PICOL_OK);
    start = clock();
    assert_eval_result(&interp, "set i 0", "0", PICOL_OK);
    assert_eval_result(&interp, "while {< $i 1000} {set str \"${str}a\"; set i [+ $i 1]}", "", PICOL_OK);
    assert_eval_result(&interp, "set strlen [* $i 1]", "1000", PICOL_OK);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Created a string of length 1000 in %f seconds\n", cpu_time_used);
    
    // Test 5: Memory allocation stress test
    printf("\nPerformance test: Memory allocation stress...\n");
    start = clock();
    for (int i = 0; i < 1000; i++) {
        char varname[32];
        sprintf(varname, "var%d", i);
        char value[32];
        sprintf(value, "%d", i);
        assert_eval_result(&interp, "proc dummy {} {return 1}", "", PICOL_OK);
        char cmd[64];
        sprintf(cmd, "set %s %s", varname, value);
        assert_eval_result(&interp, cmd, value, PICOL_OK);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Created and set 1000 variables in %f seconds\n", cpu_time_used);
    
    printf("\nAll performance tests completed!\n");
}

#ifdef TEST_STANDALONE
int main() {
    printf("====== PICOL PERFORMANCE TESTS ======\n\n");
    test_performance();
    printf("\n====== ALL PERFORMANCE TESTS COMPLETED ======\n");
    return 0;
}
#endif
