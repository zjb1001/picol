# More advanced Picol test script

# Recursive procedure
proc factorial {n} {
    if {<= $n 1} {
        return 1
    } else {
        return [* $n [factorial [- $n 1]]]
    }
}

puts "Factorial of 6 is [factorial 6]"

# Nested loops
set result 0
set i 0
while {< $i 5} {
    set j 0
    while {< $j 5} {
        set result [+ $result 1]
        set j [+ $j 1]
    }
    set i [+ $i 1]
}
puts "5x5 loop result: $result"

# Command substitution and complex expressions
set a 5
set b 3
set c [+ [* $a $a] [* $b $b]]
puts "a^2 + b^2 = $c"

# Break and continue
set sum 0
set i 1
while {<= $i 10} {
    if {== $i 5} {
        set i [+ $i 1]
        continue
    }
    if {== $i 8} {
        break
    }
    set sum [+ $sum $i]
    set i [+ $i 1]
}
puts "Sum (skipping 5, stopping at 8): $sum"
