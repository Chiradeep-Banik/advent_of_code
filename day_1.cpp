#include <bits/stdc++.h>

using namespace std;

int getSum(vector<string> inputs)
{
	int sum = 0;
	vector<string> letters = {"one", "two", "three", "four", "five",
							  "six", "seven", "eight", "nine"};
	vector<char> digits = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	for (string input : inputs)
	{
		int n = input.size();
		cout << "input : " << input << endl;
		vector<int> positions(n, -1);
		int letVal = 1;
		for (string letter : letters)
		{
			int windowSize = letter.size();
			int l = 0, r = windowSize;
			while (r <= n)
			{
				string subS = input.substr(l, windowSize);
				if (subS == letter)
				{
					positions[l] = letVal;
				}
				l++;
				r++;
			}
			letVal++;
		}
		letVal = 1;
		for (char digit : digits)
		{
			for (int i = 0; i < input.size(); i++)
			{
				if (input[i] == digit)
				{
					positions[i] = letVal;
				}
			}
			letVal++;
		}
		for (int i = 0; i < positions.size(); i++)
		{
			cout << positions[i] << " ";
		}
		cout << endl;
		int left = 0, right = 0;
		for (int i = 0; i < n; i++)
		{
			if (positions[i] != -1)
			{
				left = positions[i];
				break;
			}
		}
		for (int i = n - 1; i > -1; i--)
		{
			if (positions[i] != -1)
			{
				right = positions[i];
				break;
			}
		}
		cout << "left : " << left << endl;
		cout << "right : " << right << endl;
		sum += ((left * 10) + right);
		cout << "sum : " << sum << endl;
	}
	return sum;
}

int main()
{
	string line;
	ifstream myfile("1_input.txt");
	vector<string> inputs;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			inputs.push_back(line);
		}
		myfile.close();
	}

	else
		cout << "Unable to open file";

	cout << "Sum : " << getSum(inputs) << endl;
	return 0;
}
