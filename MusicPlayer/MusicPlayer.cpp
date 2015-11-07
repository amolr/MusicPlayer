//Implementation of all the operations of music playlist

#include "stdafx.h"
#include "MusicPlayer.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
using namespace std;
#define PLAYING_SONG_MARKER "*"

MusicPlayer::MusicPlayer()
{
	current_playing_index = -1;
}

MusicPlayer::~MusicPlayer(){}


/*
Returns the size of the list
Input : None
Output : The size of the playlist 
*/
int MusicPlayer::GetPlaylistSize()
{
	return music_list.size();
}

/*
Returns the current playing index in the list
Input: None
Output: The index of the currently playing song
*/
int MusicPlayer::GetCurrentPlayingIndex()
{
	return current_playing_index;
}

/*
Iterates through the contents of the playlist and prints the playlistId.
In case the playlistId is currently playing, an * is printed to denote that
Input: None
Output: Prints the playlist on the console
*/
void MusicPlayer::PrintPlaylist()
{
	if (GetPlaylistSize() == 0)
	{
		cout << "Playlist is empty\n";
		return;
	}

	for (auto music_node = music_list.begin(); music_node != music_list.end();music_node++)
	{
		cout << music_node->playlist_id;
		if (music_node->is_playing)
		{
			cout << PLAYING_SONG_MARKER;
		}
	
		cout << " ";
	}

	cout << "\n";
}

/*
Creates a playlist with the given specified number of songs
It discards the earlier playlist condition if exists and creates a new one
Input : number of songs
Output: Indicates if the creation is successful or not
*/
bool MusicPlayer::CreatePlaylist(int number_of_songs)
{
	if (number_of_songs <= 0)
	{
		cout << "Number of songs is less than or equal to zero. Did not create any playlist\n";
		return false;
	}
	
	if (GetPlaylistSize() > 0)
	{
		current_playing_index = -1;
		music_list.clear();
	}

	try
	{
		int track_number = 1;
		while (track_number <= number_of_songs)
		{
			music_list.push_back(MusicNode(track_number));
			track_number++;
		}
	}
	catch (exception e)
	{
		cout << "Error while creating playlist\n";
		return false;
	}

	return true;
}

/*
Deletes the song at the given ordinal and also changes the currently playing song index if exists
Input: the ordinal of the song
Output: Indicates if deletion is successful or not
*/
bool MusicPlayer::DeleteMusic(const int ordinal)
{
	if (ordinal <= 0)
	{
		cout << "Not a valid track number. Track number starts with 1.\n";
		return false;
	}
	
	if (ordinal > GetPlaylistSize())
	{
		cout << "Specified track number is greater than the playlist size.\n";
		return false;
	}

	//adjusting the current playing index on deletion
	if (current_playing_index == ordinal - 1)
		current_playing_index = -1;
	else if (current_playing_index > ordinal-1)
		current_playing_index--;

	music_list.erase(music_list.begin() + (ordinal-1));
	return true;
}

/*
Inserts the song number at a given ordinal. Changes the playing index if exists accordingly
If the ordinal is one greater than size inserts it at the end of the list
Input:
song_number : the id of the song to be inserted
ordinal : The ordinal in the list
Output : Indicates if insertion is successful or not
*/
bool MusicPlayer::InsertMusic(const int song_number, const int ordinal)
{
	if (ordinal <= 0)
	{
		cout << "Not a valid track number. Track number starts with 1.\n";
		return false;
	}
	
	if (ordinal > GetPlaylistSize() + 1)
	{
		cout << "Specified track number is greater than the playlist size.\n";
		return false;
	}

	//inserts at the end of the list if ordinal = playlistsize+1
	if (ordinal == GetPlaylistSize() + 1)
		music_list.push_back(MusicNode(song_number));
	else
		music_list.insert(music_list.begin() + ordinal - 1, song_number);

	//adjusting the playing index after insertion
	if ((ordinal - 1) <= current_playing_index)
		current_playing_index++;

	return true;
}

/*
Sets the current playing index to the given ordinal. 
Input : The required ordinal to set the current playing index
Output : Indicates if play track is successful or not
*/
bool MusicPlayer::PlayTrackNumber(const int ordinal)
{
	if (ordinal <= 0)
	{
		cout << "Not a valid track number. Track number starts with 1.\n";
		return false;
	}
	
	if (ordinal > GetPlaylistSize())
	{
		cout << "Specified track number is greater than the playlist size.\n";
		return false;
	}
	
	//Unset previously set playing status
	if (current_playing_index!=-1)
	music_list[current_playing_index].is_playing = false;
	
	current_playing_index = ordinal - 1;
	music_list[current_playing_index].is_playing = true;
	return true;
}

/*
Iterates through the list to find the currently playing index of the song
Input: None
Output: The current playing index after shuffle
*/
int MusicPlayer::SearchPlayingIndex()
{
	int playing_index = 0;

	for (auto music_node = music_list.begin(); music_node != music_list.end(); music_node++)
	{
		if (music_node->is_playing)
			break;
		playing_index++;
	}

	return playing_index;
}

/*
Swaps the current playing index after shuffle with the original playing index
Input : current playing index after shuffle
Output: None
*/
void MusicPlayer::SwapPlayingIndexNode(const int playing_index_after_shuffle)
{
	MusicNode temp_music_node = music_list[current_playing_index];
	music_list[current_playing_index] = music_list[playing_index_after_shuffle];
	music_list[playing_index_after_shuffle] = temp_music_node;
}

/*
Shuffles the song in the list. Maintains the current playing song by swapping it with new playing index
Input : None
Output : Indicates if shuffle is successful or not
*/
bool MusicPlayer::ShuffleMusic()
{
	try
	{
		auto engine = std::default_random_engine{};
		shuffle(music_list.begin(), music_list.end(), engine);
		if (current_playing_index == -1)
			return true;
	}
	catch (exception e)
	{
		cout << "Could not shuffle playlist due to error\n";
		return false;
	}
	
	//Get the playing index after shuffle
	int playing_index_after_shuffle = SearchPlayingIndex();
	SwapPlayingIndexNode(playing_index_after_shuffle);
	return true;
}