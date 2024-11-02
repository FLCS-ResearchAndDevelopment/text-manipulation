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



# Multi-Threaded Text Line Reversal

This project includes a multi-threaded C++ program that reads each line from an input text file, reverses the characters in each line, and writes the result to an output file. Designed for high efficiency, this program utilizes multiple threads to handle large text files swiftly.

## Overview

This application is suited for processing large files with tens of millions of lines. Each line is reversed individually and output in the same order, leveraging C++'s concurrency features for speed.

## Prerequisites

- **Compiler**: g++ or any C++17-compliant compiler.
- **System Requirements**: The program runs best on multi-core systems where it can utilize multiple threads.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/username/text-line-reversal.git
   cd text-line-reversal


2. Compile the code:
bash
Copy code
g++ -std=c++17 reverse-lines.cpp -o reverse-lines -pthread

3. Usage
Command
Run the program with an input file (e.g., big_input.txt) and an output file (e.g., reversed_output.txt):

bash
Copy code
./reverse-lines
By default, the program reads from big_input.txt and writes to reversed_output.txt. Modify the file names in the code if you want to use different files.

4. Example
Given an input file (big_input.txt) with these lines:

text
Copy code
Hello World
12345
ABC DEF
The output file (reversed_output.txt) will contain:

text
Copy code
dlroW olleH
54321
FED CBA

5. Code Structure
reverseLine: Reverses the characters in a single line using C++ reverse iterators.
processLines: Manages reading, reversing, and writing lines for each thread. Synchronizes access to shared resources (files) using mutexes.
main: Initializes file streams, launches threads, and manages thread synchronization.

6. Design Notes
Concurrency: The program automatically adapts to the system's available cores, using std::thread::hardware_concurrency() to determine the number of threads.
Synchronization: Protects file access with mutexes to prevent race conditions.
Scalability: Scales well for large files by processing lines concurrently, making it efficient for high volumes of text data.

7. Contributing
Feel free to open issues or submit pull requests for enhancements or bug fixes. Contributions are welcome to improve multi-threading, error handling, and performance.

markdown
Copy code


