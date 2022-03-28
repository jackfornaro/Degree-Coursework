(*let rec map f l =
  match l with
  | [] -> []
  | (h :: t) -> (f h) :: map f t;;

let rec divide_list x lst1 =
  match lst1 with
  | [] -> ([], [])
  | (h :: t) :: _)) -> if x = true then divide_list(fun(h::t) -> h) lst1
                       else divide_list(fun(h::t) -> h) lst1;;*)

(*Problem 1 in Homework 3, CSci 2041, Spring 2020*)

let divide_list x lst =
  let trueList = [] in let falseList = [] in
   let rec divide_list' x (trueList,falseList) lst =                    
   match lst with
   | [] -> (trueList, falseList)
   | (h :: t) -> if x h = true then divide_list' x (h :: trueList, falseList) t
                 else divide_list' x (trueList, h :: falseList) t
  in divide_list' x (trueList, falseList) lst;;

                    
