#include "Song.h"
#include <iostream>

Song::Song(const std::string& title,
    const std::string& keyName,
    int rating,
    const std::string& genre,
    int length,
    int yearReleased,
    bool top40)
    : Media('S', title, keyName, rating, genre, length, yearReleased),
    top40(top40)
{
}

bool Song::getTop40() const {
    return top40;
}

void Song::setTop40(bool t) {
    top40 = t;
}

void Song::print(std::ostream& os,
    const std::vector<Media*>& /*mediaList*/) const {
    os << "Song: " << title << " (" << yearReleased << ")\n"
        << "  Rating: " << rating << "/10\n"
        << "  Genre: " << genre << "\n"
        << "  Duration: " << length << " sec\n"
        << "  In Top 40: " << (top40 ? "Yes" : "No") << "\n"
        << "---\n";
}
