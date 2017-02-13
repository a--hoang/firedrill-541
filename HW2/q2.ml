open Core.Std

(* prints array of int ref *)
let print_array a =
  Array.iter a (fun r -> print_int !r; print_char ' ')
;;

(* prints 2d matrix of float *)
let print_matrix a =
  Array.iter a (fun r -> (Array.iter r (fun c -> print_float c; print_char ' '); print_newline ()))
;;

(* returns 3x3 state probability matrix of float for q2 given p,q *)
let q2_matrix p q =
  let transition = Array.make_matrix 3 3 0.0 in
    transition.(0).(0) <- 1.0;
    transition.(0).(1) <- 1.0;
    transition.(0).(2) <- 1.0;
    transition.(1).(0) <- 1.0;
    transition.(1).(1) <- 1.0;
    transition.(1).(2) <- 1.0;
    transition.(2).(0) <- 1.0;
    transition.(2).(1) <- 1.0;
    transition.(2).(2) <- 1.0;
  transition
;;

let rec sum_row matrix row index =
  match index with
  | 0 -> matrix.(row).(0)
  | _ -> matrix.(row).(index) +. (sum_row matrix row (index - 1))
;;

(* run markov simulation for q2 with # of trials and n states *)
let q2_calculate p q trials =
  Random.self_init ();
  let transition = (q2_matrix p q) in
  let table = Array.create 3 (ref 0) in
  let current = ref 0 in
  table.(1) <- (ref 0);
  table.(2) <- (ref 0);
  for i = 0 to trials do (
    let r = (Random.float 1.0) in
    let index = ref 0 in
    while (sum_row transition !current !index) < r do
      (Pervasives.incr index)
    done;
    Pervasives.incr table.(!current);
    current := !index;
    index = ref 0;
  )
  done;
  table
;;

(* 'main' function *)
let () =
  (* let m = q2_matrix 1.0 1.0 in
    print_matrix m;
    print_float (sum_row m 0 2); *)

  print_array (q2_calculate 0.5 0.5 200);
;;
