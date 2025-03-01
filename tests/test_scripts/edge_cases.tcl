# Edge case tests for Picol

# Empty strings
set empty ""
puts "Empty string: '$empty'"

# Multiple nested commands
set result [+ 1 [* 2 [+ 3 [* 4 5]]]]
puts "Complex nested result: $result"

# Long variable names
set this_is_a_very_long_variable_name_to_test_the_parser_limits 42
puts $this_is_a_very_long_variable_name_to_test_the_parser_limits

# Comments in different positions
# Comment at the beginning
set a 10 # Comment after a command
puts $a

# Escaping special characters
set escaped "This has \[ brackets \] and \$ dollar signs"
puts $escaped

# Command with many arguments
proc many_args {a b c d e f g h i j} {
    return [+ $a [+ $b [+ $c [+ $d [+ $e [+ $f [+ $g [+ $h [+ $i $j]]]]]]]]]
}
puts [many_args 1 2 3 4 5 6 7 8 9 10]

# Empty command
puts ""

# Zero division test (should cause an error)
# puts [/ 5 0]
