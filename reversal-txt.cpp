#include <fstream>      // For file input and output streams
#include <iostream>     // For standard input and output streams
#include <string>       // For using std::string to store and manipulate text
#include <thread>       // For multi-threading support
#include <vector>       // For managing multiple threads
#include <mutex>        // For synchronizing file access between threads

std::mutex write_mutex;  // Mutex to ensure synchronized writing to the output file

// Function to reverse a single line of text
std::string reverseLine(const std::string& line) {
    return {line.rbegin(), line.rend()}; // Creates a reversed string using reverse iterators
}

// Function for each thread to read, reverse, and write lines concurrently
void processLines(std::ifstream& infile, std::ofstream& outfile) {
    std::string line;
    
    // Loop until there are no more lines to read
    while (true) {
        {
            // Lock for thread-safe access to the input file stream
            static std::mutex read_mutex;
            std::lock_guard<std::mutex> lock(read_mutex);
            
            if (!std::getline(infile, line)) {
                break;  // Exit loop if end of file is reached
            }
        }

        // Reverse the line content
        std::string reversed_line = reverseLine(line);

        // Lock for thread-safe writing to the output file stream
        {
            std::lock_guard<std::mutex> lock(write_mutex);
            outfile << reversed_line << '\n'; // Write reversed line to output
        }
    }
}

int main() {
    // Define the input and output file names
    std::string input_filename = "big_input.txt";
    std::string output_filename = "reversed_output.txt";

    // Open the input file for reading
    std::ifstream infile(input_filename);
    if (!infile) {
        std::cerr << "Error opening input file: " << input_filename << std::endl;
        return 1; // Exit with error code if input file fails to open
    }

    // Open the output file for writing
    std::ofstream outfile(output_filename);
    if (!outfile) {
        std::cerr << "Error opening output file: " << output_filename << std::endl;
        return 1; // Exit with error code if output file fails to open
    }

    // Get the number of threads supported by the system
    unsigned int num_threads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    // Launch threads to process lines concurrently
    for (unsigned int i = 0; i < num_threads; ++i) {
        threads.emplace_back(processLines, std::ref(infile), std::ref(outfile));
    }

    // Wait for all threads to finish processing
    for (auto& t : threads) {
        t.join();
    }

    // Close files
    infile.close();
    outfile.close();

    std::cout << "Processing complete. Reversed output written to " << output_filename << std::endl;
    return 0; // Exit successfully
}

