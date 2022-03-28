(* Solution to Problem 2, Homework 7, CSci 2041, Spring 2020 *)

(* First, some declarations providing the stream abstraction *)

type 'a stream =
   Stream of (unit -> 'a * 'a stream)

let mkStream f = Stream f
let nextStream (Stream f) = f ()

(* Next some definitions that provide a natural number stream *)

let rec fromNStream n = mkStream (fun () -> (n, fromNStream (n+1)))

let natStream = (fromNStream 0)


(* Solution to Part 1, Problem 2 *)

(*mapStream : ('a -> 'b) -> 'a stream -> 'b stream*)
let rec map f s =
  fun () -> let (x, rst) = nextStream s
                         in (f x, mkStream(map f rst));;

let mapStream f s = mkStream(map f s);;      

(* Solution to Part 2, Problem 2 *)

(*squareStream : int stream*)
let squareStream = mapStream (fun x -> x * x) natStream;;

(*cubeStream : int stream*)
let cubeStream = mapStream (fun x -> x * x * x) natStream;;
   
(* Solution to Part 3, Problem 2 *)

(*squarecubeStream : int stream*)
let squarecubeStream = let (x, rst) = nextStream(squarecubeStream_aux) in rst;;

let squarecubeStream_aux =
  let rec SCS_aux2 ns nc s c =
    if ns < nc then let (ns2, s2) = nextStream s in SCS_aux2 ns2 nc s2 c
    else if ns > nc then let (nc2, c2) = nextStream c in SCS_aux2 ns nc2 s c2
    else let (ns2, s2) = nextStream s in let (nc2, c2) =                                                       
                                           nextStream c in mkStream(fun () -> (ns, SCS_aux2 ns2 nc2 s2 c2))
  in let (ns, s) = nextStream squareStream in let (nc, c) =
                                                nextStream cubeStream in mkStream (fun () -> 0, SCS_aux2 ns nc s c);;
