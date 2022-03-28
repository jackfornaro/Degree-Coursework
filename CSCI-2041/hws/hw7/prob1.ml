(* Solution to Problem 1, Homework 7, CSci 2041, Spring 2020 *)


(* The function definitions relevant to this problem *)

let rec map f l =
   match l with
   | [] -> []
   | (h::t) -> (f h) :: map f t

let sqr n = n * n

let rec take l n =
  match (l,n) with
  | ((_,0) | ([],_)) -> []
  | (h::t,n) -> h :: (take t (n-1))


(* Problem 1, Part 1
   Call-by-name evaluation of the expression (take (map sqr [1;2;3]) 2) *)

(*
(take (map sqr [1;2;3]) 2)
(take (1 :: (map sqr [2;3]) 2)
1 :: (take (map sqr [2;3]) 1)
1 :: (take (4 :: (map sqr [3]) 1)
1 :: 4 (take (map sqr [3] 0))
   = [1;4]
*)

(* Problem 1, Part 2
   Call-by-value evaluation of the expression (take (map sqr [1;2;3]) 2) *)

(*
(take (map (sqr [1;2;3]) 2)
(take (1 :: map (sqr [2;3]) 2)
(take (1 :: 4 :: (map (sqr [3]) 2)
(take (1 :: 4 :: 9 :: []) 2)
1 :: (take (4 :: 9 :: []) 1)
1 :: 4 (take 9 :: []) 0)
   = [1;4]
*)
