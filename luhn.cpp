#include <iostream>

int multiply(int number)
{
	return (number * 2);
}

int main()
{
	std::cout << " Enter ur card number: ";
	std::string card{ "" };
	std::cin >> card;

	const int length{ static_cast<int>(card.length()) };

	constexpr int offset{ 48 };
	bool isDouble = false;
	int sum{ 0 };

	for (int i{ 0 }; i < length; ++i)
	{

		if (isDouble == true)
		{
			int cardNumber = card[i] - offset;
			int rem{};
			int sumTemp{};

			int temp{ multiply(cardNumber) };
			std::string sus{ static_cast<char>(temp) };

			while (temp > 0)
			{
				rem = temp % 10;
				sumTemp = sumTemp + rem;
				temp = temp / 10;
			}

			sum += sumTemp;
		}
		else
		{
			int cardNumber = card[i] - offset;

			sum += cardNumber;
		}

		isDouble = !isDouble;
	}

	sum = sum % 10;

	if (sum == 0)
		std::cout << "This card is valid";
	else
		std::cout << "This card isn't valid";
}