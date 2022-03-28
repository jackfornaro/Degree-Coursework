(*#1 Working with records*)

type empItemTy =
  { name : string ;
    phone : string;
    salary : float
  };;

let johnrec =
  { name = "John";
    phone = "x3456";
    salary = 50.1
  };;

let janerec =
  { name = "Jane";
    phone = "x1234";
    salary = 107.3
  };;

let joanrec =
  { name = "Joan";
    phone = "unlisted";
    salary = 12.7
  };;

let smalldb = [johnrec; janerec; joanrec];;

let find_salary lst n =
  match lst with
  | Empty -> None
  | (h::t) -> if h.name = n then Some h.salary else find_salary t n;;

let find_phno lst n =
  match lst with
  | Empty -> None
  | (h::t) -> if h.name = n then Some h.phone else find_phno t n;;



(*#2 Designing Representations for Data*)

type nestedlist ty;;
                 
