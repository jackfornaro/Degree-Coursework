type ty = BoolTy | IntTy | FunTy of ty * ty

type expr =
       Id of string                     (* for identifiers *)
     | Int of int                       (* for integers *)
     | True                             (* for the boolean value true *)
     | False                            (* for the boolean value false *)
     | Plus of expr * expr              (* for exp1 + exp2 *)
     | Minus of expr * expr             (* for exp1 - exp2 *)
     | Times of expr * expr             (* for exp1 * exp2 *)
     | Div of expr * expr               (* for exp1 / exp2, division being for integers *)
     | Lss of expr * expr               (* for exp1 < exp2 *)
     | Eq of expr * expr                (* for exp1 = exp2, = being equality comparison *)
     | Gtr of expr * expr               (* for exp1 > exp2 *)
     | And of expr * expr               (* for exp1 && exp2 *)
     | Or of expr * expr                (* for exp1 || exp2 *)
     | Not of expr                      (* for not exp *)
     | Cond of expr * expr * expr       (* for if exp1 then exp2 else exp3 *)
     | Let of string * expr * expr      (* for let <id> = exp1 in exp2 *)
     | Fun of string * ty * expr        (* for fun (x:ty) -> exp *)
     | App of expr * expr               (* for (exp1 exp2) *)
                       

(*Solution to Part 1*)

(*let x = 5 in let y = y in x +y*)

let exp1 = Let("x", Int 5, Let("y", Int 7, Plus(Id "x", Id "y")))
         

(*(fun(x:int) -> (fun(y:bool) -> if y then (x + 1) else x-5))*)
         
let exp2 = (Fun("x", Int),(Fun("y", True),
           Cond(Id "y", Plus(Id "x", Int 1), Minus(Id "x", Int 5))))

(*(fun(x:int) -> ((fun(y:int) -> x + y) x)) 5*)
         
let exp3 = (Fun("x", Int),((Fun("y", Int),
           Plus(Id "x" + Id "y"), "x")) Int 5)

            
(*Solution to Part 2*)

let typeof_aux expr lst =
  match lst with
  | Int x -> Some IntTy
  | bool x -> Some BoolTy
  | fun x -> Some FunTy of ty * ty
  | Plus (e1, e2) -> if typeof_aux e1 * typeof_aux e2 then Some IntTy else None
  | Minus (e1, e2) -> if typeof_aux e1 * typeof_aux e2 then Some IntTy else None
  | Times (e1, e2) -> if typeof_aux e1 * typeof_aux e2 then Some IntTy else None
  | Div (e1, e2) -> if typeof_aux e1 * typeof_aux e2 then Some IntTy else None
  | Lss (e1, e2) -> if typeof_aux e1 * typeof_aux e2 then Some BoolTy else None
  | Gtr (e1, e2) -> if typeof_aux e1 * typeof_aux e2 then Some BoolTy else None
  | Eq (e1, e2) -> if typeof_aux e1 * typeof_aux e2 then Some BoolTy else None
  | Not expr -> typeof_aux expr lst
  | Cond (e1, e2, e3) -> if (typeof_aux e1 lst = Some IntTy)&&(typeof_aux e2 lst = typeof_aux e3 lst)
                     then typeof_aux e2 lst else None
  | Let (e1, e2, e3) -> if typeof_aux e2 [] = Some IntTy then typeof_aux e3 [(e1, IntTy)]
                        else if typeof_aux b [] = Some IntTy then typeof_aux e3 [(e1, IntTy)]
                        else None;;



(*Solution to Part 3*)

let typeof =
  function
  | Empty -> None
  | expr -> Some typeof_aux expr;;

