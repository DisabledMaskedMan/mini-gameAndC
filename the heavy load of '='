#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cstring>
#include <cstdio>

class CMyString
{
public:
	CMyString(const char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);
	CMyString& operator=(const CMyString& str);
	friend std::ostream& operator<<(std::ostream& os, CMyString& str);
	void Print();
private:
	char* m_pData;
};

CMyString::CMyString(const CMyString& str)
{
	if (str.m_pData == nullptr)
		m_pData = nullptr;
	else
	{
		m_pData = new char[strlen(str.m_pData) + 1];
		if (m_pData == nullptr)
			std::cout << "out of memory" << std::endl;
		else
			strcpy(m_pData, str.m_pData);
	}
}

CMyString::CMyString(const char* pData)
{
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		m_pData = new char[strlen(pData) + 1];
		if (m_pData == nullptr)
			std::cout << "out of memory" << std::endl;
		else
			strcpy(m_pData, pData);
	}
}

CMyString::~CMyString(void)
{
	delete[] m_pData;
	std::cout << "delete finally" << std::endl;
}

CMyString& CMyString::operator=(const CMyString& str)
{
	if (this != &str)
	{
		if (m_pData == nullptr || str.m_pData == nullptr)
		{
			std::cout << "error" << std::endl;
			return *this;
		}
		CMyString StrTmp(str);
		char* Tmp = StrTmp.m_pData;
		StrTmp.m_pData = m_pData;
		m_pData = Tmp;

		strcpy(m_pData, str.m_pData);
	}
	
	return *this;
}

std::ostream& operator<<(std::ostream& os, CMyString& str)
{
	return os << str.m_pData;
}

void CMyString::Print()
{
	printf("%s", m_pData);
}

int main()
{
	CMyString s1 = "hello";
	std::cout << "s1 = " << s1 << std::endl;
	CMyString s2 = "world";
	std::cout << "s2 = " << s2 << std::endl;
	CMyString s3 = s1;
	std::cout << "s3 = " << s3 << std::endl;
	s1 = s1;
	std::cout << "s1 = " << s1 << std::endl;
	s1 = s3 = s2;
	std::cout << "s1 = " << s1 << "  "
		<< "s2 = " << s2  << "  "
		<< "s3 = " << s3 << std::endl;
	CMyString s4;
}
