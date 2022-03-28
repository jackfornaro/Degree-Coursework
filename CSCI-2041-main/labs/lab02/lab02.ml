(* OCaml file for lab 02.
   Fix the errors in this file. *)

let five = (2 + 3)

let myfun x = x.[2]

let mult x y = x * y

let two = 2             
let plus_two x = x + two
              
let and3 x y z = x && y && z

let helloworld = "hello" ^  "world"

let three_or_ten x = if x then 3 else 10
let three = three_or_ten true
let ten = three_or_ten (5 < 2)


let nine = mult (three_or_ten true) (three_or_ten (2 < 4))

let mult_or_plus a b x = if (three_or_ten x < 5) then (2 * a) else (2 + b)

                                                                  

                            
