#include <windows.h>
#include <iostream>
#include <format>

int main(void)
{
	char name_file[200];
	std::cout << "Digite o nome do arquivo que voce deseja abrir : ";
	std::cin >> name_file;

	HANDLE file = CreateFile(name_file, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (file== INVALID_HANDLE_VALUE) {
		std::cout << "Esse arquivo nao existe" << std::endl;
		std::system("pause");
		return 0;
	}

	std::system("cls");
	SetConsoleTitle("Lendo arquivo");

	int size_file = GetFileSize(file, NULL), count = 0, dd = 0;
	char * testee = new char [size_file];

	ReadFile(file, testee, size_file, NULL, NULL);
	for (std::size_t i = 0; i <= size_file - 1; ++i) {
		count = count + 1;
		if (count >= 10) {
			count = 0;
			std::cout << std::endl;
		}

		dd = (int)testee[i];
		std::cout << " \033[1;36m| \033[1;32m" << std::format("{:#x}", abs(dd)) << " \033[1;36m| " << "\033[1;31m(" << testee[i] << ")\033[1;36m";
	}

	SetConsoleTitle("Arquivo lido");

	std::cout << std::endl;
	std::system("pause");
	return 0;
}
