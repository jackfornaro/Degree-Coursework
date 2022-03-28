(* Problem 5 in Homework 3, CSci 2041, Spring 2020 *)

(* The type for expressions and the new name function given in the homework appear below *)

type expr =
       Id of string                   (* for identifiers *)
     | Int of int                     (* for integers *)
     | True                           (* for the boolean value true *)
     | False                          (* for the boolean value false *)
     | Plus of (expr * expr)          (* for exp1 + exp2 *)
     | Minus of (expr * expr)         (* for exp1 - exp2 *)
     | Times of (expr * expr)         (* for exp1 * exp2 *)
     | Div of (expr * expr)           (* for exp1 / exp2, division being for integers *)
     | Lss of (expr * expr)           (* for exp1 < exp2 *)
     | Eq of (expr * expr)            (* for exp1 = exp2, = being equality comparison *)
     | Gtr of (expr * expr)           (* for exp1 > exp2 *)
     | And of (expr * expr)           (* for exp1 && exp2 *)
     | Or of (expr * expr)            (* for exp1 || exp2 *)
     | Not of expr                    (* for not exp *)
     | Cond of (expr * expr * expr)   (* for if exp1 then exp2 else exp3 *)
     | Let of (string * expr * expr)  (* for let <id> = exp1 in exp2 *)
     | Fun of (string * expr)         (* for fun (x:ty) -> exp *)
     | App of (expr * expr)           (* for (exp1 exp2) *)

let namecounter = ref 0
let newname () =
     ( namecounter := !namecounter + 1; "var" ^ string_of_int !namecounter)



(* Solution to Part 1 *)

let rec freeIn expr name =
  match expr with
  | Id (x) -> if x = name then true else false
  | Int (1) -> true
  | True -> true
  | False -> false
  | Plus(e1, e2) -> if freeIn e1 name = true || freeIn e2 name = true then true else false
  | Minus(e1, e2) -> if freeIn e1 name = true || freeIn e2 name = true then true else false
  | Times(e1, e2) -> if freeIn e1 name = true || freeIn e2 name = true then true else false
  | Div(e1, e2) -> if freeIn e1 name = true || freeIn e2 name = true then true else false
  | Lss(e1, e2) -> if freeIn e1 name = true || freeIn e2 name = true then true else false
  | Eq(e1, e2) -> if freeIn e1 name = true || freeIn e2 name = true then true else false
  | Gtr(e1, e2) -> if freeIn e1 name = true || freeIn e2 name = true then true else false
  | And(e1, e2) -> if freeIn e1 name = true || freeIn e2 name = true then true else false
  | Or(e1, e2) -> if freeIn e1 name = true || freeIn e2 name = true then true else false
  | Not(e1) -> if freeIn e1 name = true then true else false
  | Cond(e1, e2, e3) -> if freeIn e1 name = true || freeIn e2 name = true || freeIn e3 name = true then true else false
  | Let(e1, x, e2) -> if freeIn e1 name = true then true else false
  | Fun(arg, exp) -> if arg = name then false else if freeIn exp name = true then true else false
  | App(e1, e2) -> if freeIn e1 name = true || freeIn e2 name = true then true else false;;
                 

(* Solution to Part 2 *)

let subst expr name newExpr =
  match expr with
  | Id (x) if x = name then x = newExpr
  | Plus(e1, e2) -> if e1 = name || e2 = name then name = newExpr
  | Minus(e1, e2) -> if e1 = name || e2 = name then name = newExpr 
  | Times(e1, e2) -> if e1 = name || e2 = name then name = newExpr 
  | Div(e1, e2) -> if e1 = name || e2 = name then name = newExpr 
  | Lss(e1, e2) -> if e1 = name || e2 = name then name = newExpr 
  | Eq(e1, e2) -> if e1 = name || e2 = name then name = newExpr 
  | Gtr(e1, e2) -> if e1 = name || e2 = name then name = newExpr
  | And(e1, e2) -> if e1 = name || e2 = name  then name = newExpr 
  | Or(e1, e2) -> if e1 = name || e2 = name then name = newExpr 
  | Not(e1) -> if e1 = name then name = newExpr
  | Let(e1, s, e2) -> if freeIn e1 name = true then name = newExpr
  | Fun(arg, exp) -> if freeIn exp name = true then name = newExpr
  | App(e1, e2) -> if e1 = name || e2 = name then name = newExpr;;
