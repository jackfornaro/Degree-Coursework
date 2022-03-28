(*Problem 3 in Homework 3, CSci 2041, Spring 2020*)


(*Solution to Part 1*)

let rec reduce f lst u =
     match lst with
     | [] -> u
     | (h::t) -> f h (reduce f t u);;

(*The arguments for reduce will be a function f, a list lst and an element u.
If lst is empty then u will be returned.  If the list has a head an tail element,
then call f on the head and recursively call reduce with the arguments f, the
rest of the list t, and the element u.  The end result will be a value of type u.

The returned type will be:
val reduce : ('a -> 'b -> 'b) -> 'a list -> 'b -> 'b = <fun>*)



(*Solution to Part 2*)

let rec forall2 p l1 l2 =
   match (l1,l2) with
   | ([],[]) -> true
   | ([],_) -> false
   | (_,[]) -> false
   | ((h1::t1),(h2::t2)) ->
        (p h1 h2) && (forall2 p t1 t2);;

(*The arguments for forall2 will be a function p, and two lists l1 and l2.
If the two lists are empty then the result returns true, and if there is an
empty list and an element that is not an empty list then the result will return
false.  If each list holds a head and tail element then call the function on 
the head of each list and then recursively call forall2 with p and the
tail of each list.  The end result will be a bool statement of true or false,
depending on what the function p is. 

The returned type will be:
val forall2 : ('a -> 'b -> bool) -> 'a list -> 'b list -> bool = <fun>*)
