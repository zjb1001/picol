#ifndef PICOL_TEST_H
#define PICOL_TEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

// Redefine main in picol.c to avoid conflict with our test main
#define main picol_main
#include "../picol.c"
#undef main

// Helper function to evaluate a script and check the result
void assert_eval_result(struct picolInterp *i, const char *script, const char *expected, int expected_code) {
    int code = picolEval(i, (char *)script);
    assert(code == expected_code);
    if (expected != NULL) {
        assert(strcmp(i->result, expected) == 0);
    }
}

#endif /* PICOL_TEST_H */
