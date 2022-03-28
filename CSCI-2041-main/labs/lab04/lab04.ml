(*Problem 1*)

let rec pairwith x l =
  match l with
  | [] -> []
  | (h :: t) -> (x, h) :: pairwith x t


let rec addN l n =
  match l with
  | [] -> []
  | (h :: t) -> (h+n) :: addN t n


let rec addN =
  function
  | (_,[]) -> []
  | (n, (h :: t)) -> (h + n) :: addN (n, t)


let rec assoc l x =
  match l with
  | [] -> "Not found"
  | ((y, v) :: t) -> if (x = y) then v else assoc t x



let lengthOfHead l =
  let rec length =
        function
        | [] -> 0
        | (h :: t) -> 1 + length t
            in match l with
               | [] -> 0
               | (h :: t) -> length h


(*Problem 2*)

let (f,s) = (1,2) in f + s
                         
                               
