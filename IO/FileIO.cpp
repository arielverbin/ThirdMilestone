
#include "FileIO.h"

FileIO::FileIO(std::string pathToFile) : pathToFile(std::move(pathToFile)){}

bool FileIO::send(std::string message) {
    std::ofstream output;
    output.open(pathToFile);
    if (output.fail()) {
        std::cout << "Could not open " << pathToFile << std::endl;
        output.close();
        return false;
    }
    output << message << std::endl;
    output.close();
    return true;
}

std::string FileIO::receive() {
    std::string data, line;

    std::ifstream input;
    input.open(pathToFile);

    if (input.fail()) {
        std::cout << "Could not open " << pathToFile << std::endl;
        input.close();
        return "<error>";
    }

    while (!input.eof()) {
        getline(input, line);
        if (std::equal(line.begin(), line.end(), "")) continue; // avoid an empty line.
        data.append(line + "\n");
    }

    input.close();
    return data;
}
