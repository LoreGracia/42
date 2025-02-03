<div align="right">
  <img src="https://www.42barcelona.com/wp-content/uploads/2020/07/Barcelona-300x79.png" alt="Logo"  height="20">
  <div align="left">
 <a href="https://github.com/LoreGracia/42/tree/main/fractol"><img src="https://img.shields.io/badge/fractol-125%25-greenyellow?style=for-the-badge&labelColor=black"><a href="https://shields.io"/>
    <!---img src="https://cdn-icons-png.flaticon.com/512/724/724863.png" alt="Logo" width="80" height="80"--->
  
  <h3 align="center">Fractol</h3>
  <p align="center">
    Grafic fractals, Mandelbrot, Julia and variants.
    <br />
    <a href="https://github.com/LoreGracia/42/blob/a59f8b91586df4aa359d0f9c833ceafc8a669087/fractol/en.subject.pdf"><strong>Explore the subject »</strong></a>
  </p>
<div align="center">
  
<img src="https://github.com/user-attachments/assets/abad0184-662b-416d-afc7-bc67123faf2a" height="200">
<img src="https://github.com/user-attachments/assets/74265545-7247-4c8d-bf90-0ac357320947" height="200">


Fractol is the first grafic program in C to display fractals and make an interactive window. This 42 programming project aiming for the implementation of an external library and the visual representation of matematic formulas. 

<div align="left">

## Features

- Visual respesentation of Mandelbrot and Julia.
- Implementation of MLX codam library.
- Interactive window.

## Project Structure

The project is organized as follows:

```bash
.
├── MLX                                # MLX codam library
├── Makefile                           # Compiles program and MLX library
├── get_next_line.c                    # Main file and function needed
├── get_next_line.c                    # Main file and function needed
├── get_next_line_utils.c              # Rest of functions needed
├── get_next_line_bonus.h              # Header file -> libft.h
├── get_next_line_bonus.c              # Rest of functions needed
└── get_next_line_utils_bonus.c        # Rest of functions needed
```

see the <a href=https://github.com/LoreGracia/42/blob/63bab32b77e51be03f9f2f5427096d79d13db112/fractol/en.subject.pdf>subject</a> for more details.

## Installation

To compile the program and generate the execution file, follow these steps:

### Clone this repository:

```bash
git clone https://github.com/LoreGracia/42.git
cd 42/get_next_line
```

### Compile the library:
```bash
cc *.c
```

### Execution
Once you have compiled the files, you can execute it as follows:

```
./fracto Mandelbrot 2 or ./fractol Julia 0.09 0.01 [or arguments variants]
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>
