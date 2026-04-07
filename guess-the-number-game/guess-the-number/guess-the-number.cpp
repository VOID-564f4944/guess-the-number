#include <iostream>
#include <random>
#include <limits>
#include <chrono>

namespace
{
	constexpr int MIN = 1;
	constexpr int MAX = 100;
}

enum class Difficulty
{
	Easy,
	Medium,
	Hard
};

enum class GuessResult
{
	Low,
	High,
	Correct
};

static GuessResult evaluateGuess(int guess, int target)
{
	if (guess < target) return GuessResult::Low;
	if (guess > target) return GuessResult::High;

	return GuessResult::Correct;
}

static int getMaxAttempts(Difficulty mode)
{
	switch (mode)
	{
		case Difficulty::Easy: return 10;
		case Difficulty::Medium: return 7;
		case Difficulty::Hard: return 5;
	}

	return 7;
}

static int generateRandom()
{
	static std::random_device entropy;
	static std::mt19937 engine(entropy());
	static std::uniform_int_distribution <int> dist(MIN, MAX);

	return dist(engine);
}

static int playGame(int target, int max_attempts)
{
	int guess;
	auto start = std::chrono::steady_clock::now();
	int attempts = 0;

	while (attempts < max_attempts)
	{
		std::cout << "Attempt " << (attempts + 1) << '/' << max_attempts << ". Enter your guess: ";
		std::cin >> guess;

		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number.\n";
			continue;
		}

		if (guess < MIN || guess > MAX)
		{
			std::cout << "Please enter a number between " << MIN << " and " << MAX << ".\n";
			continue;
		}

		++attempts;

		GuessResult result = evaluateGuess(guess, target);

		switch (result)
		{
			case GuessResult::Low:
				std::cout << "Try higher.\n";
				break;

			case GuessResult::High:
				std::cout << "Try lower.\n";
				break;

			case GuessResult::Correct:
			{
				auto end = std::chrono::steady_clock::now();
				auto seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start);

				std::cout << "Correct! You win.\n";
				std::cout << "You guessed it in " << attempts << " attempts.\n";
				std::cout << "Time taken: " << seconds.count() << " seconds\n";

				return attempts;
			}
		}
	}

	std::cout << "You've used all attempts. The number was " << target << ".\n";

	return -1;
}

int main()
{
	int best_easy = std::numeric_limits<int>::max();
	int best_medium = std::numeric_limits<int>::max();
	int best_hard = std::numeric_limits<int>::max();

	std::cout << "Welcome to the Number Guessing Game!\nI'm thinking of a number between " << MIN << " and " << MAX << ".\nBy default you have 7 chances to guess the correct number.\n\n";

	while (true)
	{
		int choice;

		std::cout << "Select difficulty level:\n1. Easy(10 chances)\n2. Medium(7 chances)\n3. Hard(5 chances)\n";
		std::cin >> choice;

		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid selection. Defaulting to Medium.\n";
			choice = 2;
		}

		Difficulty mode;

		switch (choice)
		{
			case 1:
				mode = Difficulty::Easy;
				std::cout << "Easy difficulty is set.\n";
				break;

			case 2:
				mode = Difficulty::Medium;
				std::cout << "Medium difficulty is set.\n";
				break;

			case 3:
				mode = Difficulty::Hard;
				std::cout << "Hard difficulty is set.\n";
				break;

			default:
				std::cout << "Invalid selection. Defaulting to Medium.\n";
				mode = Difficulty::Medium;
		}

		int max_attempts = getMaxAttempts(mode);
		int target = generateRandom();

		std::cout << "Guess the number between " << MIN << " and " << MAX << ".\n";

		int attempts = playGame(target, max_attempts);
		int* best = nullptr;


		if (mode == Difficulty::Easy)
		{
			best = &best_easy;
		}
		else if (mode == Difficulty::Medium)
		{
			best = &best_medium;
		}
		else
		{
			best = &best_hard;
		}

		if (attempts != -1 && attempts < *best)
		{
			*best = attempts;
			std::cout << "New high score: " << attempts << " attempts!\n";
		}

		while (true)
		{
			std::cout << "r = replay & q = quit: ";

			char rq;

			if (!(std::cin >> rq))
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input. Please enter 'r' or 'q'.\n";
				continue;
			}

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (rq == 'q' || rq == 'Q')
			{
				return 0;
			}
			else if (rq == 'r' || rq == 'R')
			{
				break;
			}
			else
			{
				std::cout << "Please enter only 'r' or 'q'.\n";
				continue;
			}
		}
	}

	return 0;
}