# Push swap
Quicksort implementation with 2 stacks and limited movements.

ARG=\`ruby -e "puts (1..500).to_a.shuffle.join(' ')"\`; ./push_swap $ARG | ./checker $ARG

![](push-swap.gif?raw=true "push_swap")
