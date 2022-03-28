type 'a btree =
    Empty
  | Node of 'a * 'a btree * 'a btree;;

let rec treemap btree f =
  match btree with
  | Empty -> Empty
  | Node(data, left, right) -> Node(f data, treemap left f, treemap right f);;
