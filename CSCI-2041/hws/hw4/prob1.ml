(*Problem 1 in Homework 4, CSci 2041, Spring 2020*)

let friendsList =
  [ ("a", ["b"; "c"; "d"; "e";]);
    ("b", ["a"; "c"; "d"; "e";]);
    ("c", ["a"; "b"; "d"; "e";]);
    ("d", ["a"; "b"; "c"; "e";]);
    ("e", ["b"; "c"; "d";]);

(*Solution to Part 1a*)

let makePairLists p fl = List.map (fun x -> if (x > p) then ((p, x), fl)
                                            else ((x, p), xl)) fl;;

(*Solution to Part 1b*)

let makeAllPairLists l = List.map (fun (x, y) -> makePairLists x y) l;;

(*Solution to Part 2a*)

let intersect l1 l2 = List.fold_right (fun x acc ->
                          if (List.exists (fun y -> y = x) l2)
                          then x :: acc
                          else acc) l1 [];;

(*solution to Part 2b*)

let rec addOnePair fp l1 =
  match fp with
  | (x, y) -> match l1 with
              | [] -> (x, y) :: []
              | a :: b -> match a with
                          | (c, d) -> if x = c then (x, intersect y d) :: b
                                      else h :: addOnePair p t;;

(*Solution to Part 2c*)

let addAllPairs ppls l = List.fold_left (fun x y -> addOnePair y x) l ppls;;

(*Solution to Part 3*)

let commonFriends l = List.fold_right addAllPairs (makeAllPairLists l) [];;
