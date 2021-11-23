#include "pch.h"
#include "CppUnitTest.h"
#include "../lab4_AggregationExceptionsBlackjack/Deck.cpp"
#include "../lab4_AggregationExceptionsBlackjack/Card.cpp"
#include "../lab4_AggregationExceptionsBlackjack/Player.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using std::string;

namespace lab4tests
{
	TEST_CLASS(lab4tests)
	{
	public:
		
		TEST_METHOD(RandomCardGenerationTest)
		{
			bool flag = false;
			auto deck = Deck();

			for (int i = 0; i < 26; ++i) {
				Card card1 = deck.getRandomCard();
				Card card2 = deck.getRandomCard();
				if (card1 == card2) flag = !flag;
			}

			Assert::IsFalse(flag);
		}

		TEST_METHOD(PlayerCreationTest)
		{
			string name = "PlayerName";
			auto player = Player(name, 1000);
			Assert::AreEqual(name, player.getName());
		}
	};
}
