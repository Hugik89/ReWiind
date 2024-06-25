# ReWiind

A set of tools for conversion of various Wii files, written in C++.  
This is currently a work in progress !  

## Available converters

This project builds the following converters : 

- ast2wav : converts ast music files to wav format 
> Note : this converter only works on little-endian machines and PCM16 files !

## Build instructions

First, ensure that you have [cmake 3.28+](https://cmake.org/) installed.  
Then, follow the instructions depending on your operating system : 

### For Linux :

```
mkdir build
cd build
cmake -S ../ -B ./
cmake --build ./
```

### For Windows :

Mostly the same as Linux instructions, must check

## How to run converters

Open a shell, then :

- on Linux, run ``` ./<converter_name> -h ```
- on Windows, run ```<converter_name> -h``` (probably)

## Upcoming converters

- bcsv2csv : conversion between comma-separated data files
- tpl2png : conversion between image formats