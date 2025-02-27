Picol is a Tcl-alike interpreter in 500 lines of code that I released 15th of March 2007. Recentely I looked at the source code and realized this was a better C programming example compared to what I recalled, so I'm putting this on GitHub to archive it, together with the main points of the original article.

## Rules
When I built this code, I had some rule in mind:

* I wanted to use more or less my normal C style. In Picol you'll find normal C spacing and even comments.
* I wanted to write an interpreter with a design similar to a real one. One of the few useful things you can do with Picol is to learn how to write a Tcl interpreter if you are a newbie programmer, I guess, so the point was to write a simple to understand program, not just a *short* program.
* The resulting interpreter should be able to run some kind of non trivial program: to just set few vars and print hello world was not an option.

## The resulting interpreter: Picol

The parser is very similar to the Tcl one, Picol supports interpolation as well, for example you can write:

```Tcl
set a "pu"
set b {ts}
$a$b "Hello World!"
```

Note that Picol has an interactive shell! so just launch it without arguments to start to play (to compile the code use `gcc -O2 -Wall -o picol picol.c`).

To run a program stored in a file, use: `picol filename.tcl`.

Probably the parser could be rewritten in order to take less space, currently it takes almost 250 lines of code: this is too much and leaves little room for all the rest. On the other side, it's a decent example about writing parsers by hand.

A Raw list of the supported features:

* Interpolation, as seen above. You can also write `"2+2 = [+ 2 2]"` or `"My name is: $foobar"`.
* Procedures, with return. Like Tcl if return is missing the result of the last command executed is returned.
* `If`, `if .. else ..`, `while` with `break` and `continue`.
* Recursion.
* Variables inside procedures are limited in scope like Tcl, i.e. there are real call frames in Picol.
* The following other commands: `set` `+` `-` `*` `/` `==` `!=` `>` `<` `>=` `<=` `puts`.

This is an example of programs Picol can run:

```Tcl
proc fib {x} {
    if {== $x 0} {
        return 0
    }
    if {== $x 1} {
        return 1
    }
    return [+ [fib [- $x 1]] [fib [- $x 2]]]
}

puts [fib 20]
that of course will output fib(20). Another example:
proc square {x} {
    * $x $x
}
```

Or:

```
set a 1
while {<= $a 10} {
    if {== $a 5} {
        puts {Missing five!}
        set a [+ $a 1]
        continue
    }
    puts "I can compute that $a*$a = [square $a]"
    set a [+ $a 1]
}
```

## Design

* It's pretty straightforward, the first important part you see in the source code is an hand written parser. The main function of the parser is `picolGetToken` that just calls functions able to parse the different parts of a Tcl program and return in the parsing structure the type of the token and start/end pointers in order to extract it.

This parsing function is in turn used by `picolEval` in order to execute the program. Every token is used either to form a new argument if a separator token was found before, or concatenated to the last argument (this is how interpolation is performed in Picol). Once an EOL (end of line) token is returned picolEval will call the command looking it up in a linked list of commands stored inside the interpreter structure.

Variables and commands substitution is performed by `picolEval` itself. The parser is able to return variables and commands tokens already stripped by `$` and `[]`, so all it's required to do is to lookup the variable in the call frame and substitute the value with the token, or to recursively call `picolEval` if it's a command substitution, using the result instead of the original token.

Commands are described by a name and a pointer to a C function implementing the command. In the command structure there is also a private data void pointer used in order to store data private to the command. This makes you able to implement multiple Picol commands using a single C function. User defined procedures are just like commands, but they are implemented by passing as private data the argument list and the body of the procedure, so a single C function is able to implement all the existing user defined procedures.

Procedures call is trivial. The interpreter structure contains a call frame structure having more or less just a pointer to a liked list of variables (that are in turn structures with two fileds: name and value). When a procedure is called a new call frame is created and put at the top of the old one. When the procedure returns the top call frame is destroyed.

**Inside every large program there is a small program trying to get out -- Sir Tony Hoare.**
