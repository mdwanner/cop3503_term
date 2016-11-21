
static explore:: exploreNow(Character main)
{
	do
	{
		cout << "Where to?";
		string choice = getString();

		if()
	}
}

string explore::getString()
{
	std::string item;
	bool validInput = false;

	do
	{
		std::cin >> item;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			validInput = false;
		}
		else
		{
			validInput = true;
		}

	} while (!validInput);

	return item;
}