# PUSH_SWAP

A 42-cursus project where the goal is to sort given range of unique integers using two stacks (A and B) and only following operations:

**sa**: swap a - swap the first 2 elements at the top of stack a.
	Do nothing if there is only one or no elements).
**sb**: swap b - swap the first 2 elements at the top of stack b.
	Do nothing if there is only one or no elements).
**ss**: sa and sb at the same time.
**pa**: push a - take the first element at the top of b and put it
	at the top of a. Do nothing if b is empty.
**pb**: push b - take the first element at the top of a and put it
	at the top of b. Do nothing if a is empty.
**ra**: rotate a - shift up all elements of stack a by 1. The first
	element becomes the last one.
**rb**: rotate b - shift up all elements of stack b by 1. The first
	element becomes the last one.
**rr**: ra and rb at the same time.
**rra**: reverse rotate a - shift down all elements of stack a by 1.
	The last element becomes the first one.
**rrb**: reverse rotate b - shift down all elements of stack b by 1.
	The last element becomes the first one.
**rrr**: rra and rrb at the same time.

The binary **push_swap** returns a list of operations which if performed on given array of integers makes it sorted.

The binary **checker** performs given commands on given array of integers. And returns message whether the final stack is sorted or not.


## Installation and Usage

The visualisation of my algorithm is done with schools internal graphic library. However I've
made a special rule in makefile which compiles the program without the visualisation. For that version and for range of numbers larger than 900 I recommend using the python version of visualisator.

### Visual Version

For visual version, requires 42-ecole graphic library [minilibx](https://github.com/gcamerli/minilibx).

'''
git clone https://github.com/forfungg/push_swap.git; cd push_swap; make
'''

### Non-visual
