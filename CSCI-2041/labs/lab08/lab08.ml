(*Solution to Problem 2*)

type 'a btree = Empty | Node of 'a * 'a btree * 'a btree;;

let rec insert x t =
  match t with
  | Empty -> Node(x, Empty, Empty)
  | Node(x', l, r) -> if x < x' then Node(x', insert x l, r)
                      else Node(x', l, insert x r);;

type 'a bstree = {data : 'a btree; comp : 'a -> 'a -> bool;};;

let rec insert x lst =
  match lst.data with
  | Empty -> Node(x, Empty, Empty)
  | Node(x', l, r) -> if lst.comp x 'a then Node(x', insert x l, r)
                      else Node(x', l, insert x r);;

(*Solution to Problem 3*)

let rec cont_append l1 l2 =
  match l1 with
  | [] -> l2
  | (h :: t) -> h :: append t l2;;

                                                  
