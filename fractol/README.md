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

<img src="https://github.com/user-attachments/assets/e00f0fcd-311c-4426-ad9c-45b667ed36d6" height="200">
<img src="https://github.com/user-attachments/assets/5ad397a7-1a35-44c6-aa1a-2566a97ec3a1" height="200">
<img src="https://github.com/user-attachments/assets/c166ff24-e0c1-4905-a668-8160816fc96f" height="200">


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

<div align="center">

## Variants for Mandelbrot


| ./fracto Mandelbrot -1 | ./fractol Mandelbrot -2
|-|-|
|<img src="https://github.com/user-attachments/assets/d2e6fbc0-1944-4e6f-a2fb-626dd58bab15" height="125"> <img src="https://github.com/user-attachments/assets/ad5356a3-b77e-4335-872d-0d823f85f4de" height="125"> <img src="https://github.com/user-attachments/assets/bd697513-8ef4-4c98-a46d-abc865bcd3c7" height="125"> <img src="https://github.com/user-attachments/assets/ef9bc8ea-082c-48f1-a99b-c637e3073a98" height="125">| <img src="https://github.com/user-attachments/assets/e74c52f0-17de-41e7-9c5d-7e6e04b96259" height="125"> <img src="https://github.com/user-attachments/assets/4fab5d29-72d3-44a0-98b6-3f58d4271b29" height="125"> <img src="https://github.com/user-attachments/assets/10946656-4204-4b25-b9e2-acde6c24210d" height="125"> <img src="https://github.com/user-attachments/assets/2948916d-0c76-4b42-a563-c7da250aff86" height="125">|

|./fractol Mandelbrot 2 | ./fractol Mandelbrot 3 |
|-|-|
|<img src="https://github.com/user-attachments/assets/564e8eab-b3fe-48e1-9bc1-abf9446f4eb2" height="125"><img src="https://github.com/user-attachments/assets/0be36889-1b05-472d-ae9a-1712300f6d07" height="125"><img src="https://github.com/user-attachments/assets/174bb406-a933-4124-9bc0-c24c9188bf71" height="125"><img src="https://github.com/user-attachments/assets/0eb8a810-4782-477d-9603-920ad8048bf6" height="125">| <img src="https://github.com/user-attachments/assets/0a2e43bb-f3d9-4e03-bcc5-e01ca9a6aa6e" height="125"><img src="https://github.com/user-attachments/assets/fe647644-5e60-48d5-8154-c55f1672b309" height="125"><img src="https://github.com/user-attachments/assets/8d5c5576-bf4e-405f-a1be-ed099a63cf57" height="125"><img src="https://github.com/user-attachments/assets/39e3dd16-cc42-44b0-9a3b-2f08a3a91f21" height="125">|

| ./fractol Mandelbrot 4 | ./fractol Mandelbrot 5 |
|-|-|
|<img src="https://github.com/user-attachments/assets/308aeaa5-1ae9-4178-b087-ba4bb0a94b9e" height="125"><img src="https://github.com/user-attachments/assets/f44a2ad6-fd38-4bad-9177-4ea020536593" height="125"><img src="https://github.com/user-attachments/assets/55a1945f-363e-435f-af9b-73ce24172f5f" height="125"><img src="https://github.com/user-attachments/assets/febba8b2-9eea-407a-ac5f-6e499c4dab64" height="125">|<img src="https://github.com/user-attachments/assets/5ad63cf8-1ba2-4d53-b8f5-3560cfd70d38" height="125"><img src="https://github.com/user-attachments/assets/fee2b559-7a06-4d4c-8852-6b0fd774601c" height="125"><img src="https://github.com/user-attachments/assets/7b8d614d-b099-4a9a-b1c3-03c325540754" height="125"><img src="https://github.com/user-attachments/assets/2e705874-fc39-4f11-941c-331579ee56a7" height="125">|

| ./fractol Mandelbrot 6 | ./fractol Mandelbrot 8 |
|-|-|
|<img src="https://github.com/user-attachments/assets/dec6d9a7-85f8-4427-b272-c0625fac8ab4" height="125"><img src="https://github.com/user-attachments/assets/63131841-a010-4dd1-846b-d3249982104c" height="125"><img src="https://github.com/user-attachments/assets/521fe09d-868a-477f-ae36-d4586a8d47e2" height="125"><img src="https://github.com/user-attachments/assets/66d7e543-0fe8-4f60-8928-a2e0f3df5694" height="125">|<img src="https://github.com/user-attachments/assets/599aac6a-0df4-4612-9b37-49a0dbac44d8" height="125"><img src="https://github.com/user-attachments/assets/307c3585-2c38-45df-a0b3-626d8f01f415" height="125"><img src="https://github.com/user-attachments/assets/4a1c4b45-7b59-4b05-a75c-fd8c39396983" height="125"><img src="https://github.com/user-attachments/assets/c3da3511-3b0f-43df-bfae-3de334eb075d" height="125">|

