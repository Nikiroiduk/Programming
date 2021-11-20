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
			auto deck = Deck();

			Card card1 = deck.getRandomCard();
			Card card2 = deck.getRandomCard();

			Assert::IsFalse(card1 == card2);
		}

		TEST_METHOD(PlayerCreationTest)
		{
			string name = "PlayerName";
			auto player = Player(name, 1000);
			Assert::AreEqual(name, player.getName());
		}
	};
}
