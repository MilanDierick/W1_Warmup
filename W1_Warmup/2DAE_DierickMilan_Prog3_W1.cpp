#include <iostream>
#include <string>

namespace Utilities
{
	int GetIntFromCin(const std::string message)
	{
		std::cout << message;
		while (true)
		{
			std::string inputString;
			std::getline(std::cin, inputString);
			try
			{
				// Throws std::invalid_argument if no conversion could be performed
				// No need to worry about the std::out_of_range exception because it's beyond this project's scope
				const int number = std::stoi(inputString);
				return number;
			}
			catch (...)
			{
				std::cout << "Bad input: please only insert natural numbers...\n";
			}
		}
	}
}

// ***********************************
// Start Exercise 1
// ***********************************
void EnterPositiveNumbers()
{
	int count = 0;
	int sum   = 0;
	bool quit = false;

	std::cout << "Enter positive numbers, negative value to end input\n";

	while (!quit)
	{
		std::string inputString;
		std::getline(std::cin, inputString);
		try
		{
			// Throws std::invalid_argument if no conversion could be performed
			// No need to worry about the std::out_of_range exception because it's beyond this project's scope
			const int number = std::stoi(inputString);
			if (number < 0)
			{
				quit = true;
			}
			else
			{
				++count;
				sum += number;
			}
		}
		catch (...)
		{
			std::cout << "Bad input: please only insert natural numbers...\n";
		}
	}

	std::cout << "\n\nNumber of numbers entered: " << count << "\n";
	std::cout << "Average of numbers entered: " << static_cast<float>(sum) / count << "\n";
}

// ***********************************
// End Exercise 1
// ***********************************

// ***********************************
// Start Exercise 2
// ***********************************
void DrawChessboard(const int columns, const int rows, const int squareSize, const char squareWhiteCharacter, const char squareBlackCharacter)
{
	// Loop over all the required columns
	for (size_t row = 0; row < rows; ++row)
	{
		// Print a whole row x times depending on the size of the individual squares
		for (size_t size1 = 0; size1 < squareSize; ++size1)
		{
			// Print a single row
			for (size_t column = 0; column < columns; ++column)
			{
				// Determine if we need to start printing the white or black squares
				if (column % 2)
				{
					// Print the white / black characters depending on the size of the individual squares
					for (size_t size2 = 0; size2 < squareSize; ++size2)
					{
						// Determine if we need to print the black / white character to make them alternate
						row % 2 ? std::cout << squareWhiteCharacter : std::cout << squareBlackCharacter;
					}
				}
				else
				{
					// Print the white / black characters depending on the size of the individual squares
					for (size_t size3 = 0; size3 < squareSize; ++size3)
					{
						// Determine if we need to print the black / white character to make them alternate
						row % 2 ? std::cout << squareBlackCharacter : std::cout << squareWhiteCharacter;
					}
				}
			}

			std::cout << "\n";
		}
	}
}

void DrawChessboard(const int columns, const int rows, const int squareSize)
{
	DrawChessboard(columns, rows, squareSize, ' ', '*');
}

int Chessboard()
{
	const int horizontal = Utilities::GetIntFromCin("Number of horizontal squares? > ");
	const int vertical   = Utilities::GetIntFromCin("Number of vertical squares? > ");
	const int size       = Utilities::GetIntFromCin("Size of a square? > ");
	DrawChessboard(horizontal, vertical, size);
	system("pause");
	DrawChessboard(horizontal, vertical, size, '+', '-');
	system("pause");

	return 0;
}
// ***********************************
// End Exercise 2
// ***********************************

int main(int argc, char* argv[])
{
	Chessboard();
	
	return 0;
}
