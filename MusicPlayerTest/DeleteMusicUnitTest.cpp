#include "stdafx.h"
#include "CppUnitTest.h"
#include "MusicPlayer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusicPlayerTest
{
	// Unit tests for Delete operations on the playlist
	TEST_CLASS(DeleteMusicUnitTest)
	{
	public:
		
		// Delete a song when ordinal is less than 0
		TEST_METHOD(DeleteMusicTrackLessThanZero)
		{
			MusicPlayer* player = new MusicPlayer();
			const int ordinal = -1;
			const int number_of_songs = 3;
			player->CreatePlaylist(number_of_songs);
			Assert::IsFalse(player->DeleteMusic(ordinal));
		}

		// Delete a song when ordinal is equal to 0
		TEST_METHOD(DeleteMusicTrackEqualZero)
		{
			MusicPlayer* player = new MusicPlayer();
			const int ordinal = 0;
			const int number_of_songs = 3;
			player->CreatePlaylist(number_of_songs);
			Assert::IsFalse(player->DeleteMusic(ordinal));
		}

		// Delete a song when ordinal is greater than 0. Also check the size of the list
		TEST_METHOD(DeleteMusicTrackGreaterThanZero)
		{
			MusicPlayer* player = new MusicPlayer();
			const int number_of_songs = 3;
			player->CreatePlaylist(number_of_songs);
			int size_before = player->GetPlaylistSize();

			const int ordinal = 2;
			Assert::IsTrue(player->DeleteMusic(ordinal));
			
			int size_after = player->GetPlaylistSize();
			Assert::AreEqual(size_before - 1, size_after);
		}

		// Delete song when ordinal is greater than the size of the list
		TEST_METHOD(DeleteMusicTrackGreaterThanSize)
		{
			MusicPlayer* player = new MusicPlayer();
			const int number_of_songs = 3;
			player->CreatePlaylist(number_of_songs);

			const int ordinal = 4;
			Assert::IsFalse(player->DeleteMusic(ordinal));
		}

		// Delete the currently playing song
		TEST_METHOD(DeleteMusicCurrentPlaying)
		{
			MusicPlayer* player = new MusicPlayer();
			const int number_of_songs = 3;
			const int track_number = 2;
			const int ordinal = 2;

			player->CreatePlaylist(number_of_songs);
			player->PlayTrackNumber(track_number);
			player->DeleteMusic(ordinal);

			Assert::AreEqual(player->GetCurrentPlayingIndex(), -1);
		}

		// Check the current playing index after deleting a song when ordinal is less than playing index
		TEST_METHOD(DeleteMusicCurrentPlayingIndexChange)
		{
			MusicPlayer* player = new MusicPlayer();
			const int number_of_songs = 4;
			const int track_number = 3;
			const int ordinal = 2;

			player->CreatePlaylist(number_of_songs);
			player->PlayTrackNumber(track_number);

			int playing_before = player->GetCurrentPlayingIndex();
			player->DeleteMusic(ordinal);
			int playing_after = player->GetCurrentPlayingIndex();

			Assert::AreEqual(playing_before-1, playing_after);
		}

		// Check the current playing index after deleting a song when ordinal is greater than playing index
		TEST_METHOD(DeleteMusicCurrentPlayingIndexNoChange)
		{
			MusicPlayer* player = new MusicPlayer();
			const int number_of_songs = 4;
			const int track_number = 2;
			const int ordinal = 3;

			player->CreatePlaylist(number_of_songs);
			player->PlayTrackNumber(track_number);

			int playing_before = player->GetCurrentPlayingIndex();
			player->DeleteMusic(ordinal);
			int playing_after = player->GetCurrentPlayingIndex();

			Assert::AreEqual(playing_before, playing_after);
		}
	};
}