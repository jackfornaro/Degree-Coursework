(* Problem 4 in Homework 3, CSci 2041, Spring 2020 *)

(* The definitions of accumulate and reduce *)

let rec accumulate f lst u =
   match lst with
   | [] -> u
   | (h::t) -> accumulate f t (f h u)


let rec reduce f lst u =
   match lst with
   | [] -> u
   | (h::t) -> f h (reduce f t u)   


(* Solution to Part 1 *)

let append l1 l2 = reduce (fun x y -> (x::y)) l1 l2;;

(* Solution to Part 2 *)

let reverse l1 = accumulate (fun x y -> (x::y)) l1 [];;

(* Solution to Part 3 *)

let filter f l1 = reduce (fun x y -> if (f x) then x::y else y) l1 [];;
