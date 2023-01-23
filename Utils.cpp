#include "Utils.h"

// ���� � ��������: �� ������ ��������. ���� � ������ �� ������ ���������
bool enter(std::string* str) {

	const size_t size{ 1024 };		// ������ ������ ����������������� �����
	char s[size]{};					// ����� ����������������� �����

	std::cin.getline(s, size);
	size_t counter = count(s);		// ������� �������� ��������

	if (counter > 0 && counter <= 8) {
		for (size_t i = 0; i < counter; ++i) str->push_back(s[i]);
	}
	else {
		for (size_t i = 0; i < 1024; ++i) s[i] = 0;
		return false;
	}
	return true;
}

// ������� �������� �������� � ������� char
size_t count(const char s[])
{
	size_t counter{ 0 };
	for (size_t i = 0; i < 1024; ++i) { if (s[i] != '\0') ++counter; }
	return counter;
}
