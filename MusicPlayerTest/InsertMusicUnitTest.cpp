#include "stdafx.h"
#include "CppUnitTest.h"
#include "MusicPlayer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusicPlayerTest
{
	//Unit test for all insert operations on the playlist
	TEST_CLASS(InsertMusicUnitTest)
	{
	public:
		
		// Insert a song when ordinal is less than 0
		TEST_METHOD(InsertMusicOrdinalLessThanZero)
		{
			MusicPlayer* player = new MusicPlayer();
			const int ordinal = -1;
			const int song_number = 1;
			const int number_of_songs = 3;
			player->CreatePlaylist(number_of_songs);

			Assert::IsFalse(player->InsertMusic(song_number, ordinal));
		}

		// Insert a song when ordinal is equal to 0
		TEST_METHOD(InsertMusicOrdinalEqualToZero)
		{
			MusicPlayer* player = new MusicPlayer();
			const int ordinal = 0;
			const int song_number = 1;
			const int number_of_songs = 3;
			player->CreatePlaylist(number_of_songs);

			Assert::IsFalse(player->InsertMusic(song_number, ordinal));
		}

		// Insert a song when ordinal is greater than 0. Also check the size of the list
		TEST_METHOD(InsertMusicOrdinalGreaterThanZero)
		{
			MusicPlayer* player = new MusicPlayer();
			const int ordinal = 2;
			const int song_number = 1;
			const int number_of_songs = 3;
			player->CreatePlaylist(number_of_songs);
			int playlist_size_before = player->GetPlaylistSize();

			Assert::IsTrue(player->InsertMusic(song_number, ordinal));

			int playlist_size_after = player->GetPlaylistSize();
			Assert::AreEqual(playlist_size_before + 1, playlist_size_after);
		}

		// Check the current playing index after inserting a song
		TEST_METHOD(InsertMusicCurrentPlayingIndexChange)
		{
			MusicPlayer* player = new MusicPlayer();
			const int ordinal = 2;
			const int song_number = 1;
			const int play_track_number = 2;
			const int number_of_songs = 4;
			player->CreatePlaylist(number_of_songs);
			player->PlayTrackNumber(play_track_number);
			int playing_index_before = player->GetCurrentPlayingIndex();

			player->InsertMusic(song_number, ordinal);
			int playing_index_after = player->GetCurrentPlayingIndex();

			Assert::AreEqual(playing_index_before + 1, playing_index_after);
		}
		
		// Insert a song at the ordinal = playlistsize+1
		TEST_METHOD(InsertMusicOrdinalGreaterThanSize)
		{
			MusicPlayer* player = new MusicPlayer();
			int ordinal = 4;
			const int song_number = 1;
			const int number_of_songs = 3;
			player->CreatePlaylist(number_of_songs);
			
			Assert::IsTrue(player->InsertMusic(song_number, ordinal));
		}

		// Insert a song at ordinal > playlistsize+1
		TEST_METHOD(InsertMusicOrdinalMuchGreaterThanSize)
		{
			MusicPlayer* player = new MusicPlayer();
			int ordinal = 5;
			const int song_number = 1;
			const int number_of_songs = 3;
			player->CreatePlaylist(number_of_songs);

			Assert::IsFalse(player->InsertMusic(song_number, ordinal));
		}

	};
}