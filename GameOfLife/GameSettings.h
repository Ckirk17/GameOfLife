#pragma once
#include <fstream>

struct GameSettings  {
	unsigned int LivingRed, LivingBlue, LivingGreen = 128;
	unsigned int LivingAlpha = 255;
	unsigned int DeadRed, DeadBlue, DeadGreen = 255;
	unsigned int DeadAlpha = 255;
	int gridSize = 15;
	int interval = 50;
	bool showNeighborCount = false;
	wxColor GetLivingColor() {
		return wxColor(LivingRed, LivingBlue, LivingGreen, LivingAlpha);
	}
	wxColor GetDeadColor() {
		return wxColor(DeadRed, DeadBlue, DeadGreen, DeadAlpha);
	}
	void SetLivingColor(wxColor& color) {
		LivingRed = color.Red();
		LivingBlue = color.Blue();
		LivingGreen = color.Green();
		LivingAlpha = color.Alpha();
	}
	void SetDeadColor(wxColor& color) {
		DeadRed = color.Red();
		DeadBlue = color.Blue();
		DeadGreen = color.Green();
		DeadAlpha = color.Alpha();
	}
	void LoadData() {
		std::ifstream file("settings.bin", std::ios::binary | std::ios::in);
		file.read((char*)this, sizeof(GameSettings));
		file.close();
	}
	void SaveData() {
		std::ofstream file("settings.bin", std::ios::out | std::ios::binary);
		file.write((char*)this, sizeof(GameSettings));
		file.close();
	}
};