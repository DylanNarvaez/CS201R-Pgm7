#include "Functions.h"
#include <vector>
#include <string>
#include <iostream>
#include "Media.h"

int main() {
    std::vector<Media*> mediaList;
    const std::string mediaFile = "mediaList.txt";
    const std::string commandsFile = "mediaCommands.txt";
    const std::string reportFile = "report.txt";
    const std::string errorFile = "error.txt";

    // Load data
    loadMediaList(mediaFile, mediaList, errorFile);

    // Execute commands
    processCommands(commandsFile, mediaList, reportFile, errorFile);

    // Clean up
    for (auto ptr : mediaList) {
        delete ptr;
    }

    return 0;
}
