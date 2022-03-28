(*Problem 4 in Homework 4, CSci 2041, Spring 2020*)

(*Solution to Part 1a*)

(*The type would be: 'a -> ('b * ('a * 'b)) -> 'c *)

(*Solution to Part 1b*)

let dostat exp stat =
  fun s -> seq (stat) (ifstat exp (dostat exp stat) (fun x -> x)) s
(*Solution to Part 2a*)

(*For this declaration, we need an int for the i, an int for the n, and an int for the sum.*)
                        
type state = int * int * int;;                                

(*Solution to Part 2b*)

let getI (i, sum, n) = i;;
let getSum (i, sum, n) = sum;;
let getN (i, sum, n) = n;;

let putI exp =
  fun s -> let (i, sum, n) = s in (s, sum, n);;

let putSum exp =
  fun s -> let (i, sum, n) = s in (i, s, n);;

let putN exp =
  fun s -> let (i, sum, n) = s in (i, sum, s);;

(*Solution to Part 2c*)

let sumup = seq (putI (fun s -> 0))
   (seq (putSum (fun s -> 0)
      (dostat (fun s -> getI s < getN s)
         (seq (putI (fun s -> getI s + 1)
            (putSum (fun s -> getSum s + getI s)))))));;
(*The output is to be the sum of integers i up to n*)                       
                                  
(*Solution to Part 3*)

(*Type: sumToN : int -> int*)
(*Parameters:  num is the number that the values will be summed to*)
let sumToN num = getSum(sumup (0 0 num));;                                  
(*The output is to be the sum of the numbers up to the value num*)                                       
