# text-manipulation
This repository contains various code examples for  ASCII text manipulation

# Large ASCII Text File Generator

This project contains a C++ program to generate a large text file of random ASCII lines. Each line has a random length between 10 and 100 characters, and only contains printable ASCII characters.

## Overview

The program is multi-threaded, leveraging modern C++ (C++17) random utilities to ensure unique, non-repetitive data on each run. With 15 million lines of text, this tool is ideal for creating sample datasets or testing file processing algorithms.

## Prerequisites

- **Compiler**: g++ or any compiler supporting C++17 standard.
- **System Requirements**: Enough disk space for a large file (15 million lines).

## Installation

1. Clone the repository:
   	```bash
   	git clone https://github.com/username/large-ascii-text-generator.git
   	cd large-ascii-text-generator

2. Compile the code:
	bash
	Copy code
	g++ -std=c++17 gen-large-txt.cpp -o gen-large-txt
	
3. Usage
	Run the executable to generate a text file named ascii_text_file.txt:
	bash
	Copy code
	./gen-large-txt
	After running, check the same directory for the output file. 
	The program will output progress updates every 1 million lines.

4. Explanation of Output
	The file ascii_text_file.txt will contain 15 million lines. 
	Each line consists of randomly generated ASCII characters with a random length (10-100 characters).

5. Example of output format:

	text
	Copy code
	fRgTxv4^%jqv
	)RGtxzXp[H?]Y
	xghs83jfNvdh&&
	...

6. Code Structure
	generateRandomString(size_t length): Generates a random ASCII string of specified length.
	main(): Initializes file handling, random line lengths, and controls the generation loop.

7. Contributing
	Feel free to open issues or submit pull requests to suggest improvements or report bugs.
