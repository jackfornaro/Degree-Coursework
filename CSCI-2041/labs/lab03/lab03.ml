# let rec sumup x = if x > 0 then x + sumup (x - 1) else x;;
(*adding up recursive calls of sumup (x - 1)*)
val sumup : int -> int = <fun>


            
# let flip_pair (x, y) = 
    match (x, y) with
      (x, y) -> (y, x)
  ;;
val flip_pair : 'a * 'b -> 'b * 'a = <fun>


(*This one gives warning 8:  This pattern-matching is not exhaustive*)
# let rec flip_list [(x, y); (a, z)] =
    match [(x, y); (a, z)] with
      [(x, y); (a, z)] -> [(y, x); (z, a)]              
  ;;
  val flip_list : ('a * 'b) list -> ('b * 'a) list = <fun>

let rec flip_list lst1 =
  match lst1 with
  | [] -> []
  | (x, y) :: t ->  (flip_pair y x) :: t

                            

(*I don't understand this one*)                                                       
# let rec destutter =
    function
      |  [] -> []
      |  (x::y::l) ->
          if (x=y) then destutter (x::l) else x :: destutter (y::l);;


(*I don't understand this one*)
# let rec sum_diffs =
    function
    | [] -> [0]
    | [a] -> [0]


(*I don't understand this one*)
# let rec unzip (a, b) =
    match (a, b) with
    | (a, b) -> unzip(a :: [], b :: [])
                  

(*I don't understand this one*)
# let f x n = if n = 0 then x = 1 else n - m (f (n-1))
# let m x n =                                      

