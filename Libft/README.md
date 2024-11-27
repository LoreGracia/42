 <div align="right">
  <img src="https://www.42barcelona.com/wp-content/uploads/2020/07/Barcelona-300x79.png" alt="Logo"  height="20">
   <div align="left"> <a href="https://github.com/LoreGracia/42/tree/main/Libft"><img src="https://img.shields.io/badge/libft-125%25-greenyellow?style=for-the-badge&labelColor=black"><a href="https://shields.io"/>
<div align="center">
    <!---img src="https://cdn-icons-png.flaticon.com/512/724/724863.png" alt="Logo" width="80" height="80"--->
  
  <h3 align="center">Libft</h3>
  <p align="center">
    A library, first 42 project!
    <br />
    <a href="https://github.com/LoreGracia/42/blob/3a999a1dcd50ee586bc5821a9c1e263442ffdd4c/Reload/en.subject.pdf"><strong>Explore the subject »</strong></a>
    <br />
    <br />
    <a href="https://github.com/othneildrew/Best-README-Template">View Demo</a>
    ·
    <a href="https://github.com/othneildrew/Best-README-Template/issues/new?labels=bug&template=bug-report---.md">Installation</a>
    ·
    <a href="https://github.com/othneildrew/Best-README-Template/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>

Libft is a custom library written in C that contains a set of standard functions from the C library along with some additional utility functions useful for developing C projects. This project is part of the 42 programming school's curriculum and aims to reinforce knowledge of basic C language concepts, memory management, and the implementation of simple data structures.

 <div align="left">
   
## Features

- Recreation of standard C library functions (`string.h`, `stdlib.h`, etc.).
- Auxiliary functions for manipulating strings, memory, and linked lists.
- Basic implementation of data structures such as linked lists and related operations.

## Project Structure

The repository is organized as follows:

```bash
.
├── *.h              # Header file -> libft.h
├── *.c              # Source files
├── Makefile         # Script to compile the library
└── libft.a          # Compiled library (generated after running 'make')
```

see the <a href=[Reload/en.subject.pdf](https://github.com/LoreGracia/42/blob/3a999a1dcd50ee586bc5821a9c1e263442ffdd4c/libft/en.subject.pdf)>subject</a> for more details.

## Installation

To compile the library and generate the libft.a file, follow these steps:

### Clone this repository:

```bash
git clone https://github.com/ararrojas/libft.git
cd libft
```

### Compile the library:
```bash
make
```

### Usage
Once compiled the library, it can be used as follows:

Include header files in your code:
```c
#include "libft.h"
```

### Start using the functions
For example:
```bash
gcc yourmain.c libft.a
```
<p align="right">(<a href="#readme-top">back to top</a>)</p>