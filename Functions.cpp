#include "Functions.h"
#include "Movie.h"
#include "Book.h"
#include "Song.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

// Load the media entries from CSV
void loadMediaList(const std::string& mediaListFile,
    std::vector<Media*>& mediaList,
    const std::string& errorFile)
{
    std::ifstream in(mediaListFile);
    std::ofstream err(errorFile, std::ios::app);
    std::string line;

    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string token;

        try {
            // TYPE
            if (!std::getline(ss, token, ',')) throw std::runtime_error("Missing type");
            char type = token[0];

            // TITLE
            if (!std::getline(ss, token, ',')) throw std::runtime_error("Missing title");
            std::string title = token;

            // KEYNAME
            if (!std::getline(ss, token, ',')) throw std::runtime_error("Missing keyName");
            std::string keyName = token;

            // RATING
            if (!std::getline(ss, token, ',')) throw std::runtime_error("Missing rating");
            int rating = std::stoi(token);
            if (rating <= 0 || rating > 10) throw std::runtime_error("Rating out of range");

            // GENRE
            if (!std::getline(ss, token, ',')) throw std::runtime_error("Missing genre");
            std::string genre = token;

            // LENGTH
            if (!std::getline(ss, token, ',')) throw std::runtime_error("Missing length");
            int length = std::stoi(token);

            // YEAR
            if (!std::getline(ss, token, ',')) throw std::runtime_error("Missing yearReleased");
            int year = std::stoi(token);
            if (year < 1920 || year > 2024) throw std::runtime_error("Year out of range");

            // TYPE-SPECIFIC
            if (type == 'M') {
                // STARS list (semicolon-separated)
                std::vector<std::string> stars;
                if (std::getline(ss, token)) {
                    std::istringstream starStream(token);
                    std::string star;
                    while (std::getline(starStream, star, ';')) {
                        stars.push_back(star);
                    }
                }
                mediaList.push_back(new Movie(title, keyName, rating, genre, length, year, stars));
            }
            else if (type == 'B') {
                if (!std::getline(ss, token, ',')) throw std::runtime_error("Missing weeksNYT");
                int weeks = std::stoi(token);
                mediaList.push_back(new Book(title, keyName, rating, genre, length, year, weeks));
            }
            else if (type == 'S') {
                if (!std::getline(ss, token, ',')) throw std::runtime_error("Missing top40");
                int top = std::stoi(token);
                if (top != 0 && top != 1) throw std::runtime_error("Invalid top40 flag");
                mediaList.push_back(new Song(title, keyName, rating, genre, length, year, top == 1));
            }
            else {
                throw std::runtime_error("Invalid media type");
            }
        }
        catch (const std::exception& e) {
            err << "Error processing line: [" << line << "] -> " << e.what() << "\n";
        }
    }
}
