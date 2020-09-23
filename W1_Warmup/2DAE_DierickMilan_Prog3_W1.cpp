#include <chrono>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

#include "ConsoleInputParser.h"

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
void DrawChessboard(const int columns, const int rows, const int squareSize, const char squareWhiteCharacter,
                    const char squareBlackCharacter)
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

// ***********************************
// Start Exercise 3
// ***********************************
bool IsPrime(const int number)
{
	if (number < 2) return false;
	if (number % 2 == 0 && number != 2) return false;
	for (size_t counter = 3; counter <= std::sqrt(number); counter += 2)
	{
		if (number % counter == 0) return false;
	}
	return true;
}

void ConsoleIsPrime(int argc, char* argv[])
{
	// Putting this functionality into a class allows me to use this code in another project much easier
	const Utilities::InputParser inputParser(argc, argv);

	if (inputParser.CmdOptionExists("-h"))
	{
		std::cout << "Please pass a value that need to be checked with the -v parameter option, like so:\n";
		std::cout << "program.exe -v 5\n";
	}
	else
	{
		const std::string value = inputParser.GetCmdOption("-v");
		if (value == "")
		{
			std::cout << "Incorrect value passed. Pass the -h parameter for help.\n";
		}
		else
		{
			try
			{
				if (IsPrime(std::stoi(value)))
				{
					std::cout << value << " is a prime number!\n";
				}
				else
				{
					std::cout << value << " is not a prime number!\n";
				}
			}
			catch (...)
			{
				std::cout << "Incorrect value passed. Pass the -h parameter for help.\n";
			}
		}
	}
}

// ***********************************
// End Exercise 3
// ***********************************

// ***********************************
// Start Exercise 4
// ***********************************
void OutputAllPrimesBelowValue(int argc, char* argv[])
{
	// Putting this functionality into a class allows me to use this code in another project much easier
	const Utilities::InputParser inputParser(argc, argv);

	if (inputParser.CmdOptionExists("-h"))
	{
		std::cout << "Please pass a value that need to be checked with the -v parameter option, like so:\n";
		std::cout << "program.exe -v 5\n";
	}
	else
	{
		const std::string value = inputParser.GetCmdOption("-v");
		if (value == "")
		{
			std::cout << "Incorrect value passed. Pass the -h parameter for help.\n";
		}
		else
		{
			try
			{
				const int number = std::stoi(value);

				for (size_t counter = 0; counter < number; ++counter)
				{
					if (IsPrime(static_cast<int>(counter)))
					{
						std::cout << counter << " is a prime number!\n";
					}
				}
			}
			catch (...)
			{
				std::cout << "Incorrect value passed. Pass the -h parameter for help.\n";
			}
		}
	}
}

void OutputAllPrimesBelowValueExtension(int argc, char* argv[])
{
	// Putting this functionality into a class allows me to use this code in another project much easier
	const Utilities::InputParser inputParser(argc, argv);

	if (inputParser.CmdOptionExists("-h"))
	{
		std::cout << "Please pass a value that need to be checked with the -v parameter option, like so:\n";
		std::cout << "program.exe -v 5\n";
	}
	else
	{
		const std::string value = inputParser.GetCmdOption("-v");
		if (value == "")
		{
			std::cout << "Incorrect value passed. Pass the -h parameter for help.\n";
		}
		else
		{
			try
			{
				int counter      = 0;
				const int number = std::stoi(value);

				const std::chrono::steady_clock::time_point start = std::chrono::high_resolution_clock::now();
				// Unsync the I/O of C and C++. 
				std::ios_base::sync_with_stdio(false);
				
				for (size_t iterationCounter = 0; iterationCounter < number; ++iterationCounter)
				{
					if (IsPrime(static_cast<int>(iterationCounter)))
					{
						++counter;
					}
				}

				const std::chrono::steady_clock::time_point stop = std::chrono::high_resolution_clock::now();
				double timeTaken = static_cast<double>(std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count()); 
				timeTaken *= 1e-9; 

				std::cout << "There are " << counter << " prime numbers that are smaller than the value " << number <<
					"\n\n";
				std::cout << "This operation took: " << std::fixed << timeTaken << std::setprecision(9) << " seconds\n";
			}
			catch (...)
			{
				std::cout << "Incorrect value passed. Pass the -h parameter for help.\n";
			}
		}
	}
}

// ***********************************
// End Exercise 4
// ***********************************

int main(const int argc, char* argv[])
{
	OutputAllPrimesBelowValueExtension(argc, argv);

	return 0;
}
