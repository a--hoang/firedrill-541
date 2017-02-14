open Core.Std

(* prints array of int ref *)
let print_int_ref_array a =
  Array.iter a (fun r -> print_int !r; print_char ' ')
;;

let print_float_array a =
  Array.iter a (fun r -> print_float r; print_char ',');
  print_char ';';
  print_newline ()
;;

(* prints 2d matrix of float *)
let print_matrix a =
  Array.iter a (fun r -> (Array.iter r (fun c -> print_float c; print_char ' '); print_newline ()))
;;

(* returns 3x3 state probability matrix of float for q2 given p,q *)
let q2_matrix p q =
  let transition = Array.make_matrix 3 3 0.0 in
    transition.(0).(0) <- 0.0;
    transition.(0).(1) <- (1.0 -. p);
    transition.(0).(2) <- p;
    transition.(1).(0) <- 1.0;
    transition.(1).(1) <- 0.0;
    transition.(1).(2) <- 1.0;
    transition.(2).(0) <- 0.0;
    transition.(2).(1) <- q;
    transition.(2).(2) <- (1.0 -. q);
  transition
;;

(* sum elements of a row of a matrix from matrix[row][0] to matrix[row][index] *)
let rec sum_row matrix row index =
  match index with
  | 0 -> matrix.(row).(0)
  | _ -> matrix.(row).(index) +. (sum_row matrix row (index - 1))
;;

let rec sum_row_arr arr index =
  match index with
  | 0 -> !(arr.(0))
  | _ -> !(arr.(index)) + (sum_row_arr arr (index - 1))
;;

(* return percentages of states (arr[i]/sum_row arr) *)
let row_percentages arr =
  let sum = float_of_int(sum_row_arr arr (Array.length arr - 1)) in
  let output = Array.create (Array.length arr) 0.0 in
  for i = 0 to (Array.length arr - 1) do
    output.(i) <- float_of_int(!(arr.(i))) /. sum
  done;
  output
;;

(* run markov simulation for q2 with # of trials and n states *)
(* returns array where arr[i] = time spent in stage i *)
let q2_calculate p q trials =
  Random.self_init ();
  let transition = (q2_matrix p q) in
  let table = Array.create 3 (ref 0) in
  let current = ref 0 in
  table.(1) <- (ref 0);
  table.(2) <- (ref 0);
  for i = 1 to trials do (
    let r = (Random.float 1.0) in
    let index = ref 0 in
    while (sum_row transition !current !index) < r do
      (Pervasives.incr index)
    done;
    Pervasives.incr table.(!current);
    current := !index;
    index := 0;
      print_float_array (row_percentages table);
  )
  done;
;;

let q3_matrix a d1 d2 =
  let transition = Array.make_matrix 4 4 0.0 in
    transition.(0).(0) <- (1.0 -. a);
    transition.(0).(1) <- a;
    transition.(0).(2) <- 0.0;
    transition.(0).(3) <- 0.0;
    transition.(1).(0) <- 0.0;
    transition.(1).(1) <- (1.0 -. d1);
    transition.(1).(2) <- d1;
    transition.(1).(3) <- 0.0;
    transition.(2).(0) <- ((1.0 -. a) *. d2);
    transition.(2).(1) <- (a *. d2);
    transition.(2).(2) <- ((1.0 -. a) *. (1.0 -. d2));
    transition.(2).(3) <- (a *. (1.0 -. d2));
    transition.(3).(0) <- 0.0;
    transition.(3).(1) <- d2;
    transition.(3).(2) <- 0.0;
    transition.(3).(3) <- (1.0 -. d2);
  transition
;;

let q3_calculate a d1 d2 trials =
  Random.self_init ();
  let transition = (q3_matrix a d1 d2) in
  let completions = ref 0 in
  let current = ref 0 in
  for i = 1 to trials do (
    let r = (Random.float 1.0) in
    let index = ref 0 in
    while (sum_row transition !current !index) < r do
      (Pervasives.incr index)
    done;
    if (!current == 2 && !index == 0) || (!current == 3 && !index == 1) then
      Pervasives.incr completions
    ;
    current := !index;
    index := 0;
    print_float (float_of_int !completions /. float_of_int trials);
    print_newline ();
  )
  done;
;;

(* 'main' function *)
let () =
  q3_calculate 0.5 0.5 0.5 2000;
;;
