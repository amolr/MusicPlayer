#include "stdafx.h"
#include "CppUnitTest.h"
#include "MusicPlayer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusicPlayerTest
{
	// Unit test for all shuffle operations on playlist
	TEST_CLASS(ShuffleMusicUnitTest)
	{
	public:
		
		// Shuffle an empty playlist
		TEST_METHOD(ShuffleMusicEmptyPlayList)
		{
			MusicPlayer* player = new MusicPlayer();
			Assert::IsTrue(player->ShuffleMusic());
		}

		// Shuffle a playlist and check if current playing index retains
		TEST_METHOD(ShuffleMusicPlayList)
		{
			MusicPlayer* player = new MusicPlayer();
			const int number_of_songs = 4;
			const int play_track_number = 3;
			player->CreatePlaylist(number_of_songs);
			player->PlayTrackNumber(play_track_number);

			int playing_index_before = player->GetCurrentPlayingIndex();
			Assert::IsTrue(player->ShuffleMusic());
			int playing_index_after = player->GetCurrentPlayingIndex();
			Assert::AreEqual(playing_index_before, playing_index_after);
		}
	};
}