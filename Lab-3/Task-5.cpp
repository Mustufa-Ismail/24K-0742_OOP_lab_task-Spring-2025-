#include <iostream>
using namespace std;

class musicPlayer
{
private:
    string playList[100];
    int songCount;
    string currentPlaying;

public:
    musicPlayer()
    {
        songCount = 0;
        currentPlaying = "";
    }

    void addSong(string song)
    {
        playList[songCount] = song;
        songCount++;
    }

    void removeSong(string song)
    {
        int flag = 0;
        for (int i = 0; i < songCount; i++)
        {
            if (playList[i] == song)
            {
                flag = 1;
                for (int j = i; j < songCount - 1; j++)
                {
                    playList[j] = playList[j + 1];
                }
                songCount--;
                cout << "Song:" << song << " Removed" << endl;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "Song not found in the Play list" << endl;
        }
    }

    void playSong(string song)
    {
        int flag = 0;
        for (int i = 0; i < songCount; i++)
        {
            if (playList[i] == song)
            {
                flag = 1;
                currentPlaying = song;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "Song not found in the Play list" << endl;
        }
        cout << "Currently Playing:" << song << endl;
    }

    void displayPlaylist()
    {
        for (int i = 0; i < songCount; i++)
        {
            cout << i + 1 << "." << playList[i] << endl;
        }
    }
};

int main()
{
    musicPlayer mp1;
    mp1.addSong("A");
    mp1.addSong("B");
    mp1.addSong("C");
    mp1.addSong("D");
    mp1.addSong("E");

    mp1.displayPlaylist();
    mp1.playSong("F");

    mp1.removeSong("C");

    mp1.playSong("B");
    mp1.displayPlaylist();

    return 0;
}