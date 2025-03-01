# Performance test for Picol

# Fibonacci calculation (recursive - inefficient but good for testing)
proc fib {n} {
    if {<= $n 1} {
        return $n
    } else {
        return [+ [fib [- $n 1]] [fib [- $n 2]]]
    }
}

puts "Starting Fibonacci calculation..."
set start_fib 15
puts "Fibonacci($start_fib) = [fib $start_fib]"

# Large loop test
puts "Starting large loop test..."
set sum 0
set i 0
while {< $i 1000} {
    set sum [+ $sum $i]
    set i [+ $i 1]
}
puts "Sum from 0 to 999: $sum"

# String concatenation test
puts "Starting string concatenation test..."
set str ""
set i 0
while {< $i 100} {
    set str "${str}a"
    set i [+ $i 1]
}
puts "Created string of length $i"

puts "Performance tests completed."
