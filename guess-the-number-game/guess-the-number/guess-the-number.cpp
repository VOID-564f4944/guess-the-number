#include <iostream>
#include <random>
#include <limits>

enum class Difficulty
{
	Easy,
	Medium,
	Hard
};


unsigned short getMaxAttempts(Difficulty mode)
{
	switch (mode)
	{
	case Difficulty::Easy:
		return 10;
	case Difficulty::Medium:
		return 7;
	case Difficulty::Hard:
		return 5;
	}

	return 10;
}

unsigned short generateRandom(unsigned short max)
{
	static std::random_device entropy;
	static std::mt19937 engine(entropy());
	std::uniform_int_distribution <unsigned short> dist(1, max);
	return dist(engine);
}

void playGame(unsigned short target, unsigned short max_attempts)
{
	unsigned short guess;

	for (unsigned short attempts = 1; attempts <= max_attempts; ++attempts)
	{
		std::cout << "Attempt " << attempts << "/" << max_attempts << ". Enter your guess: ";
      std::cin >> guess;

		if (!std::cin)
		{
			std::cin.clear();
           std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number.\n";
			--attempts;
			continue;
		}

		if (guess == target)
		{
			std::cout << "Correct! You win.\n";
			return;
		}
		else if (guess < target)
		{
			std::cout << "Too low.\n";
		}
		else
		{
			std::cout << "Too high.\n";
		}
	}

	std::cout << "You've used all attempts. The number was " << target << ".\n";
}

int main()
{
	std::cout << "Welcome to the Number Guessing Game!\nI'm thinking of a number between 1 and 100.\nYou have 7 chances to guess the correct number.\n\n";
	std::cout << "Select difficulty level:\n1. Easy(10 chances)\n2. Medium(7 chances)\n3. Hard(5 chances)\n";
	unsigned short choice;
	std::cin >> choice;
	if (!std::cin)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		choice = 2; // default to Medium on invalid input
		std::cout << "Invalid selection. Medium difficulty is set.\n";
	}

	Difficulty mode;
	switch (choice)
	{
	case 1:
		mode = Difficulty::Easy;
		break;
	case 2:
		mode = Difficulty::Medium;
		break;
	case 3:
		mode = Difficulty::Hard;
		break;
	default:
		mode = Difficulty::Medium;
		std::cout << "Medium difficulty is set.\n";
	}
	unsigned short max_attempts = getMaxAttempts(mode);
	unsigned short target = generateRandom(100);

	std::cout << "Guess the number between 1 and " << 100 << "\n";
	playGame(target, max_attempts);

	return 0;
}