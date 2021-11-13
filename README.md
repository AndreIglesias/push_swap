# Push swap
Quicksort implementation with 2 stacks and limited movements.

`ARG=\`ruby -e "puts (1..500).to_a.shuffle.join(' ')"\`; ./push_swap $ARG | ./checker $ARG`

# Interface
`cd interface`
`python3 sorting.py \`ruby -e "puts (1..500).to_a.shuffle.join(' ')"\``

![](push-swap.gif?raw=true "push_swap")
