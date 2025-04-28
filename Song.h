#ifndef SONG_H
#define SONG_H

#include "Media.h"
#include <ostream>

class Song : public Media {
private:
    bool top40;

public:
    Song(const std::string& title,
        const std::string& keyName,
        int rating,
        const std::string& genre,
        int length,
        int yearReleased,
        bool top40);

    bool getTop40() const;
    void setTop40(bool t);

    void print(std::ostream& os,
        const std::vector<Media*>& mediaList) const override;
};

#endif // SONG_H

