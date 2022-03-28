let rec map2 f lst1 lst2 =
  match lst1 with
  | [] -> []
  | (h :: t) -> match lst2 with
                | [] -> []
                | (a :: b) -> (f h a) :: map2 f t b;;


