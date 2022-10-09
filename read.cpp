#include <windows.h>
#include <iostream>

int main(void)
{
	char name_file[200];
	std::cout << "Digite o nome do arquivo que voce deseja abrir : ";
	std::cin >> name_file;

	HANDLE file = CreateFile(name_file, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file== INVALID_HANDLE_VALUE) {
		return 0;
	}

	std::system("cls");
	SetConsoleTitle("Lendo arquivo");

	int size_file = GetFileSize(file, NULL), count = 0;
	char * testee = new char [size_file];

	ReadFile(file, testee, size_file, NULL, NULL);
	for (std::size_t i = 0; i <= size_file - 1; ++i) {
		count = count + 1;
		if (i >= 1) {
			std::cout << "|";
		}

		if (count >= 20) {
			for (std::size_t j = 0; j <= 20; ++j) {
				if (j == 0) {
					std::cout << " |";
				}

				std::cout << testee[i - j];
			}
			std::cout << "|" << std::endl;
			count = 0;
		}

		std::cout << (int)testee[i];
	}

	SetConsoleTitle("Arquivo lido");

	std::cout << std::endl;
	std::system("pause");
	return 0;
}
