#include "stdafx.h"
#include "CppUnitTest.h"
#include "MusicPlayer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MusicPlayerTest
{
	//Unit test for all Play track operations
	TEST_CLASS(PlayTrackUnitTest)
	{
	public:
		
		// play a song when ordinal is less than 0
		TEST_METHOD(PlayTrackOrdinalLessThanZero)
		{
			MusicPlayer* player = new MusicPlayer();
			const int ordinal = -1;
			const int number_of_songs = 3;
			player->CreatePlaylist(number_of_songs);

			Assert::IsFalse(player->PlayTrackNumber(ordinal));
		}

		// play a song when ordinal is equal to 0
		TEST_METHOD(PlayTrackOrdinalEqualZero)
		{
			MusicPlayer* player = new MusicPlayer();
			const int ordinal = 0;
			const int number_of_songs = 3;
			player->CreatePlaylist(number_of_songs);

			Assert::IsFalse(player->PlayTrackNumber(ordinal));
		}

		// play a song when ordinal is greater than 0
		TEST_METHOD(PlayTrackOrdinalGreaterThanZero)
		{
			MusicPlayer* player = new MusicPlayer();
			const int ordinal = 2;
			const int number_of_songs = 3;
			player->CreatePlaylist(number_of_songs);

			Assert::IsTrue(player->PlayTrackNumber(ordinal));
		}

		// play a song when ordinal is greater than playlist size
		TEST_METHOD(PlayTrackOrdinalGreaterThanSize)
		{
			MusicPlayer* player = new MusicPlayer();
			const int ordinal = 4;
			const int number_of_songs = 3;
			player->CreatePlaylist(number_of_songs);

			Assert::IsFalse(player->PlayTrackNumber(ordinal));
		}

		// Change the playing track
		TEST_METHOD(PlayTrackOrdinalChange)
		{
			MusicPlayer* player = new MusicPlayer();
			int ordinal = 2;
			const int number_of_songs = 4;
			player->CreatePlaylist(number_of_songs);

			player->PlayTrackNumber(ordinal);
			Assert::AreEqual(player->GetCurrentPlayingIndex(), ordinal-1);
			
			ordinal = 4;
			player->PlayTrackNumber(ordinal);
			Assert::AreEqual(player->GetCurrentPlayingIndex(), ordinal-1);
		}
	};
}