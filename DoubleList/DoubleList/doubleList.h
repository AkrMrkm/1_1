#pragma once

//�v���C���[�\����
struct Player 
{
	int score; // �X�R�A
	std::string name; // ���O
	Player* prev; // �O�m�[�h
	Player* next; // ���m�[�h
};

class DoubleList
{
private:
	Player* head; // �擪�m�[�h
	Player* tail; // �����m�[�h

public:
	DoubleList() : head(nullptr), tail(nullptr) {}

	// �V�����v�f�����X�g�ɒǉ����郁�\�b�h
	void Add(int score, const std::string& name)
	{
		Player* newPlayer = new Player{ score, name, nullptr, nullptr };

		// ���X�g���󂾂�����擪�ɒǉ�
		if (head == nullptr) 
		{
			head = tail = newPlayer;
		}
		else
		{
			tail->next = newPlayer; // �V�m�[�h�𖖔��m�[�h�̎��̃m�[�h�Ɋi�[
			newPlayer->prev = tail; // �����m�[�h��V�m�[�h�̑O�m�[�h�Ɋi�[
			tail = newPlayer; // �����m�[�h��V�m�[�h�ɂ���
		}
	}

	// ���X�g�̓��e��擪���珇�ɕ\��
	void Draw() 
	{
		Player* current = head;
		while (current != nullptr) 
		{
			std::cout << " score : " << current->score << "   name : " << current->name << std::endl;
			current = current->next;
		}
	}

	// �f�X�g���N�^
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