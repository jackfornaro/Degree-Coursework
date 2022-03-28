(*Solution to Problem 1*)

(*1. Well-typed, int, int = -4
2. Not well-typed, you cannot add a float and an int together 
3. Not well-typed, you cannot multiply a float by an int 
4. Well-typed, bool, int = 7 
5. Not well-typed, you cannot have a string in an int-type expression 
6. Not well-typed, there must be an else statement 
7. Well-typed, string, string = "hello world" 
8. Not well-typed, "hello" is not a part of the function because of the comma *)


(*Solution to Problem 2*)

(*1. Illegal, there is no value for y
2. Legal, int = 3
3. Illegal, x is unbounded because of the "and"
4. Legal, int = 3
5. Legal, int = 5 *)


(*Solution to Problem 3*)

(*Type: int -> int -> int; 'a' and 'b' are the variables you are trying to find the gcd of*)
let rec gcd a b = if a = 0 then b else if b = 0 then a
                  else if a > b then gcd b (a mod b)
                  else gcd a (b mod a);;
(*We expect one integer value to be the output*)


(*Solution to Problem 4*)

(*Type: int * int -> int * int; 'a' is the numerator and 'b' is the denominator*)
let rec reduced_form (a, b) = if gcd a b = 1 then (a, b)
                              else ((a / gcd a b), (b / gcd a b));;
(*We expect a pair to be returned in the most simplified form*)



(*Solution to Problem 5*)

(*Type: int -> int -> (int list); 'm' is the upper bound value while 'n' is the lower bound value*)
let rec fromMtoN m n = if m < n then []
                       else if (m = n) then [m]
                       else (m :: (fromMtoN (m-1) n));;
(*We expect a list to be returned counting down from m to n*)


(*Solution to Problem 6*)

(*Type: ('a list) -> ('a list); No initial parameters*)
let rec everyOdd =
  function
  | [] -> []
  | [a] -> [a]
  | [a; b] -> [a]
  | (a :: b :: c) -> a :: (everyOdd c);;
(*We expect the list to be returned with every even index omitted*)


(*Solution to Problem 7*)

(*Type: ('a list) -> int -> ('a list); 'lst1' is the initial list, 'n' is the nth value inputted by the user, and 'i' is used to iterate in the keep function*)
let rec everyNth lst1 n =
  let rec keep lst1 i =
  match lst1 with
  | [] -> []
  | (a :: b) -> if n = i then a :: (keep b 1)
                else keep b (i + 1) in keep lst1 1;;
(*We expect the list to be returned with every "nth" index omitted*)


(*Type: ('a list) -> int -> ('a list); 'lst1' is the initial list*)
let rec everyThird lst1 = everyNth lst1 3;;
(*We expect the list to be returned with every third index omitted*)


(*Solution to Problem 8*)

(*Type: (string * string * float) list) -> string -> float; 'lst1' is the initial list, and 'name' is the name that the program is trying to find at index 'a' of the  embedded list*)
let rec find_salary lst1 name =
    match lst1 with
    | [] -> 0.0
    | (a, b, c) :: t -> if a = name then c else (find_salary t name);;
(*We expect a float to be returned after matching the name index and the name input*)


(*Type: (string * string * float) list) -> string -> string; 'lst1' is the initial list, and 'name' is the name that the program is trying to find at index 'a' of the  embedded lists*)
let rec find_phno lst1 name =
  match lst1 with
  | [] -> " "
  | (a, b, c) :: t -> if a = name then b else (find_phno t name);;
(*We expect a float to be returned after matching the name index and the name input*)
                                     
                        
(*Solution to Problem 9*)

(*All successive embedded lists must be of the same length of the first embedded list, and if the length of the first embedded list is zero.*)

(*Type: (int list) list -> bool; 'lst1' is the matrix*)
let rec is_matrix lst1 =
  match lst1 with
  | [] -> true
  | (h :: x) ->  let y = List.length(h) in
                 let rec help lst1 = 
                   match lst1 with
                   | [] -> true
                   | (h :: x) -> if List.length(h) != y then false
                                 else help x
                 in help lst1;;
(*We expect a bool statement to determine whether or not the matrix is a legal one*)


(*Type: (int list) list -> int -> (int list) list; 'm' is the entire matrix, 'lst1' is each embedded list, and 'num' is the number you multiply each element by*)
let matrix_scaler_multiply m =
  let rec helper lst1 num =
    match lst1 with
    | [] -> []
    | (h :: x) -> (num * h :: helper lst1 num)
  in let rec help y =
     match y with
     | [] -> []
     | (h :: x) -> helper h num :: help x num in help m;;
(*We expect a list of lists where each element is multiplied by a scaler 'num'*)
