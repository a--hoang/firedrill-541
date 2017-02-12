open Core.Std

let matrix_multiply mata matb =
  let output = Array.make_matrix (Array.length mata) (Array.length(matb.(0))) 0.0 in
    print_int (Array.length output);
;;

(* prints array of int *)
let print_array a =
  Array.iter a (fun r -> print_float r; print_char ' ')
;;

(* prints 2d matrix of  *)
let print_matrix a =
  Array.iter a (fun r -> (Array.iter r (fun c -> print_float c; print_char ' '); print_newline ()))
;;

(* 'main' function *)
let () =
  let transition = Array.make_matrix 4 4 0.0 in
    transition.(0).(0) <- 1.0;
    print_matrix transition;
  print_newline ();
;;
