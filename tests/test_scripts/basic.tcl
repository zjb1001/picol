# Basic Picol test script

# Variable assignment and arithmetic
set a 10
set b 20
set sum [+ $a $b]
puts "Sum: $sum"

# Conditionals
if {> $a 5} {
    puts "$a is greater than 5"
} else {
    puts "$a is not greater than 5"
}

# Loops
set i 1
set factorial 1
while {<= $i 5} {
    set factorial [* $factorial $i]
    set i [+ $i 1]
}
puts "5! = $factorial"

# Procedure definition and call
proc greet {name} {
    return "Hello, $name!"
}

puts [greet "Picol"]
