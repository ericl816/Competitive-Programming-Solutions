<?php
    $N = (int) fgets(STDIN);
    $A = array();
    for ($i=0; $i<$N; $i++) array_push($A, (string) fgets(STDIN));
    sort($A);
    for ($i=0; $i<$N; $i++) echo $A[$i], "\n";
?>