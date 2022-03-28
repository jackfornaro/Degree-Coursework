(*Problem 2 in Homework 4, CSci 2041, Spring 2020*)

(*Solution to Part 1*)

type 'a olist =
  {data : 'a list; comp : 'a -> 'a -> bool;};;

(*Solution to Part 2*)

(*Type:  ('a -> 'a -> bool) -> 'a olist*)
(*Parameters: f is a function that will be used to compare data*)
let initOList f = {data = []; comp = f};;

(*Solution to Part 3*)

let list1 = {data = [1;2;3;4;5] : comp = (fun (x : int) (y : int) -> x < y)};;
let list2 = {data = [5;4;3;2;1] : comp = (fun (x : int) (y : int) -> x > y)};;
let list3 = {data = ["a";"b";"c";"d"] : comp = (fun (x : string) (y : string)
                                               -> x < y)};;
let list4 = {data = [5;2;7;3] : comp = (fun (x : int) (y : int) -> x < y);;


(*Solution to Part 4*)

(*Type:  ('a olist) -> bool*)
(*Parameters:  lst is an olist that holds data and a comparison*)             
let rec isOrderedList lst =
  match lst.data with
  | [] -> true
  | h :: [] -> true
  | (a :: b :: c) -> lst.comp a b &&
                       isOrderedList {data = b :: c; comp = lst.comp};;
(*The output is to tell us whether or not the list is ordered by using boolean statements*)

(*Solution to Part 5*)

(*Type:  'a -> ('a olist) -> ('a olist)*)
(*Parameters:  e is the element to be inserted and lst is the olist*)
let rec insertOList e lst =
  match lst.data with
  | [] -> {data = [e]; comp = lst.comp}
  | (a :: b) -> if lst.comp e a then {data = (e :: (a :: b)) : comp = lst.comp}
                else {data = (a :: (insertOList e {data = b : comp = lst.comp).data) : comp = lst.comp};;
(*The output is to be element e inserted into the correctly ordered olist*)                      
(*Solution to Part 6*)

(*Type:  'a olist -> 'a list*)
(*Parameters:  lst is an olist*)
let rec olistToList lst = lst.data;;
(*The output is the lst.data, which is just a regular 'a list*)                      
                               
