#include <iostream>

int multiply(int number)
{
	return (number * 2);
}

int main()
{
	std::cout << " Enter ur card number: ";
	std::string card;
	std::cin >> card;

	const int length{ static_cast<int>(card.length()) };

	constexpr int offset{ 48 };
	bool isDouble = false;
	int sum{ 0 };

	for (int i{ 0 }; i < length; ++i)
	{

		if (isDouble == false)
		{
			const int card_number = card[i] - offset;
			int sumTemp{};

			int temp{ multiply(card_number) };
			std::string sus{ static_cast<char>(temp) };

			while (temp > 0)
			{
				const int rem = temp % 10;
				sumTemp = sumTemp + rem;
				temp = temp / 10;
			}

			sum += sumTemp;
		}
		else
		{
			const int cardNumber = card[i] - offset;

			sum += cardNumber;
		}

		isDouble = !isDouble;
	}


	if (const int tempSum = sum % 10; tempSum > 0)
	{
		isDouble = false; // reset to false
		sum = 0; // reset to 0

		for (int i{ 0 }; i < length; ++i)
		{

			if (isDouble == true) // some cards are only valid if the multiplied numbers are the odd and not the even ones.
			{
				const int card_number = card[i] - offset;
				int sumTemp{};

				int temp{ multiply(card_number) };
				std::string sus{ static_cast<char>(temp) };

				while (temp > 0)
				{
					const int rem = temp % 10;
					sumTemp = sumTemp + rem;
					temp = temp / 10;
				}

				sum += sumTemp;
			}
			else
			{
				const int cardNumber = card[i] - offset;

				sum += cardNumber;
			}

			isDouble = !isDouble;
		}
	}

	sum = sum % 10;

	if (sum == 0)
		std::cout << "This is a valid card";
	else
		std::cout << "This card isn't valid";
}