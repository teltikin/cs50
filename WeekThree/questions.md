# Questions

## What's `stdint.h`?

A library that allows programmers to write more portable code.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

These are integer types from stdint.h and make coding and porting much easier because the machine interprets each int as you want it to and there won't be any unwanted surprises.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE: 1, DWORD: 4, LONG: 4, WORD: 2.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

ASCII B then ASCII M in that order.

## What's the difference between `bfSize` and `biSize`?

bfSize: number of bytes required by the .bmp, biSize: number of bytes required by the structure.

## What does it mean if `biHeight` is negative?

The image is upside-down.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

The file that it is trying to open may not exist.

## Why is the third argument to `fread` always `1` in our code? (For example, see lines 40, 44, and 75.)

It is always 1 because you iterate over every single pixel.

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

(4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4 = 3, makes sure the bytes in a row % 4 = 0.

## What does `fseek` do?

Changes the offset of a pointer.

## What is `SEEK_CUR`?

The position indicator in the file.
