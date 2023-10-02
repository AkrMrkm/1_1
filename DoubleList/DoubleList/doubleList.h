#pragma once

//プレイヤー構造体
struct Player 
{
	int score; // スコア
	std::string name; // 名前
	Player* prev; // 前ノード
	Player* next; // 次ノード
};

class DoubleList
{
private:
	Player* head; // 先頭ノード
	Player* tail; // 末尾ノード

public:
	DoubleList() : head(nullptr), tail(nullptr) {}

	// 新しい要素をリストに追加するメソッド
	void Add(int score, const std::string& name)
	{
		Player* newPlayer = new Player{ score, name, nullptr, nullptr };

		// リストが空だったら先頭に追加
		if (head == nullptr) 
		{
			head = tail = newPlayer;
		}
		else
		{
			tail->next = newPlayer; // 新ノードを末尾ノードの次のノードに格納
			newPlayer->prev = tail; // 末尾ノードを新ノードの前ノードに格納
			tail = newPlayer; // 末尾ノードを新ノードにする
		}
	}

	// リストの内容を先頭から順に表示
	void Draw() 
	{
		Player* current = head;
		while (current != nullptr) 
		{
			std::cout << " score : " << current->score << "   name : " << current->name << std::endl;
			current = current->next;
		}
	}

	// デストラクタ
	~DoubleList() 
	{
		Player* current = head;
		while (current != nullptr) 
		{
			Player* next = current->next;
			delete current;
			current = next;
		}
	}
};