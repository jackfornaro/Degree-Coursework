(*Solution to Part 1*)

type ('a, 'b) btree =
  | Empty
  | Node of 'a * 'b * ('a * 'b)btree * ('a * 'b)btree;;

(*Solution to Part 2*)

let inttree = Empty;;

(*Solution to Part 3*)

let tree1 = (17, "Tom", Empty, Empty);;
let tree2 = ("Billy", ("708-593-6666", 100), Empty, Empty);;

(*Solution to Part 4*)

let find tree key =
  match tree with
  | Empty -> None
  | Node(a, b, c, d) -> if a = key then Some b
                        else if a > key then find c key
                        else find d key;;

(*Solution to Part 5*)

let insert tree key value =
  match tree with
  | Empty -> Node(key, value, Empty, Empty)
  | Node(a, b, c, d) -> if a = key then Node(key, value, c, d)
                        else if a < key then Node(a, b, c, insert d key value)
                        else Node(a, b, insert c key value d);;

(*Solution to Part 6*)

let keyList tree =
  match tree with
  | Empty -> []
  | Node(a, b, c, d) -> keyList c @ a :: keyList d;;

(*Solution to Part 7*)
let rec maxKey t =
  match t with
  | Node (key, value, l, Empty) -> key
  | Node (key, value, l, r) -> maxTree r;;

let delete t k =
  let rec delete_aux tree =
  match tree with
  | Empty -> tree
  | Node(key, value, Empty, r) ->
     if k = key then Node (key, value, Empty, delete_aux r)
     else r
  | Node (key, value, l, Empty) ->
     if k = key then Node (key, value, delete_aux l, Empty)
     else l
  | Node (key, value, Empty, Empty) -> Empty
  | Node (key, value, l, r) ->
     if k = key then Node (key, value, delete_aux l, r)
     else if k = key then Node (key, value, l, delete_aux r)
     else Node (maxKey l, value, delete (delete_aux l) (maxKey l), r)
  in delete_aux t;;
