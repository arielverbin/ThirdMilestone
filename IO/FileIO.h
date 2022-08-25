
#ifndef THIRDMILESTONE_FILEIO_H
#define THIRDMILESTONE_FILEIO_H

#include "DefaultIO.h"
#include <utility>
#include <iostream>
#include <fstream>
/**
 * Can write and read from files. (Supports both relative and absolute path)
 */
class FileIO : public DefaultIO{
private:
    std::string pathToFile;
public:
    explicit FileIO(std::string pathToFile);

    std::string receive() override;

    /** This method overwrites the file **/
    bool send(std::string message) override;
};


#endif //THIRDMILESTONE_FILEIO_H
