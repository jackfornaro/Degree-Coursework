(*Solution to Part 1*)

let rec fib' x fib1 fib2 =
  let rec helper n =
    if x = n then fib1 else fib' n (x + 1) fib2 (fib2 + fib1);;


                                 (*Solution to Part 2*)
                              
(*the value x will iterate by adding one everytime the else case is reached.  
Additionally, fib1 turns into fib2, n remains the same, and fib2 turns into fib1 plus fib2. 
 The output is the value of fib1, which will increase by fib2's value.*)

                                 (*Solution to Part 3*)
let fib n =
  fib' 1 n 1 1 ;;
