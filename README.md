# PUSH_SWAP

> Final Score 125/100

A 42-cursus project where the goal is to sort given range of unique integers using two stacks (A and B) and only following operations:

**sa**: swap a - swap the first 2 elements at the top of stack a.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Do nothing if there is only one or no elements).\
**sb**: swap b - swap the first 2 elements at the top of stack b.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Do nothing if there is only one or no elements).\
**ss**: sa and sb at the same time.\
**pa**: push a - take the first element at the top of b and put it\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;at the top of a. Do nothing if b is empty.\
**pb**: push b - take the first element at the top of a and put it\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;at the top of b. Do nothing if a is empty.\
**ra**: rotate a - shift up all elements of stack a by 1. The first\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;element becomes the last one.\
**rb**: rotate b - shift up all elements of stack b by 1. The first\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;element becomes the last one.\
**rr**: ra and rb at the same time.\
**rra**: reverse rotate a - shift down all elements of stack a by 1.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The last element becomes the first one.\
**rrb**: reverse rotate b - shift down all elements of stack b by 1.\
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;The last element becomes the first one.\
**rrr**: rra and rrb at the same time.

The binary **push_swap** returns a list of operations which if performed on given array of integers makes it sorted.

The binary **checker** performs given commands on given array of integers. And returns message whether the final stack is sorted or not.

## Solution Approach and Algorithm
To solve the project I've been testing many sorting algorithms and pretty much any of them is usable. Those which benefit from additional stack are obviously beneficial here. However the pickle was to figure out which one to use in order to fulfill benchmarks for maximum amout of points.
> 5 numbers - 12 maximum operations\
> 100 numbers - under 700 operations for full score\
> 500 numbers - under 5500 operations for full score

I've tried many few, but ended up with hybrid of quicksort and insertsort, both ajusted to fully optimize rotations.

Firstly I split stack A in such manner than all numbers under the median are pushed to stack B. Then I calculate amount of operations required for every number from stack B to be pushed back on stack in sorted manner (adjusted insertsort). I select the number requiring the least amount of operations. I repeat the two previous steps untill stack B is empty. At this point half of stack A is sorted. I proceed to repeat all previous steps on the unsorted part, getting new median, pushing all numbers for which last_sorted < N <= median, and insertsorting them back while minimizing the amout of operations. Rinse and repeat until the stack A is sorted.

Note: After the project was concluded it turned out that for range under 250 numbers, it is beneficial just to push all numbers except the minimum and maximum to stack B and insert sort them back on A while optimizing for the minumum operations / rotations. Such method results in about 10-15% better performance. However on larger ranges it's becomes less efficient (500 numbers results in about 25% more operations).

## Installation and Usage

The visualisation of my algorithm is done with schools internal graphic library. However I've
made a special rule in makefile which compiles the program without the visualisation. For that version and for range of numbers larger than 900 I recommend using the python version of visualisator.

### Visual Version

For visual version, requires 42-ecole graphic library [minilibx](https://github.com/gcamerli/minilibx).

```
git clone --recurse-submodules https://github.com/forfungg/push_swap.git; cd push_swap; make
```

### Non-visual

```
git clone --recurse-submodules https://github.com/forfungg/push_swap.git; cd push_swap; make nograph
```

### Run Program

To check the usage:
```
./push_swap -u
```

Example of push_swap:
```
ARG=$(printf '%s ' `seq 1 100 | sort -R`); ./push_swap $ARG
```

Example of checker:
```
ARG=$(printf '%s ' `seq 1 100 | sort -R`); ./push_swap $ARG | ./checker $ARG
```

### Python visualiser

Requirements:
- python3
- tkinter
- PIL (pillow)

Example:
```
echo $(printf '%s ' `seq 1 100 | sort -R`) > testfile; ./push_swap -f testfile > result; python3 ./python_visualiser/ps_visual.py
```