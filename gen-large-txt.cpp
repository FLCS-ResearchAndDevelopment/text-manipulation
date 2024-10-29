#include <fstream>
#include <iostream>
#include <string>
#include <random>


#include <fstream>      // For file input and output streams
#include <iostream>     // For standard input and output streams
#include <string>       // For using std::string to store and manipulate text
#include <random>       // For generating random numbers

// Function to generate a random string of a specified length with ASCII characters
std::string generateRandomString(size_t length) {
    // ASCII range for printable characters: from 32 (' ') to 126 ('~')
    std::string result;
    result.reserve(length); // Reserve memory for the string to improve performance
    
    // Initialize a random number generator (mt19937) using a random seed from std::random_device
    static std::mt19937 generator{std::random_device{}()};
    // Distribution range set to 32-126 to generate only printable ASCII characters
    std::uniform_int_distribution<char> distribution(32, 126);

    // Loop to fill the string with random characters
    for (size_t i = 0; i < length; ++i) {
        result += distribution(generator); // Append each random character to the result string
    }

    return result; // Return the generated random string
}


int main() {
    // Number of lines to generate in the file
    const size_t num_lines = 15'000'000;
    
    // Name of the output file to store the generated ASCII text
    const std::string filename = "ascii_text_file.txt";

    // Open the output file in text mode for writing
    std::ofstream outfile(filename, std::ios::out | std::ios::trunc);
    if (!outfile.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return 1; // Exit with an error code if file can't be opened
    }

    // Initialize random length generator for line lengths between 10 and 100
    std::mt19937 generator{std::random_device{}()};
    std::uniform_int_distribution<size_t> line_length_distribution(10, 100);

    // Generate and write lines
    for (size_t i = 0; i < num_lines; ++i) {
        size_t line_length = line_length_distribution(generator);
        std::string random_line = generateRandomString(line_length);
        // Write the generated line to the output file followed by a newline character
        outfile << random_line << '\n';

        // Optional: Progress indicator every 1 million lines
        if (i % 1'000'000 == 0) {
            std::cout << "Generated " << i << " lines..." << std::endl;
        }
    }

    // Close the output file after all lines are written
    outfile.close();
    std::cout << "File generation complete. Saved to " << filename << std::endl;
    return 0; // Indicate successful completion
}

