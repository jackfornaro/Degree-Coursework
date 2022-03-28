(* Solution to Problem 3, Homework 7, CSci 2041, Spring 2020 *)

(* First some definitions that realize the new stream abstraction *)

type 'a stream = Stream of 'a stream_aux ref
and  'a stream_aux =
       | Evald of ('a * 'a stream)
       | UnEvald of (unit -> 'a * 'a stream)

(* Problem 3, Part 1 *)

(* Replace this comment with a definition of the following identifiers
   that will complement the type declarations to realize the new stream
   abstraction. Pay attention to the requirements described in the problem
   writeup, this is important for credit on this problem.
 *)
(*mkStream : (unit -> 'a * 'a stream) -> 'a stream*)
let mkStream e = Stream (ref (UnEvald e));;

(*nextStream : 'a stream -> 'a * 'a stream*)
let nextStream (Stream e) =
  match !e with
  | Evald x -> x
  | UnEvald x -> let y = x () in (e:=Evald y; y)

(* Problem 3, Part 2 *)

let rec fromNStream n = mkStream (fun () -> (n, fromNStream (n + 1)))
                               
(*natStream : int stream*)
let natStream = fromNStream 0;;
  
                                   
