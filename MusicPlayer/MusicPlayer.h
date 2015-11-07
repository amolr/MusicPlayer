//main entry point to perform operations on Music playlist

#include "MusicNode.h"
#include <vector>
using namespace std;

//defines methods to perform operations on the playlist
class MusicPlayer
{
	private:

		//List of songs added to the list
		vector<MusicNode> music_list;
		
		//index of the song in the list which is currently playing
		int current_playing_index;

		//returns the index of the currently playing song
		int SearchPlayingIndex();

		//Swaps the playing index after shuffle with the original index
		void SwapPlayingIndexNode(const int playing_index_after_shuffle);

	public:
		MusicPlayer();
		~MusicPlayer();

		//Creates playlist with a specified number of songs
		bool CreatePlaylist(int number_of_songs);

		//Deletes the song at a particular ordinal
		bool DeleteMusic(const int ordinal);

		//Inserts a song at a particular ordinal
		bool InsertMusic(const int song_number, const int ordinal);
		
		//Shuffles the song in the playlist
		bool ShuffleMusic();

		// Sets the song at the given ordinal to currently playing
		bool PlayTrackNumber(const int ordinal);

		// Returns the playlist size
		int GetPlaylistSize();

		// Returns the current playing index 
		int GetCurrentPlayingIndex();

		//Prints the current playlist
		void PrintPlaylist();
};