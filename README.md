<div align="center">
	<h1>Rule 110</h1>
	<b><a href="https://en.wikipedia.org/wiki/Rule_110">Rule 110</a> made in C.</b><br>
   <p>ASCII version and <a href="https://en.wikipedia.org/wiki/Netpbm">Netpbm</a> version.</p><br><br>
	<a href="https://github.com/r4v10l1/rule110/network/members"><img src="https://img.shields.io/github/forks/r4v10l1/rule110.svg?style=for-the-badge&logo=c&color=a8b9cc&logoColor=a8b9cc" alt="Forks"></a>
	<a href="https://github.com/r4v10l1/rule110/stargazers"><img src="https://img.shields.io/github/stars/r4v10l1/rule110.svg?style=for-the-badge&logo=c&color=a8b9cc&logoColor=a8b9cc" alt="Stars"></a>
</div>

# Table of contents
1. [ASCII](https://github.com/r4v10l1/rule110#ASCII)
   - [Configuration](https://github.com/r4v10l1/rule110#ASCII-Configuration)
   - [Functions](https://github.com/r4v10l1/rule110#ASCII-Functions)
2. [Netpbm](https://github.com/r4v10l1/rule110#Netpbm)
   - [Usage](https://github.com/r4v10l1/rule110#Netpbm-Usage)
   - [Configuration](https://github.com/r4v10l1/rule110#Netpbm-Configuration)
   - [Functions](https://github.com/r4v10l1/rule110#Netpbm-Functions)
3. [Examples](https://github.com/r4v10l1/rule110#Examples)
4. [Todo](https://github.com/r4v10l1/rule110#Todo)

## ASCII
You can see an example [here](https://raw.githubusercontent.com/r4v10l1/rule110/main/example.txt).

### ASCII Configuration
#### Display
- `STEPS`: The ammount of lines to be printed.
- `MAX_LINE_LEN`: Won't print characters that exceed this position. **If the value is `0`, it will turn off this option.**
#### Characters
- `FILLCHAR`: The character that the program will print as `1`.
- `EMPTYCHAR`: The character that the program will print as `0`.
#### Settings
- `PRINT_DETAILS`: If `1`, it will print useful information before displaying the simulation.

### ASCII Functions
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

## Netpbm
You can see an example [here](https://raw.githubusercontent.com/r4v10l1/rule110/main/examples/example2.png).

### Netpbm Usage
```bash
rule110-netpbm.o > output.pbm
```

### Netpbm Configuration
#### Display
- `HEIGHT`: The height of the `.pbm` file.
- `WIDTH`: The width of the `.pbm` file.

### Netpbm Functions
```c
int calc_rule(int a, int b, int c, int mode);
int calc_array();
```
## Examples
<img src="https://raw.githubusercontent.com/r4v10l1/rule110/main/examples/example3.png" alt="Example image 1" height="100px" width="100px">

![Example image 2](https://raw.githubusercontent.com/r4v10l1/rule110/main/examples/example2.png)

## Todo
- [X] The image does weird shit depending on the width. If HEIGHT > WIDTH, the image is ok.
- [X] Format the code for the ascii version.v
- [ ] Format the code for the pmb version.v
- [ ] Add `compile.sh`
- [X] Make the simulation infinite if steps is 0.
- [ ] Make a version in SDL2?
