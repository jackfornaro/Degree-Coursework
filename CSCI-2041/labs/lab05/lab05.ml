(*#1 Working with binary trees*)
type 'a btree = Empty
              | Node of 'a btree * 'a * 'a btree;;

let rec maxTree =
  function
  | Empty -> None
  | Node(root, left, right) -> if right = Empty then Some(root) else maxTree(right);;


let rec minTree =
  function
  |  Empty -> None
  |  Node(root, left, right) -> if left = Empty then Some(root) else maxTree(left);;
                                 
let rec isSearchTree t =
   let bigger i j =
     match j with
     | None -> true
     | (Some j') -> i >= j' in
   let smaller i j =
     match j with
     | None -> true
     | Some j' -> j' >= i in
   match t with
   | Empty -> true
   | Node (i,l,r) ->
         isSearchTree l && isSearchTree r &&
           (bigger i (maxTree l)) && (smaller i (minTree r));;

(*#2 Working with Program Representations*)

type ty = IntTy | BoolTy;;
       
let typeof =
  function
  | Plus(e1, e2) -> if e1 = IntTy & e2 = IntTy then IntTy(Plus(e1, e2)) else 0
  | Cond(e1, e2, e3) -> if e1 = BoolTy & e2 = BoolTy & e3 = BoolTy then BoolTy(Cond(e1, e2, e3)) else 0;;


let wellTyped = if typeof(Plus(e1, e2)) || typeof(Cond(e1, e2, e3)) then true else false;;

type ocamlTy = IntTy' | BoolTy';;
                                                                                          
    
                                       
