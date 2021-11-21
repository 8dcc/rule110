# Rule 110
**[Rule110](https://en.wikipedia.org/wiki/Rule_110) made in C.**

You can see an example [here](https://raw.githubusercontent.com/r4v10l1/rule110/main/example.txt).

## Configuration
#### Display
- `STEPS`-`int`: The ammount of lines to be printed.
- `MAX_LINE_LEN`-`int`: Won't print characters that exceed this position.
#### Characters
- `FILLCHAR`-`int`: The character that the program will print as `1`.
- `EMPTYCHAR`-`int`: The character that the program will print as `0`.
#### Settings
- `PRINT_ARRAY`-`int`: If `0`, it will print the array before the line display.
- `PRINT_DETAILS`-`int`: If `0`, it will print useful information before displaying the simulation.

## Functions
```c
int calc_rule(int a, int b, int c, int mode);
```
`a`, `b` and `c` are the states of the cells, left to right. `mode == 1` will switch the variables `a` and `b`.

- `mode == 0`:

   a | b | c 
  ---|---|---
     | r |   
     
   1 | 0 | 0 
  ---|---|---
     | 0 |   
     
- `mode == 1`:

   c | b | a 
  ---|---|---
     | r |   

   0 | 0 | 1 
  ---|---|---
     | 0 |   

Where `r` is the value returned.

