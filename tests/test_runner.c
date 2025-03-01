#include "picol_test.h"

// Test function declarations
void test_basic_functionality();
void test_edge_cases();
void test_performance();

// Helper function to run and report on tests
void run_and_print_test(const char *test_name, void (*test_function)()) {
    printf("Running %s...\n", test_name);
    test_function();
    printf("%s completed successfully.\n\n", test_name);
}

int main(int argc, char **argv) {
    printf("====== PICOL TEST SUITE ======\n\n");
    
    // If arguments are provided, run specific tests
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "basic") == 0) {
                run_and_print_test("Basic Functionality Tests", test_basic_functionality);
            } else if (strcmp(argv[i], "edge") == 0) {
                run_and_print_test("Edge Case Tests", test_edge_cases);
            } else if (strcmp(argv[i], "performance") == 0) {
                run_and_print_test("Performance Tests", test_performance);
            } else {
                printf("Unknown test category: %s\n", argv[i]);
                printf("Available categories: basic, edge, performance\n");
                return 1;
            }
        }
    } else {
        // Run all tests
        run_and_print_test("Basic Functionality Tests", test_basic_functionality);
        run_and_print_test("Edge Case Tests", test_edge_cases);
        run_and_print_test("Performance Tests", test_performance);
    }
    
    printf("\n====== ALL TESTS COMPLETED ======\n");
    return 0;
}

// Include test implementations
#include "test_basic.c"
#include "test_edge.c"
#include "test_performance.c"
