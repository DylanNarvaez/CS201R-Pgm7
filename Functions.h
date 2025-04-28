#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>
#include "Media.h"

// PRE:  mediaListFile points to a readable CSV, errorFile is writable.
// POST: mediaList is populated with dynamically allocated Media-derived objects.
//       Any line with invalid data is written (unaltered) to errorFile with a descriptive message.
void loadMediaList(const std::string& mediaListFile,
    std::vector<Media*>& mediaList,
    const std::string& errorFile);

// PRE:  commandsFile exists, mediaList is populated, reportFile and errorFile are writable.
// POST: Processes each command in commandsFile, writing normal output to reportFile
//       and any 'not found' or invalid-command messages to errorFile.
void processCommands(const std::string& commandsFile,
    const std::vector<Media*>& mediaList,
    const std::string& reportFile,
    const std::string& errorFile);

#endif // FUNCTIONS_H

