#include <iostream> 
#include <string>
using namespace std;

struct Couples {
    string partner1;
    string partner2;
    int week_scores[9];  // up to 9 weeks
    int song_and_dance;  // total score or separate
    int num_weeks;       // actual weeks recorded
};

struct Song_and_Dance{
int week1_song_and_dance;
int week2_song_and_dance;
int week3_song_and_dance;
int week4_song_and_dance;
int week5_song_and_dance;
int week6_song_and_dance;
int week7_song_and_dance;
int week8_song_and_dance;
};

void collect (ifstream& fin, Couples& c);
void display (Couples c);

void collect_song (ifstream& fin, Song_and_Dance& c);
