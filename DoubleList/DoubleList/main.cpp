//==========================
//�o�������X�g����
//==========================
//2023/10/02/14:30
//�쐬��:����P



#include <iostream>
#include <fstream>
#include <list>
#include <string>

//�v���C���[�\����
struct Player 
{
	int score;
	std::string name;
};

int main() 
{
	std::ifstream inputFile("Scores.txt"); //�t�@�C���ǂݍ���
	std::list<Player> players; //�v���C���[�̃��X�g����

	if (inputFile.is_open())  //�t�@�C���ǂݍ��ݐ���
	{
		std::cerr << "�t�@�C���̓ǂݍ��݂ɐ������܂����B" << std::endl;

		// �t�@�C������ǂݍ��񂾒l���i�[����ϐ�
		int score;
		std::string name;

		// �t�@�C������f�[�^��ǂݍ���Ń��X�g�ɒǉ�
		while (inputFile >> score >> name)
		{
			Player player;
			player.score = score;
			player.name = name;
			players.push_back(player); //���X�g�ɒǉ�
		}

		// �t�@�C�������
		inputFile.close();

		// �X�R�A�Ɩ��O��\��
		for (const auto& player : players) 
		{
			std::cout << " score : " << player.score << "   name : " << player.name << std::endl;
		}
	}
	else // �t�@�C���ǂݍ��ݎ��s
	{
		std::cerr << "�t�@�C�����J���܂���B" << std::endl;
	}

	getchar();
	return 0;
}