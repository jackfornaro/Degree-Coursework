(*Problem 3 in Homework 4, CSci 2041, Spring 2020*)

(*Solution to Part 1*)

let rec reverse l =
  match l with
  | [] -> []
  | (h :: t) -> (reverse t) @ [h];;

(*Type:  cont_reverse : 'a list -> ('a list -> 'b) -> 'b*)
(*Parameters:  l is a list and c is a function*)
let rec cont_reverse l c =
  match l with
  | [] -> c []
  | (h :: t) -> cont_reverse t (fun x -> c (x @ [h]));;
(*The output is to be the reversed list by calling the c function on the list*)

(*Solution to Part 2*)

type 'a btree = Empty | Node of 'a * 'a btree * 'a btree;;

let rec sumTree t =
  match t with
  | Empty -> 0
  | Node(i, l, r) -> i + sumTree l + sumTree r;;

(*Type:  cont_sumTree : int btree -> (int -> 'a) -> 'a*)
(*Parameters:  t is the tree and c is a function*)
let rec cont_sumTree t c =
  match t with
  | Empty -> c 0
  | Node(i, l, r) -> cont_sumTree l (fun x -> c(x + i + cont_sumTree r
                                                         (fun y -> y)));;
(*The output is the sum of all the elements in the tree and using the c function to determine order*)          
