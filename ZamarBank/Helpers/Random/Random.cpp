#include "Random.h"

string RandomHelper::GenerateRandomNumbers(int length) {
	string numbers = "0123456789";
	string text = "";

	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> dist10(0, 9);

	for (int i = 0; i < length; i++)
		text += numbers[dist10(rng)];

	return text;
}