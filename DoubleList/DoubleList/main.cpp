//==========================
//双方向リスト実装
//==========================
//2023/10/02/16:00
//作成者:村上輝

#include <iostream>
#include <fstream>
#include <string>
#include "doubleList.h"

int main() 
{
	std::ifstream inputFile("Scores.txt"); //ファイル読み込み
	DoubleList playersList;

	if (inputFile.is_open())  //ファイル読み込み成功
	{
		std::cerr << "ファイルの読み込みに成功しました。" << std::endl;

		// ファイルから読み込んだ値を格納する変数
		int score;
		std::string name;

		// ファイルからデータを読み込んでリストに追加
		while (inputFile >> score >> name)
		{
			playersList.Add(score, name);
		}

		// ファイルを閉じる
		inputFile.close();
		
		//リスト表示
		playersList.Draw();

	}
	else // ファイル読み込み失敗
	{
		std::cerr << "ファイルを開けません。" << std::endl;
	}

	getchar();
	return 0;
}