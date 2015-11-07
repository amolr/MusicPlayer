
#include "stdafx.h"
#include "CppUnitTest.h"
#include "MusicPlayer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusicPlayerTest
{		
	// Unit test for all create playlist operations
	TEST_CLASS(CreatePlaylistUnitTest)
	{
	public:
		
		// create playlist with number of songs less than zero
		TEST_METHOD(CreatePlaylistLessThanZero)
		{
			MusicPlayer* player = new MusicPlayer();
			const int number_of_songs = -1;
			Assert::IsFalse(player->CreatePlaylist(number_of_songs));
		}

		// create playlist with number of songs equal to zero
		TEST_METHOD(CreatePlaylistEqualZero)
		{
			MusicPlayer* player = new MusicPlayer();
			const int number_of_songs = 0;
			Assert::IsFalse(player->CreatePlaylist(number_of_songs));
		}

		// create playlist with number of songs greater than zero
		TEST_METHOD(CreatePlaylistSizeGreaterThanZero)
		{
			MusicPlayer* player = new MusicPlayer();
			const int number_of_songs = 3;
			Assert::IsTrue(player->CreatePlaylist(number_of_songs));
		}

		// create playlist and discard the earlier list including the playing index
		TEST_METHOD(CreatePlaylistSizeGreaterZero)
		{
			int number_of_songs = 3;
			int track_number = 2;
			MusicPlayer* player = new MusicPlayer();
			player->CreatePlaylist(number_of_songs);
			player->PlayTrackNumber(track_number);
			number_of_songs = 4;
			Assert::IsTrue(player->CreatePlaylist(number_of_songs));
			Assert::AreEqual(player->GetCurrentPlayingIndex(), -1);
		}
	};
}