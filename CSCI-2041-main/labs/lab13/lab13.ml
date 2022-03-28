(* Copyright (c) Gopalan Nadathur *)


(* Problem 1 *)

(* The code given to you at the outset *)

type 'a stream = Stream of (unit -> 'a * 'a stream)

let mkStream f = Stream f
let nextStream (Stream f) = f ()

let rec fromNStream n = mkStream (fun () -> (n, fromNStream (n+1)))
let natStream = (fromNStream 0)

(* Write the definition of zipStreams below *)

let zipStreams s1 s1 =
  let rec merge s1 s2 =
    fun () -> let (x, rsts1') = nextStream s1
                in (x, merge s2 rsts1')
  in mkStream (merge s1 s2)
   
(* Problem 2 *)

(* The code given to you to analyze *)
let rec fib_aux n i f s =
    if (n = i) then f
    else fib_aux n (i+1) s (f+s)
    
let fib n = fib_aux n 1 1 1


(* Part 1
   Replace this text with the recurrence equation for the running time for
   (fib_aux n i f s) expressed as a function of (n-i).

   T(m) = T(n-1) + T(n-2) + c2 + c3
*)

(* Part 2

   T(m) = T(n-2) + T(n-1) + c2 + c3
        = T(n-2) + c2 + c2 + c3
        = mc2 + c3
   c2 will run m times because there is a recursive call everytime n does not equal i.
   c3 will only occur once because the base case will only return a value once
*)

(* Part 3
   The run-time for the naive version is T(n) >= (2^(ceiling(n/2)))c2 + c
   It seems that the run-time in the naive version will typically take less time than
   the memoization version.  fib_aux takes in more argument and therefore take longer to compile.
*)
   

(* Problem 3 *)

(* The type declarations that set the problem up *)

type color = R | B

type 'a rbtree =
    Empty
  | Node of color * 'a * 'a rbtree * 'a rbtree


(* Part 1 *)

(*is_RBTree_aux : 'a rbtree -> int * bool*)

let rec is_RBTree_aux t =
  let counter n = 0 in
    match t with
    | Empty -> (n, true)
    | Node(x, l, r) -> if x = "R" then match l with
                                       | Node(y, a, b) -> match r with
                                                          | Node(z, c, d) -> if y = "R" || z = "R" then (n+1, false)
                                                                             else if y = "B" then is_RBTree_aux a && isRBTree_aux b
                                                                             else if z = "B" then is_RBTree_aux c && isRBTree_aux d
                                                                             else n+1
                       else is_RBTree_aux l && is_RBTree_aux r

(* Part 2 *)

(*is_RBTree : 'a rbtree -> bool*)

let isRB_Tree t = is_RBTree_aux t
                                                 
(* Part 3 *)

(*bh_RBTree : 'a rbtree -> int option*)

let bh_RBTree t =
  match (is_RBTree_aux t) with
  | Empty -> None
  | (n, result) -> Some n
