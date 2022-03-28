(*Problem 2*)

type 'a mylist = 'a listcell ref
and 'a listcell = Nil | Cons of 'a * ('a mylist) ref;;

(*reverse : 'a mylist -> 'a mylist -> 'a mylist*)

let reverse l = l;;



                                       
