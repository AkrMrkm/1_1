//==========================
//双方向リスト実装
//==========================
//2023/10/02/14:30
//作成者:村上輝



#include <iostream>
#include <fstream>
#include <list>
#include <string>

//プレイヤー構造体
struct Player 
{
	int score;
	std::string name;
};

int main() 
{
	std::ifstream inputFile("Scores.txt"); //ファイル読み込み
	std::list<Player> players; //プレイヤーのリスト生成

	if (inputFile.is_open())  //ファイル読み込み成功
	{
		std::cerr << "ファイルの読み込みに成功しました。" << std::endl;

		// ファイルから読み込んだ値を格納する変数
		int score;
		std::string name;

		// ファイルからデータを読み込んでリストに追加
		while (inputFile >> score >> name)
		{
			Player player;
			player.score = score;
			player.name = name;
			players.push_back(player); //リストに追加
		}

		// ファイルを閉じる
		inputFile.close();

		// スコアと名前を表示
		for (const auto& player : players) 
		{
			std::cout << " score : " << player.score << "   name : " << player.name << std::endl;
		}
	}
	else // ファイル読み込み失敗
	{
		std::cerr << "ファイルを開けません。" << std::endl;
	}

	getchar();
	return 0;
}