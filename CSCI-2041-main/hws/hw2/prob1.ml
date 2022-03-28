                                          (*Solution to Part 1*)

let rec zip lp =
  match lp with
  | ([], _) -> []
  | (_, []) -> []
  | ((x :: l1),(y :: l2)) -> (x, y) :: zip(l1, l2)

(*This function is well typed.  Zip returns "val zip : 'a list * 'b list -> ('a * 'b) list = <fun>".  The function is looking for a tuple of two lists in order to run the third case to return an 'a * 'b list.*)                   

                                          (*Solution to Part 2*)                                         
let rec reverse l =
  match l with
  | [] -> []
  | (h :: t) -> (reverse t) :: h

(*This function is not well typed.  The type error falls in the second case when we attempt to recursevly call the function.  "h" is of type 'a, but the program is looking for an element of type 'b list, but the fucntion is trying to solve this by simply flipping 'a list, not creating the new 'b list.*)                    
 
