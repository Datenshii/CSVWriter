#include "Utils.h"
#include <iostream>
#include <fstream>

int AskData(Island &island) {

	if (island.name == "") {
		std::cout << "Nombre: ";
		std::cin >> island.name;
	}

	if (island.width <= 0) {
		std::cout << "Ancho: ";
		std::cin >> island.width;
	}

	if (island.height <= 0) {
		std::cout << "Alto: ";
		std::cin >> island.height;
	}

	return 0;
}

int CreateCSV(Island &island) {
	std::string pause;

	if (island.width > 256) island.width = 256;
	if (island.height > 256) island.height = 256;

	if (island.width > 18) {
		std::cout << "Cuidado. Anchos por encima de 18 pueden ser peligrosos!" << std::endl;
	}
	if (island.height > 18) {
		std::cout << "Cuidado. Altos por encima de 18 pueden ser peligrosos!" << std::endl;
	}

	std::cout << "Escribe \"y\" para continuar..." << std::endl;
	std::cin >> pause;

	while (island.width <= 0 || island.height <= 0) {
		std::cout << "Error. Introduceme datos correctos.";
		AskData(island);
	}

	std::ofstream csv(island.name + ".csv");

	csv << "NOMBRE;" << island.name << ";";
	csv << "ANCHO;" << island.width << ";";
	csv << "ALTO;" << island.height << ";;" << std::endl;

	for (int i = 0; i < island.height; i++) {
		for (int j = 0; j < island.width; j++) {
			csv << "0;";
		}
		csv << ";" << std::endl;
	}

	csv.close();
	
	return 0;
}