                               (*Solution to Part A*)

(*The option type allows us to define when the name is not found rather than returning an empty value.*)

                               (*Solution to Part B*)

(*Type: (string * string * float) list) -> string -> float; 'lst1' is the initial list, and 'name' is the name that the program is trying to find at index 'a' of the  embedded list*)

let rec find_salary lst1 name =
    match lst1 with
    | [] -> = None
    | (a, b, c) :: t -> if a = name then Some c else (find_salary t name);;

(*We expect a float to be returned after matching the name index and the name input*)


(*Type: (string * string * float) list) -> string -> string; 'lst1' is the initial list, and 'name' is the name that the program is trying to find at index 'a' of the  embedded lists*)

let rec find_phno lst1 name =
  match lst1 with
  | [] -> None
  | (a, b, c) :: t -> if a = name then Some b else (find_phno t name);;

(*We expect a float to be returned after matching the name index and the name input*)