| ./fractol Mandelbrot 14 | ./fractol Mandelbrot 80 |
| - | -|
|<img src="https://github.com/user-attachments/assets/0a1599e4-c04c-4243-9fad-95a9f662a152" height="125"> <img src="https://github.com/user-attachments/assets/a94382ea-7900-4783-b2c7-71c8c8e20bfa" height="125"> <img src="https://github.com/user-attachments/assets/18b98298-2e06-4a65-821d-de104750846c" height="125">  <img src="https://github.com/user-attachments/assets/7c15b721-e372-4eaf-a5f2-5dec1a4a2015" height="125"> | <img src="https://github.com/user-attachments/assets/a8e92ea1-5c33-4419-bd57-6653f990f069" height="125"> <img src="https://github.com/user-attachments/assets/b13a16cf-8a4d-4862-b21e-eac2d3ecdd64" height="125"> <img src="https://github.com/user-attachments/assets/fc0bd984-ee6f-4da6-a2be-e6cbf5c2c266" height="125"> <img src="https://github.com/user-attachments/assets/268d4a4c-ec62-403d-a81e-7427049f3133" height="125"> |

## ./fractol Julia 2
### ./fractol Julia 2 0.267 0.009
<img src="https://github.com/user-attachments/assets/94288fe6-663d-43c5-a84a-0db5d00194e2" height="125">
<img src="https://github.com/user-attachments/assets/67d841a1-65d2-478a-b6de-034ef555f297" height="125">
<img src="https://github.com/user-attachments/assets/83f5b0a0-cef0-4783-861b-e83f416d4b0f" height="125">
<img src="https://github.com/user-attachments/assets/10f8bad7-315e-4b4f-ae66-85fc775f65b5" height="125">

### ./fractol Julia 2 0.267 0.009

<img src="https://github.com/user-attachments/assets/af907e57-cf28-4c41-9fad-689d267dc072" height="125">
<img src="https://github.com/user-attachments/assets/bb5c4bd4-fad1-4a63-9d7d-1f86725b1278" height="125">
<img src="https://github.com/user-attachments/assets/2f2c53a2-bd4f-4c0c-a5e2-59e6b4d865e1" height="125">
<img src="https://github.com/user-attachments/assets/9b84eb49-159d-4791-a37f-011add2f3308" height="125">

### ./fractol Julia 2 0.267 0.009

<img src="https://github.com/user-attachments/assets/9a597142-cf0a-4e25-b39a-f6da18260193" height="125">
<img src="https://github.com/user-attachments/assets/6b718515-468c-4883-a7b7-6f2d1f9879f9" height="125">
<img src="https://github.com/user-attachments/assets/f6b2c6ff-a567-4fe1-b025-2d4d66f5238f" height="125">
<img src="https://github.com/user-attachments/assets/4d288d67-8fa2-40da-b15c-8402ec121f84" height="125">

### ./fractol Julia 2 0.267 0.009

<img src="https://github.com/user-attachments/assets/be8d9890-46ec-496e-93ab-4cd09057fc11" height="125">
<img src="https://github.com/user-attachments/assets/568474ef-ef75-474e-a26a-915a56e936de" height="125">
<img src="https://github.com/user-attachments/assets/343a57b9-2ddf-4522-af70-0cecab34419d" height="125">
<img src="https://github.com/user-attachments/assets/2ff593bb-d6db-40dd-8f6f-eda235bbf41b" height="125">

| ### ./fractol Julia 2 0.267 0.009                                                                        | ### ./fractol Julia 2 0.267 0.009 |
|---------------------------------------------------------------------------------------------------------- | ------------------- |
| <img src="https://github.com/user-attachments/assets/8181ca63-9a81-48ca-963f-422c03897e73" height="125"> <img src="https://github.com/user-attachments/assets/602ae551-6643-4b29-941c-ec9761a6bf18" height="125"> <img src="https://github.com/user-attachments/assets/5abe5bff-cda4-4d04-8912-fb87da78d2d8" height="125">  <img src="https://github.com/user-attachments/assets/b767ed7d-ccee-4d3e-b1ab-5fef819192e8" height="125"> |  <img src="https://github.com/user-attachments/assets/489a8a6b-331c-43a4-be6c-67a22d1e3325" height="125"> <img src="https://github.com/user-attachments/assets/a56f563d-3a0c-4594-b850-acfcdef84575" height="125"> <img src="https://github.com/user-attachments/assets/078b724e-874c-46c7-bfdf-1544e0ebb181" height="125">  <img src="https://github.com/user-attachments/assets/950423b8-2b64-4160-a3b2-304c5911cd01" height="125"> |

### ./fractol Julia 2 0.267 0.009

<img src="https://github.com/user-attachments/assets/ecbc5b54-0563-4e92-aaae-1731b0b4fbd5" height="125">
<img src="https://github.com/user-attachments/assets/fb6448a9-6054-4d45-9c77-bfad7adf3991" height="125">
<img src="https://github.com/user-attachments/assets/fbf456ad-b4d6-4dd5-8ddd-cba2e21221fd" height="125">
<img src="https://github.com/user-attachments/assets/efa3f75d-c690-44b2-a926-7c5bfb1dead7" height="125">

## ./fractol p

In order to get the grip of the MLX codam library I made some try and error from which there are two commented results of the program. One is a simple flat background and a line which was a first attemp to print and the second one is a panda face made out of circles.

<img src="https://github.com/user-attachments/assets/767ad717-2bcb-48b4-9723-b209aa005cff" height="125">

<p align="right">(<a href="#readme-top">back to top</a>)</p>
