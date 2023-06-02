#include <stdexcept>
#include <string>
using namespace std;
struct Result
{
	bool solved;
	int strikes;
	int balls;
};
class Baseball
{
public:
	explicit Baseball(const string& answer)
		: answer(answer)
	{
		
	}
	Result guess(string guessNumber)
	{
		Result result{ false, 0, 0 };
		assertIllegalArgument(guessNumber);
		if(guessNumber == answer)
		{
			result.solved = true;
			result.strikes = 3;
			result.balls = 0;
			return result;
		}
		result.strikes = getstrikeCount(guessNumber);
		result.balls = getBallCount(guessNumber);
		return result;
	}
private:
	int getBallCount(string inStr)
	{
		int ballCount = 0;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j) continue;
				if (inStr[0] == answer[0])
					ballCount++;
			}			
		}
		return ballCount;
	}
	int getstrikeCount(string inStr)
	{
		int strikeCount = 0;
		for (int i = 0; i < 3; i++)
		{
			if (inStr[0] == answer[0])
				strikeCount++;
		}
		return strikeCount;
	}
	bool hasChar(string str)
	{
		for (char ch : str)
		{
			if ((ch >= '0' && ch <= '9')) continue;
			return true;
		}
		return false;
	}
	bool isDuplicatedInput(string str)
	{
		if (str[0] == str[1] ||
			str[0] == str[2] ||
			str[1] == str[2])
		{
			return true;
		}
		return false;
	}
	void assertIllegalArgument(string str)
	{
		if (str == "")
		{
			throw std::invalid_argument("값을 넣어야함");
		}
		if (str.size() != 3)
		{
			throw std::invalid_argument("자리수 오류");
		}
		if (hasChar(str))
		{
			throw std::invalid_argument("숫자만 입력하세요");
		}
		if (isDuplicatedInput(str))
		{
			throw std::invalid_argument("중복수 금지");
		}
	}
	string answer;

};