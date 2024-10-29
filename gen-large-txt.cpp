#include <fstream>
#include <iostream>
#include <string>
#include <random>

std::string generateRandomString(size_t length) {
    // Limit to printable ASCII characters: 32 (' ') to 126 ('~')
    std::string result;
    result.reserve(length);

    static std::mt19937 generator{std::random_device{}()};
    std::uniform_int_distribution<char> distribution(32, 126);

    for (size_t i = 0; i < length; ++i) {
        result += distribution(generator);
    }

    return result;
}

int main() {
    const size_t num_lines = 15'000'000;
    const std::string filename = "ascii_text_file.txt";

    // Open file for writing in text mode
    std::ofstream outfile(filename, std::ios::out | std::ios::trunc);
    if (!outfile.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return 1;
    }

    // Initialize random length generator for line lengths between 10 and 100
    std::mt19937 generator{std::random_device{}()};
    std::uniform_int_distribution<size_t> line_length_distribution(10, 100);

    // Generate and write lines
    for (size_t i = 0; i < num_lines; ++i) {
        size_t line_length = line_length_distribution(generator);
        std::string random_line = generateRandomString(line_length);
        outfile << random_line << '\n';

        // Optional: Progress indicator every 1 million lines
        if (i % 1'000'000 == 0) {
            std::cout << "Generated " << i << " lines..." << std::endl;
        }
    }

    outfile.close();
    std::cout << "File generation complete. Saved to " << filename << std::endl;
    return 0;
}

